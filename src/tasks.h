#pragma once
//FYI DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write

/**
 * prints out information to controller screen
 */
void controllerPrinting() {
    int controller_print = 0;
    while (true) {
        if (controller_print == 0) {
            std::string printOut = "ERROR";
            if (!sorter_active || team_color == 'n') printOut = "None";
            else if (team_color == 'r') printOut = "Red";
            else if (team_color == 'b') printOut = "Blue";
            master.print(0, 0, "Team Color: %s", printOut);
            controller_print = 2;
        } else if (controller_print == 1) {
            std::string printOut = "ERROR";
            if (manualLBMode) printOut = "Manual";
            else if (lbDescoreMode) printOut = "Descore";
            else printOut = "Stages";
            master.print(1, 0, "LB Mode: %s", printOut);
        }
        if (controller_print > 0) {
            controller_print--;
        }
        delay(50);
    }
}

/**
 * activates doinker claw clamp when the doinker's limit switch is activated
 */
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

/// @brief Stops the conveyor when a ring OF THE TEAM's COLOUR is detected by the distance sensor
void monitorAndStopConveyor() {

    char colour_detected = 'n'; 

    while (true) {
        if (auton_active) {
            if (stopNextRing) {
                double hue = colour_sensor.get_hue();

                if (in_range(hue, 190, 215)) {
                    colour_detected = 'b';
                } else if (in_range(hue, 5, 18)) {
                    colour_detected = 'r';
                } else {
                    colour_detected = 'n';
                }

                if (distance_sensor.get() < CONVEYOR_DISTANCE_OFFSET && (colour_detected == team_color)) {
                    conveyor.move(0);
                    stopNextRing = false;
                }
            }
        }
        delay(20);
    }
}

/**
 * if the ladybrown is trying to go down with a ring in it this will back the conveyor up so the ladybrown can go down
 */
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
            conveyor.move(127);
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


void colorSortTask() {

    char colour_detected = 'n'; // 'n' means empty
    bool wrong_color_detected = false;


    while (true) {

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
        } else if (in_range(hue, 5, 18)) {
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



        delay(15);
    }
}

void ladybrownTask() {
    ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    bool newSwitchToAutoLB = false;

    while (true) {

        if (!auton_active) {

            float currTheta = ladybrownMotor.get_position() / 3;

            if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) { //toggle manual mode
                manualLBMode = !manualLBMode;
                lbDescoreMode = false;
                newSwitchToAutoLB = true;
            } else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
                lbDescoreMode = !lbDescoreMode;
                newSwitchToAutoLB = true;
                manualLBMode = false;
            }
            if (manualLBMode) { //manual control
                if (master.get_digital(E_CONTROLLER_DIGITAL_Y) && master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(0);
                }
                if (master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
                    ladybrownMotor.move(127);
                } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(-127);
                } else {
                    ladybrownMotor.move(0);
                }
            } else if (lbDescoreMode) {
                if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
                    if (newSwitchToAutoLB) {
                        lbDescoreTarget = findClosestDescorePosition(currTheta, false);
                    } else if (lbDescoreTarget < (sizeof(descorePositions) / sizeof(descorePositions[0])) - 1) {
                        lbDescoreTarget++;
                    }
                }
                if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
                    if (newSwitchToAutoLB) {
                        lbDescoreTarget = findClosestDescorePosition(currTheta, true);
                    } else if (lbDescoreTarget > 0) {
                        lbDescoreTarget--;
                    }
                }
                float powerGiven = ladybrownController.update(currTheta, (descorePositions[lbDescoreTarget] - currTheta));
                if (newSwitchToAutoLB) powerGiven = 0; //ensures that the arm doesn't begin moving immediately after switching modes

                if (descorePositions[lbDescoreTarget] != DESCORED_POSITION) { //PID required
                    ladybrownMotor.move(powerGiven); //update PID and motor voltage
                } else { //bang bang controller
                    if (abs(descorePositions[lbDescoreTarget] - currTheta) < 8) ladybrownMotor.move(powerGiven);
                    else {
                        if (powerGiven > 0) ladybrownMotor.move(127);
                        else if (powerGiven < 0) ladybrownMotor.move(-127);
                        else ladybrownMotor.brake();
                    }
                }
                newSwitchToAutoLB = false;
            } else { //stages activated
                if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
                    if (newSwitchToAutoLB) {
                        lbTarget = find_closest_LBPosition(currTheta, false);
                    } else if (lbTarget < (sizeof(positions) / sizeof(positions[0])) - 1) {
                        lbTarget++;
                    }
                }
                if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
                    if (newSwitchToAutoLB) {
                        lbTarget = find_closest_LBPosition(currTheta, true);
                    } else if (positions[lbTarget] == WALLSTAKE) {
                        lbTarget = 1;
                    } else if (lbTarget > 0) {
                        lbTarget--;
                    }
                }
                float powerGiven = ladybrownController.update(currTheta, (positions[lbTarget] - currTheta));
                if (newSwitchToAutoLB) powerGiven = 0; //ensures that the arm doesn't begin moving immediately after switching modes

                if (positions[lbTarget] == CAPTURE) { //PID required
                    ladybrownMotor.move(powerGiven); //update PID and motor voltage
                } else { //bang bang controller
                    if (abs(positions[lbTarget] - currTheta) < 8) ladybrownMotor.move(powerGiven);
                    else {
                        if (powerGiven > 0) ladybrownMotor.move(127);
                        else if (powerGiven < 0) ladybrownMotor.move(-127);
                        else ladybrownMotor.move(LB_STABILIZER);
                    }
                }
                newSwitchToAutoLB = false;
            }

        }


        delay(15);
    }
}


void autoClampTask() {
    while (true) {
        if (mogoClampRequested) {
            if (mogo_distance.get() < 11 && !mogoclamp.is_extended()) { // clamp the mogo when it is close enough
                mogoclamp.extend();
                mogoClampRequested = false;
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
        // std::cout << ladybrownMotor.get_position() / 3 << std::endl;
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