#include "main.h"
#include "lemlib/api.hpp"
#include "./devices.h"
#include "./tasks.h"
#include "logging.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "json.hpp"

using json = nlohmann::json;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	std::cout << "foxglove" << std::endl;
	lcd::initialize();

	horizontal_tracker.set_position(0);
	vertical_tracker.set_position(0);
	chassis.calibrate();
	chassis.setPose(0,0,0);


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {


	bool clampState = false;

	int count = 0;

	while (true) {
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.arcade(leftY, rightX, false, 0.75);

		if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intake.move(-127);
		} else {
			intake.move(0);
		}

		if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			conveyor.move(100);
		} else {
			conveyor.move(0);
		}

		if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			mogoclamp.extend();
		} else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			mogoclamp.retract();
		}

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
			chassis.moveToPose(0, 24, 0, 4000, {.horizontalDrift = 8, .lead = 0.3});
		}

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
			chassis.moveToPose(0, 0, 0, 4000, {.forwards=false, .horizontalDrift = 8, .lead = 0.3});
		}


	
		lemlib::Pose pose = chassis.getPose();
		// print to brain screen
		lcd::print(0, "x: %f", pose.x);
		lcd::print(1, "y: %f", pose.y);
		lcd::print(2, "theta: %f", pose.theta);

		// Odometry odom = {(double)pose.x, (double)pose.y, (double)pose.theta};
		// Message odom_message = {"robot_position", odom};
		// json j = static_cast<json>(odom_message);
		// to_json(j, odom_message);
		// std::string message = j.dump();
		// int odom_message_length = sizeof(message);
		// // convert message to unsigned char array
		// unsigned char message_array[odom_message_length];
		// for (int i = 0; i < odom_message_length; i++) {
		// 	message_array[i] = message[i];
		// }
		// // send message
		// serial.write(message_array, odom_message_length);

		// serial.flush();

		// std::cout << static_cast<json>(odom_message) << std::flush;

		delay(10);

	}
}