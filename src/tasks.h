#pragma once

//DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write
const float REST = 0;
const float CAPTURE = 35;
const float WALLSTAKE_PREP = 100;
const float WALLSTAKE = 140;
float positions[3] = {REST, CAPTURE, WALLSTAKE};
int lbTarget = 0; //NUMBER FROM 0-SIZE OF POSITIONS ARRAY, DO NOT PUT THE ACTUAL ANGLE


bool sorter_active = true;
bool auton_active = false;
char current_sort = 'b';
float conveyor_speed = 127;
// float conveyor_start_time = 0;
// bool conveyor_powered = false;

bool in_range(double value, double bottom, double top) {
    return (value >= bottom) && (value <= top);
}

/**
 * 0 REST, 1 CAPTURE, 2 WALLSTAKE
 */
void set_LBPosition(int target){
    lbTarget = target;
}

int find_closest_LBPosition(float lbArmAngle, bool findPositionBehind){
    if(lbArmAngle > 300) lbArmAngle = 0; //if the angle is slightly past hard stop, making it do a full rotation over to 359.99 degrees, this accounts for that case
    if(lbArmAngle > positions[sizeof(positions)/sizeof(positions[0])-1]) return sizeof(positions)/sizeof(positions[0])-1;
    for(int i = 0; i < sizeof(positions)/sizeof(positions[0])-1; i++){
        float lowerBound = positions[i];
        float upperBound = positions[i+1];
        if(lowerBound <= lbArmAngle && lbArmAngle < upperBound){
            if(findPositionBehind) return i;
            else return i+1;
        }
    }
    return -1;
}


void driver_inputs() {
    if(!auton_active){ //don't run driver inputs if auton is active
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
            conveyor.move(conveyor_speed);
            // if(!conveyor_powered) {
            //     conveyor_powered = true;
            //     conveyor_start_time = CLOCK_REALTIME;
            // }
            // else if(CLOCK_REALTIME - conveyor_start_time > 5 && conveyor.get_actual_velocity() < 150){
            //     conveyor.move(-127);
            // }
        }
        else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            // conveyor_powered = false;
            conveyor.move(-127);
        } else {
            // conveyor_powered = false;
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
    
    bool manualLBMode = false;

    // const float ALLIANCE = 190;


    char colour_detected = 'n'; // 'n' means empty
    bool wrong_color_detected = false;
    float wrong_color_detected_time = 0;
    int controller_print = 0;
    
    while (true) {

        // 200-ish is blue
        // 10-ish is red
        double hue = colour_sensor.get_hue();

        // Message colour_message = { "colour", {{"hue", hue}, {"colours", colour_detected}, {"sees", (distance_sensor.get() < 15)}} };
        // std::cout << static_cast<json>(colour_message) << std::flush;


        if (in_range(hue, 205, 219)) {
            colour_detected = 'b';
        } else if (in_range(hue, 5, 13.5)) {
            colour_detected = 'r';
        } else {
            colour_detected = 'n';
        }

        

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) { //toggle whether color sort is active or not
            sorter_active = !sorter_active;
        }

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) { //toggle color sort setting
            if (current_sort == 'r') {
                current_sort = 'b';
            } else {
                current_sort = 'r';
            }
        }
        float currAngle = ((float)ladybrownSensor.get_angle())/100;
        if(currAngle > 300) currAngle = currAngle - 360;
        //LADYBROWN CODE BELOW
        if(master.get_digital(E_CONTROLLER_DIGITAL_UP) && currAngle <= 140){
            ladybrownMotor.move(127);
            manualLBMode = true;
        }
        else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
            ladybrownMotor.move(-127);
            manualLBMode = true;
        }
        else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){ //moves the arm up in positions in the wallstake chain of action
            if(manualLBMode){
                lbTarget = find_closest_LBPosition(currAngle, false);
            }
            else if(lbTarget < (sizeof(positions) / sizeof(positions[0]))-1){
                lbTarget++;
            }
            manualLBMode = false;
        }
        else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){ //arm recovery
            if(manualLBMode){
                lbTarget = find_closest_LBPosition(currAngle, true);
            }
            else if(lbTarget > 0){
                lbTarget--;
            }
            manualLBMode = false;
        }
        else if(manualLBMode && (!auton_active)){
            ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            ladybrownMotor.brake();
        }
        if(!manualLBMode){ //no manual overrides have been given, move on to macros
            ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_COAST);
            float powerGiven = ladybrownPID.update(positions[lbTarget] - currAngle);
            if(!manualLBMode) ladybrownMotor.move(powerGiven); //update PID and motor voltage
            // lcd::print(0, "targetAngle: %f", positions[lbTarget]);
            // lcd::print(1, "lbAngleAdjusted: %f", lbAngle);
            // lcd::print(2, "power given: %f", powerGiven);
        }
        
        if (!wrong_color_detected && (sorter_active && current_sort == colour_detected) && distance_sensor.get() < 45) {
            wrong_color_detected = true;
            driver_inputs();
        }
        else if(wrong_color_detected && final_distance_sensor.get() < 25){
            wrong_color_detected = false;
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

        if (controller_print == 0) {
            master.print(0, 0, "Sorter State: %s", sorter_active ? "Active" : "Inactive");
            controller_print = 10;
        } else if (controller_print == 5) {
            master.print(1, 0, "Current Sort: %s", current_sort == 'r' ? "Red" : "Blue");
        }

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