#pragma once

//DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write
const float REST = 0;
const float CAPTURE = 45;
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
        if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
            conveyor.move(conveyor_speed);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_L2) && !clawDoinker.is_extended()) {
            conveyor.move(-127);
        } else {
            conveyor.move(0);
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_L1) && !clawDoinker.is_extended()) {
            intake.move(127);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
            intake.move(-127);
        } else {
            intake.move(0);
        }
    }
}


void ladybrownTask() {

    bool lbAboveCapture = false;
    bool newLBPress = false;
    bool manualLBMode = false;
    ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    int lbTarget = 0;

    while (true) {

        float currTheta = ladybrownMotor.get_position() / 3;

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
            if (lbTarget < (sizeof(positions) / sizeof(positions[0])) - 1) {
                lbTarget++;
            }
        }
        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT) && positions[lbTarget] != MANUAL) {
            lbTarget = 0;
        }



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


        driver_inputs();


        delay(15);
    }
}
