#pragma once

//DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write


bool sorter_active = true;
bool auton_active = false;
char current_sort = 'b';
float conveyor_speed = 127;

bool in_range(double value, double bottom, double top) {
    return (value >= bottom) && (value <= top);
}

int find_closest_LBPosition(float lbArmAngle, float positions[4], bool isBehind){
    float closestPositionDiff = 9999;
    float closestPositionIndex = 0;
    if(lbArmAngle > 300) lbArmAngle = lbArmAngle - 360;
    for(int i = 0; i < sizeof(positions)/sizeof(positions[0]); i++){
        if(abs(lbArmAngle - positions[i]) < closestPositionDiff && (isBehind && abs(lbArmAngle) >= positions[i]) || (!isBehind && abs(lbArmAngle) <= positions[i])) {
            closestPositionDiff = abs(lbArmAngle - positions[i]);
            closestPositionIndex = i;
        }
    }
    return closestPositionIndex;
}


void driver_inputs() {
    if(!auton_active){ //don't run driver inputs if auton is active
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1) || master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
            conveyor.move(conveyor_speed);
        } 
        else if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
            conveyor.move(-127);
        } else {
            conveyor.move(0);
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_R1) || master.get_digital(E_CONTROLLER_DIGITAL_LEFT)) {
            intake.move(-127);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            intake.move(127);
        } else {
            intake.move(0);
        }
    }
}


void ladybrown_and_color_task() {
    
    bool ringHeld = false;
    bool manualLBMode = false;
    const float REST = 0;
    const float CAPTURE = 35;
    const float WALLSTAKE_PREP = 100;
    const float WALLSTAKE = 140;
    // const float ALLIANCE = 190;

    int lbTarget = 0;
    float positions[4] = {REST, CAPTURE, WALLSTAKE_PREP, WALLSTAKE};

    char colour_detected = 'n'; // 'n' means empty
    int controller_print = 0;
    
    while (true) {

        // 200-ish is blue
        // 10-ish is red
        double hue = colour_sensor.get_hue();

        // Message colour_message = { "colour", {{"hue", hue}, {"colours", colour_detected}, {"sees", (distance_sensor.get() < 15)}} };
        // std::cout << static_cast<json>(colour_message) << std::flush;


        if (in_range(hue, 215, 219)) {
            colour_detected = 'b';
        } else if (in_range(hue, 5, 13.5)) {
            colour_detected = 'r';
        } else {
            colour_detected = 'n';
        }

        

        // if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) { //toggle whether color sort is active or not
        //     sorter_active = !sorter_active;
        // }

        // if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) { //toggle color sort setting
        //     if (current_sort == 'r') {
        //         current_sort = 'b';
        //     } else {
        //         current_sort = 'r';
        //     }
        // }

        //LADYBROWN CODE BELOW
        if(master.get_digital(E_CONTROLLER_DIGITAL_X)){
            ladybrownMotor.move(127);
            manualLBMode = true;
        }
        else if(master.get_digital(E_CONTROLLER_DIGITAL_B)){
            ladybrownMotor.move(-127);
            manualLBMode = true;
        }
        else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){ //moves the arm up in positions in the wallstake chain of action
            if(manualLBMode){
                lbTarget = find_closest_LBPosition((float)ladybrownSensor.get_angle()/100, positions, false);
            }
            else if(lbTarget < sizeof(positions) / sizeof(positions[0])-1){
                lbTarget++;
            }
            manualLBMode = false;
        }
        else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){ //arm recovery
            if(manualLBMode){
                lbTarget = find_closest_LBPosition((float)ladybrownSensor.get_angle()/100, positions, true);
            }
            else if(lbTarget > 0){
                lbTarget--;
            }
            manualLBMode = false;
        }
        else if(manualLBMode && !auton_active){
            ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            ladybrownMotor.brake();
        }
        if(!manualLBMode && !auton_active){ //no manual overrides have been given, move on to macros
            ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_COAST);
            float lbAngle = ((float)ladybrownSensor.get_angle())/100;
            if(lbAngle > 300) lbAngle = lbAngle - 360;
            float powerGiven = ladybrownPID.update(positions[lbTarget] - lbAngle);
            if(!manualLBMode) ladybrownMotor.move(powerGiven); //update PID and motor voltage
            // lcd::print(0, "targetAngle: %f", positions[lbTarget]);
            // lcd::print(1, "lbAngleAdjusted: %f", lbAngle);
            // lcd::print(2, "power given: %f", powerGiven);
        }
        
        if ((sorter_active && current_sort == colour_detected) && distance_sensor.get() < 15) {
            int voltageBeforeStop = conveyor.get_voltage();
            delay(45);
            conveyor.move(-127);
            delay(250);
            conveyor.move_voltage(voltageBeforeStop); //reset the voltage to what it was before reversing the conveyor
            colour_detected = 'n';
        } 
        else{
            driver_inputs();
        }

        // if (controller_print == 0) {
        //     master.print(0, 0, "Sorter State: %s", sorter_active ? "Active" : "Inactive");
        //     controller_print = 10;
        // } else if (controller_print == 5) {
        //     master.print(1, 0, "Current Sort: %s", current_sort == 'r' ? "Red" : "Blue");
        // }

        if (controller_print > 0) {
            controller_print--;
        }

        delay(20);
    }
}


// void gps_sensor_task(){
//     pros::gps_status_s_t gpsData;
//     while(true){
//         gpsData = gps_sensor.get_position_and_orientation();
//         lcd::print(2, "GPSx: %f", gpsData.x*39.3701);
// 		lcd::print(3, "GPSy: %f", gpsData.y*39.3701);
//         lcd::print(4, "GPSorientation: %f", gpsData.yaw);
//         lcd::print(5, "orientation: %f", chassis.getPose().theta);
//         delay(5);
//     }
// }


// void conveyor_task() {

//     bool conveyor_held;
//     bool conveyor_overvolt;

//     bool overvolt_state = false;

//     int conveyor_overvolt_count = 0;

//     while (true) {
//         conveyor_held = master.get_digital(E_CONTROLLER_DIGITAL_R2);

//         conveyor_overvolt = conveyor.get_current_draw() > 2500;

//         if (conveyor_overvolt) {
//             conveyor_overvolt_count++;
//         } else {
//             conveyor_overvolt_count = 0;
//         }

//         // If the conveyor is overvolted and its the first time, move it backwards for a bit
//         if ((conveyor_overvolt_count > 100) && !overvolt_state) {
//             overvolt_state = true;
//             conveyor.move(-100);
//             delay(250);
//             conveyor.move(0);
//         } else if (!conveyor_overvolt && !conveyor_held) { // If the conveyor is no longer overvolted and not held, reset state
//             overvolt_state = false;
//         }

//         if (!overvolt_state) {
//             if (conveyor_held) {
//                 conveyor.move(100);
//             } else {
//                 conveyor.move(0);
//             }
//         }

//         delay(10);
//     }
// }