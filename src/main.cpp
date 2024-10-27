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



	horizontal_tracker.set_data_rate(10);
	vertical_tracker.set_data_rate(10);
	imu.set_data_rate(10);
	horizontal_tracker.set_position(0);
	vertical_tracker.set_position(0);
	horizontal_tracker.reset();
	vertical_tracker.reset();
	delay(1000);
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

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
			std::cout << "test" << std::endl;
		}

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
			// chassis.moveToPoint(0, 48, 6000);
			chassis.moveToPose(0, 48, 0, 4000, {.horizontalDrift = 8, .lead = 0.5});
			// chassis.tank(127, 127);
			// delay(500);
			// chassis.tank(0, 0);

			// chassis.turnToPoint(0, 99999, 10000);
			// chassis.turnToHeading(0, 10000);
		}

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
			// chassis.moveToPoint(0, 0, 6000, {.forwards=false});
			// chassis.turnToHeading(90, 10000);
			// chassis.turnToPoint(99999, 0, 10000);
			chassis.moveToPose(0, 0, 0, 4000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5});
		}


	
		// // print to brain screen
		// lcd::print(0, "x: %f", pose.x);
		// lcd::print(1, "y: %f", pose.y);
		// lcd::print(2, "theta: %f", imu.get_heading());
		// lcd::print(3, "horizontal rotations: %d", horizontal_tracker.get_position()/100);
		// lcd::print(4, "vertical rotations: %d", vertical_tracker.get_position()/100);


		lemlib::Pose pose = chassis.getPose();

		if (count == 3) {
			master.print(0, 0, "x: %f", pose.x);
		}
		if (count == 6) {
			master.print(1, 0, "y: %f", pose.y);
		}

		if (count == 9) {
			master.print(2, 0, "theta: %f", pose.theta);
			count = 0;
		} 
		count++;
		
		
		
		Odometry odom = {std::ceil((double)pose.x * 100.0) / 100.0, std::ceil((double)pose.y * 100.0) / 100.0, std::ceil((double)pose.theta * 100.0) / 100.0};
		Message odom_message = {"odometry", odom};
		std::cout << static_cast<json>(odom_message) << std::flush;

		delay(20);

	}
}