#pragma once

bool in_range(double value, double bottom, double top) {
    return (value >= bottom) && (value <= top);
}

bool sorter_active = true;
bool auton_active = false;
char current_sort = 'b';


void driver_inputs() {
    if(!auton_active){ //don't run driver inputs if auton is active
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
            conveyor.move(127);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
            conveyor.move(-127);
        } else {
            conveyor.move(0);
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
            intake.move(-127);
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            intake.move(127);
        } else {
            intake.move(0);
        }
    }
}


void colour_sorter_task() {

    char colour_detected = 'n'; // 'n' means empty
    int controller_print = 0;
    
    while (true) {

        // 200-ish is blue
        // 10-ish is red
        double hue = colour_sensor.get_hue();

        Message colour_message = { "colour", {{"hue", hue}, {"colours", colour_detected}, {"sees", (distance_sensor.get() < 15)}} };
        std::cout << static_cast<json>(colour_message) << std::flush;


        if (in_range(hue, 215, 219)) {
            colour_detected = 'b';
        } else if (in_range(hue, 5, 13.5)) {
            colour_detected = 'r';
        } else {
            colour_detected = 'n';
        }

        if (sorter_active) {
            if (current_sort == colour_detected && distance_sensor.get() < 15) {
                int voltageBeforeStop = conveyor.get_voltage();
                delay(45);
                conveyor.move(-127);
                delay(250);
                conveyor.move_voltage(voltageBeforeStop); //reset the voltage to what it was before reversing the conveyor
                colour_detected = 'n';
            } else {
                driver_inputs();
            }
        } else {
            driver_inputs();
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


void conveyor_task() {

    bool conveyor_held;
    bool conveyor_overvolt;

    bool overvolt_state = false;

    int conveyor_overvolt_count = 0;

    while (true) {
        conveyor_held = master.get_digital(E_CONTROLLER_DIGITAL_R2);

        conveyor_overvolt = conveyor.get_current_draw() > 2500;

        if (conveyor_overvolt) {
            conveyor_overvolt_count++;
        } else {
            conveyor_overvolt_count = 0;
        }


        // If the conveyor is overvolted and its the first time, move it backwards for a bit
        if ((conveyor_overvolt_count > 100) && !overvolt_state) {
            overvolt_state = true;
            conveyor.move(-100);
            delay(250);
            conveyor.move(0);
        } else if (!conveyor_overvolt && !conveyor_held) { // If the conveyor is no longer overvolted and not held, reset state
            overvolt_state = false;
        }

        if (!overvolt_state) {
            if (conveyor_held) {
                conveyor.move(100);
            } else {
                conveyor.move(0);
            }
        }

        delay(10);
    }
}