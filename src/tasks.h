#pragma once

//DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write
const float REST = 0;
const float CAPTURE = 42;
const float WALLSTAKE_PREP = 100;
const float WALLSTAKE = 141;
const float MANUAL = 350;
float positions[3] = { REST, CAPTURE, MANUAL };
int lbTarget = 0; //NUMBER FROM 0-SIZE OF POSITIONS ARRAY, DO NOT PUT THE ACTUAL ANGLE

float conveyor_speed = 127;

void reactiveClawClamp() {
    while (true) {
        if (reactiveClawClampOn) {
            if (clawLimitSwitch.get_new_press() == 1) {
                claw.extend();
                if (auton_active) {
                    chassis.cancelMotion();
                }
            }
        }
        delay(30);
    }
}

/// @brief Stops the conveyor when a ring is detected by the distance sensor
void monitor_and_stop_conveyor() {
    while (true) {
        if (auton_active) {
            if (stopNextRing) {
                if (distance_sensor.get() < CONVEYOR_DISTANCE_OFFSET) {
                    conveyor.move(0);
                    stopNextRing = false;
                }
            }
        }
        delay(30);
    }
}
void unjamLBTask() {

    int jamCount = 0;

    while (true) {
        if (unjamLB) {
            if (lbTarget == 0 && in_range(((float)ladybrownMotor.get_position()), 15, 33)) {
                if (jamCount >= 20) { // lb is not fully down despite being told to be down
                    // set_LBPosition(1);
                    int prevMotorState = conveyor.get_voltage();
                    conveyor.move(-127);
                    delay(350);
                    if (unjamLB) {
                        if (prevMotorState > 2000) {
                            conveyor.move(127);
                        } else if (prevMotorState < -2000) {
                            conveyor.move(-127);
                        } else conveyor.move(0);
                    }
                    // set_LBPosition(0);
                    jamCount = 0;
                }
                jamCount++;
            }
        }
        delay(30);
    }
}

void driver_inputs() {
    if (!auton_active) { //don't run driver inputs if auton is active
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
            conveyor.move(conveyor_speed);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_R2) && !clawDoinker.is_extended()) {
            conveyor.move(-127);
        } else {
            conveyor.move(0);
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_R1) && !clawDoinker.is_extended()) {
            intake.move(127);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            intake.move(-127);
        } else {
            intake.move(0);
        }
    }
}


void ladybrown_and_color_task() {

    bool lbAboveCapture = false;
    bool newLBPress = false;
    bool manualLBMode = false;
    ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    int lbTarget = 0;


    char colour_detected = 'n'; // 'n' means empty
    bool wrong_color_detected = false;
    float wrong_color_detected_time = 0;
    int controller_print = 0;


    while (true) {
        // lcd::print(0, "x: %f", chassis.getPose().x);
        // lcd::print(1, "y: %f", chassis.getPose().y);
        // lcd::print(2, "theta: %f", imu.get_heading());

        // below code is for manual override
        // if(auton_active && master.get_digital(E_CONTROLLER_DIGITAL_LEFT)){ //REMOVE BEFORE PROVS
        //     chassis.cancelAllMotions();
        // }

        // 200-ish is blue
        // 10-ish is red
        double hue = colour_sensor.get_hue();

        // Message colour_message = { "colour", {{"hue", hue}, {"colours", colour_detected}, {"sees", (distance_sensor.get() < 15)}} };
        // std::cout << static_cast<json>(colour_message) << std::flush;


        if (in_range(hue, 190, 215)) {
            colour_detected = 'b';
        } else if (in_range(hue, 5, 15)) {
            colour_detected = 'r';
        } else {
            colour_detected = 'n';
        }



        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) { //toggle whether color sort is active or not
            sorter_active = !sorter_active;
        }

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) { //toggle color sort setting
            if (team_color == 'r') {
                team_color = 'b';
            } else {
                team_color = 'r';
            }
        }

        float currTheta = ladybrownMotor.get_position() / 3;

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
            if (lbTarget < (sizeof(positions) / sizeof(positions[0])) - 1) {
                lbTarget++;
            }
        }
        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT) && positions[lbTarget] != MANUAL) {
            lbTarget = 0;
        }



        if (!auton_active) {
            if (positions[lbTarget] == CAPTURE) {
                float powerGiven = ladybrownController.update(currTheta, (positions[lbTarget] - currTheta));
                ladybrownMotor.move(powerGiven); //update PID and motor voltage
            } else { //manual mode is active
                if (master.get_digital(E_CONTROLLER_DIGITAL_Y) && master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(0);
                } else if (master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
                    ladybrownMotor.move(127);
                } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(-127);
                } else ladybrownMotor.move(0);
                if (currTheta < CAPTURE) lbTarget = 0;
            }
        }







        // else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){ //moves the arm up in positions in the wallstake chain of action
        //     if(manualLBMode){
        //         lbTarget = find_closest_LBPosition(currAngle, false);
        //     }
        //     else if(lbTarget < (sizeof(positions) / sizeof(positions[0]))-1){
        //         lbTarget++;
        //     }
        //     manualLBMode = false;
        // }
        // else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){ //arm recovery
        //     if(manualLBMode){
        //         lbTarget = find_closest_LBPosition(currAngle, true);
        //     }
        //     else if(lbTarget > 0){
        //         lbTarget--;
        //     }
        //     manualLBMode = false;
        // }
        // else if(manualLBMode && (!auton_active)){
        //     ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        //     ladybrownMotor.brake();
        // }

        // if(!manualLBMode){ //no manual overrides have been given, move on to macros
        //     // float powerGiven = ladybrownPID.update(positions[lbTarget] - currAngle);
        //     float powerGiven = ladybrownController.update(currAngle, (positions[lbTarget] - currAngle));
        //     if(positions[lbTarget] == WALLSTAKE) powerGiven = 127;
        //     if(currAngle <= 142 || positions[lbTarget] < WALLSTAKE) {
        //         ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_COAST);
        //         ladybrownMotor.move(powerGiven); //update PID and motor voltage
        //     }
        //     else {
        //         ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        //         ladybrownMotor.brake();
        //     }
        //     // lcd::print(0, "targetAngle: %f", positions[lbTarget]);
        //     // lcd::print(1, "lbAngleAdjusted: %f", lbAngle);
        //     // lcd::print(2, "power given: %f", powerGiven);
        // }

        if (sorter_active && team_color != 'n' && team_color != colour_detected && colour_detected != 'n' && distance_sensor.get() < CONVEYOR_DISTANCE_OFFSET) {
            wrong_color_detected = false;
            int voltageBeforeStop = conveyor.get_voltage();
            delay(25);
            conveyor.move(-127);
            delay(250);
            conveyor.move_voltage(voltageBeforeStop); //reset the voltage to what it was before reversing the conveyor
            colour_detected = 'n';
        } else {
            driver_inputs();
        }

        if (controller_print == 0) {
            master.print(0, 0, "Sorter State: %s", sorter_active ? "Active" : "Inactive");
            controller_print = 10;
        } else if (controller_print == 5) {
            master.print(1, 0, "Team Color: %s", team_color == 'r' ? "Red" : "Blue");
        }

        if (controller_print > 0) {
            controller_print--;
        }

        delay(15);
    }
}


