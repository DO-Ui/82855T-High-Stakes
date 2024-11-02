#pragma once

bool in_range(double value, double bottom, double top) {
    return (value >= bottom) && (value <= top);
}

void colour_sorter_task() {

    std::vector<char> colours = {}; // 'r' represents red 'b' represents blue
    char last_colour = 'n'; // 'n' means empty
    int ring_cooldown = 0;
    int queue_cooldown = -1;

    while (true) {
        // 200-ish is blue
        // 10-ish is red
        double hue = colour_sensor.get_hue();

        std::string colours_string = "";
        for (char colour : colours) {
            colours_string += colour;
        }

        Message colour_message = {"colour", {{"hue", hue}, {"colours", colours_string}}};
        std::cout << static_cast<json>(colour_message) << std::flush;


        if ((in_range(hue, 195, 215) && last_colour != 'b') && ring_cooldown == 0) {
            colours.push_back('b');
            last_colour = 'b';
            ring_cooldown = 35;
            queue_cooldown = 250;
        } else if ((in_range(hue, 5, 13.5) && last_colour != 'r') && ring_cooldown == 0) {
            colours.push_back('r');
            last_colour = 'r';
            ring_cooldown = 35;
            queue_cooldown = 250;
        } else {
            last_colour = 'n';
        }



        // if ((colours.size() > 0 && colours.back() == 'r') && distance_sensor.get() < 15) {
        //     delay(150);
        //     conveyor.move(-127);
        //     delay(200);
        //     conveyor.move(0);
        //     // remove_colour(colours, 'r');
        //     colours.pop_back();
        // } else {
        //     if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
        //         conveyor.move(100);
        //     } else if (master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
        //         conveyor.move(127);
        //     } else {
        //         conveyor.move(0);
        //     }
        // }

        if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
                conveyor.move(100);
            } else if (master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
                conveyor.move(127);
            } else {
                conveyor.move(0);
        }


        if (colours.size() > 10) {
            colours.erase(colours.begin());
        }

        if (ring_cooldown > 0) {
            ring_cooldown--;
        }

        if (queue_cooldown > 0) {
            queue_cooldown--;
        }

        if (queue_cooldown == 0) {
            colours.clear();
            queue_cooldown = -1;
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
