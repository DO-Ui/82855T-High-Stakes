#include "main.h"
#include "lemlib/api.hpp"
#include "./devices.h"
#include "logging.hpp"
#include "json.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "./tasks.h"

using json = nlohmann::json;

/**
 * @brief Rounds a float to 2 decimal places
 * 
 * @param num The number to round
 * @return float The rounded number
 */
float round2dp(float num) {
	return std::ceil(num * 100.0) / 100.0;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	std::cout << "foxglove" << std::endl;
	lcd::initialize();

	colour_sensor.set_led_pwm(100);


	horizontal_tracker.set_data_rate(10);
	// vertical_tracker.set_data_rate(10);
	imu.set_data_rate(10);
	horizontal_tracker.set_position(0);
	// vertical_tracker.set_position(0);
	horizontal_tracker.reset();
	// vertical_tracker.reset();
	chassis.calibrate();
	chassis.setPose(0, 0, 0);

	Task odom_task([&]() {
		while (true) {
			lemlib::Pose pose = chassis.getPose();
			// Odometry odom = {std::ceil((double)pose.x * 100.0) / 100.0, std::ceil((double)pose.y * 100.0) / 100.0, std::ceil((double)pose.theta * 100.0) / 100.0};
			Odometry odom = {round2dp(pose.x), round2dp(pose.y), round2dp(pose.theta)};
			Message odom_message = {"odometry", odom};
			std::cout << static_cast<json>(odom_message) << std::flush;
			delay(25);
		}
	});

	// NOTE: colour_task has logging, remove if not needed
	Task colour_task(colour_sorter_task);

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
	// MOGO RUSH SOLO AWP
	// chassis.setPose(-58, -35, 270);
	// chassis.moveToPoint(-15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
	// chassis.turnToPoint(-8.5, -41.5, 800, {.forwards=false, .earlyExitRange=10}); // turn toward mogo flat side
	// // chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
	// chassis.moveToPose(-8.5, -41.75, 300, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp contested mogo
	// delay(400);
	// chassis.turnToPoint(-25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
	// conveyor.move(127); // score preload onto mogo
	// chassis.moveToPose(-25, -47, 270, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1200);
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.moveToPose(-49.5, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
	// delay(500);
	// intake.move(127); // make sure blue ring goes away
	// delay(1000);
	// conveyor.move(0);	
	// mogoclamp.retract(); // release the mogo
	// chassis.moveToPose(-49.5, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
	// intake.move(-100);
	// conveyor.move(127);
	// chassis.waitUntilDone();
	// chassis.moveToPose(-49.5, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
	// delay(780);
	// conveyor.move(0);
	// chassis.moveToPose(-32, -23, 300, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	// intake.move(-25);
	// chassis.waitUntilDone();
	// mogoclamp.extend(); // clamp new mogo
	// conveyor.move(127); // score ring onto mogo
	// delay(1000);
	// conveyor.move(0);
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPose(-27, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
	// intake.move(0);

	// SAFE TWO MOGOS AWP
	// chassis.setPose(-58, -35, 270);
	// chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	// chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	// chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(120);
	// chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	// chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1800); // TODO change delay
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.waitUntilDone();
	// chassis.turnToPoint(-45, -10.5, 1000, {.earlyExitRange=10}); // turn toward reversed stack intermediate point
	// delay(500);
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPose(-45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
	// intake.move(-100);
	// conveyor.move(127);
	// chassis.moveToPose(-45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
	// delay(790);
	// conveyor.move(0);
	// intake.move(0);
	// chassis.turnToPoint(-30, 15, 800, {.forwards=false}); // turn toward mogo flat side
	// chassis.moveToPose(-30, 15, 240, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(127);	
	// chassis.moveToPoint(-23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
	// chassis.waitUntilDone();
	// conveyor.move(0);
	// intake.move(0);

	

	// TEAMMATE AWP RIGHT SIDE
	// chassis.setPose(-58, -35, 270);
	// chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	// chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	// chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(120);
	// chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	// chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1800);
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.waitUntilDone();
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPoint(-23.6, -2.5, 10000, {.maxSpeed=80}); // Move to ladder
	// chassis.waitUntilDone();
	// conveyor.move(0);
	// intake.move(0);
	// chassis.tank(30, 30);
	// delay(2000);
	// chassis.tank(0, 0);

	// ELIMS LEFT SIDE (Unfinished)
	// chassis.setPose(-58.5, 48, 270);
	// chassis.turnToPoint(-32, 28.7, 1500, {.forwards=false, .earlyExitRange=5}); // turn toward mogo flat side
	// chassis.moveToPose(-32, 28.7, 300, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(120);
	// chassis.turnToPoint(-23.5, 47, 1000, {.earlyExitRange=10}); // turn toward ring stack
	// chassis.moveToPose(-23.5, 47, 43, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1100);
	// intake.move(127); // ensure the blue isn't intaken
	// chassis.moveToPoint(-9, 60, 1000, {.earlyExitRange=5}); // move to intermediate point
	// chassis.moveToPose(-4, 37, 180, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed=80}); // move into double ring stack
	// intake.move(-127); // start intaking double ring stack
	// chassis.waitUntilDone();
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.moveToPose(-47, 37, 90, 2000, {.horizontalDrift = 8, .lead = 0.2}); // move back
	// chassis.waitUntilDone();
	// conveyor.move(0);


	// SAFE ALLIANCE STAKE
	chassis.setPose(55, -15.65, 0);
	chassis.moveToPose(55, 0, 0, 1000); // move to alliance stake
	intake.move(127);
	chassis.turnToHeading(270, 1200); // turn toward alliance stake
	chassis.waitUntilDone();
	chassis.setPose(55, 0, 270);
	intake.move(0);

	chassis.moveToPose(62, 0, 270, 1000, {.forwards=false, .maxSpeed=60}); // move to alliance stake
	chassis.waitUntilDone();
	conveyor.move(120);
	delay(1000);
	conveyor.move(0);

	// chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	// chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	// chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(120);
	// chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	// chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1800); // TODO change delay
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.waitUntilDone();
	// chassis.turnToPoint(-45, -10.5, 1000, {.earlyExitRange=10}); // turn toward reversed stack intermediate point
	// delay(500);
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPose(-45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
	// intake.move(-100);
	// conveyor.move(127);
	// chassis.moveToPose(-45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
	// delay(790);
	// conveyor.move(0);
	// intake.move(0);
	// chassis.turnToPoint(-30, 15, 800, {.forwards=false}); // turn toward mogo flat side
	// chassis.moveToPose(-30, 15, 240, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp mogo
	// delay(400);
	// conveyor.move(127);	
	// chassis.moveToPoint(-23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
	// chassis.waitUntilDone();
	// conveyor.move(0);
	// intake.move(0);

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


	bool clampState = true;

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



		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
			if (clampState) {
				mogoclamp.extend();
				clampState = !clampState;
			} else {
				mogoclamp.retract();
				clampState = !clampState;
			}
		}

		// // print to brain screen
		// lcd::print(0, "x: %f", pose.x);
		// lcd::print(1, "y: %f", pose.y);
		// lcd::print(2, "theta: %f", imu.get_heading());
		// lcd::print(3, "horizontal rotations: %d", horizontal_tracker.get_position()/100);
		// lcd::print(4, "vertical rotations: %d", vertical_tracker.get_position()/100);



		// if (count == 3) {
		// 	master.print(0, 0, "x: %f", pose.x);
		// }
		// if (count == 6) {
		// 	master.print(1, 0, "y: %f", pose.y);
		// }

		// if (count == 9) {
		// 	master.print(2, 0, "theta: %f", pose.theta);
		// 	count = 0;
		// } 
		// count++;

		delay(20);

	}
}