void autoClampTask() {
    while (true) {
        if (clampRequested) {
            if (mogo_distance.get() < 11 && !mogoclamp.is_extended()) { // clamp the mogo when it is close enough
                mogoclamp.extend();
                clampRequested = false;
            }
        }
        delay(30);
    }
}


void lbAngleResetTask() {
    int count = 0;
    while (true) {
        if (positions[lbTarget] == REST) {
            if (ladybrownMotor.get_current_draw() > 900 && ladybrownMotor.get_actual_velocity() < 2) {
                count++;
            } else {
                count = 0;
            }
            if (count == 10) {
                ladybrownMotor.move(0);
                ladybrownMotor.tare_position();
                count = 0;
            }
        }
        std::cout << ladybrownMotor.get_position() / 3 << std::endl;
        delay(30);
    }
}

// void gps_sensor_task(){

//     double xOffset = 6.0;

//     while(true) {
//         float gpsX = gps_sensor.get_position_x();
//         float gpsY = gps_sensor.get_position_y();
//         float gpsYaw = gps_sensor.get_yaw();
//         gpsX *= (39.3701 * -1.0); // TEMPORARY, MAKE SURE TO UNREVERSE THIS LATER
//         gpsY *= (39.3701 * -1.0); // TEMPORARY, MAKE SURE TO UNREVERSE THIS LATER
//         lemlib::Pose pose = chassis.getPose();
//         lcd::print(6, "gpsY preffset %f", gpsY);



//         gpsY -= sin(pose.theta*0.01745329) * 6.0; // PROS OFFSET IS NOT WORKING
//         gpsX -= cos(pose.theta*0.01745329) * 6.0; // PROS OFFSET IS NOT WORKING

//         if(gpsYaw < 0) gpsYaw = 360 - gpsYaw;
//         // gpsYaw += 90; // correct shift
//         gpsYaw -= 90; // TEMPORARY, MAKE SURE TO REMOVE THIS LATER
//         if(gpsYaw > 360) {
//             gpsYaw -= 360;
//         }
//         lcd::print(3, "GPSx: %f", round2dp(gpsX));
// 		lcd::print(4, "GPSy: %f", round2dp(gpsY));
//         lcd::print(5, "y offset calculation %f", sin(pose.theta*0.01745329) * 6.0);
//         // lcd::print(6, "orientation: %f", pose.theta);
//         lcd::print(7, "error: %f", gps_sensor.get_error());

//         // if(gps_sensor.get_error() <= 0.01016 && abs(gpsX - chassis.getPose().x) <= 0.5 && abs(gpsY - chassis.getPose().y) <= 0.5){
//         //     chassis.setPose(gpsX, gpsY, pose.theta);
//         // }

//         // Odometry odom = {std::ceil((double)pose.x * 100.0) / 100.0, std::ceil((double)pose.y * 100.0) / 100.0, std::ceil((double)pose.theta * 100.0) / 100.0};
//         // Odometry odom = {round2dp(pose.x), round2dp(pose.y), round2dp(pose.theta), round2dp(gpsX), round2dp(gpsY), round2dp(gpsYaw), gps_sensor.get_error()};
//         // Message odom_message = {"odometry", odom};
//         // std::cout << static_cast<json>(odom_message) << std::flush;

//         delay(50);

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