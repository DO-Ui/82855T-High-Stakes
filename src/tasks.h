#pragma once


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
