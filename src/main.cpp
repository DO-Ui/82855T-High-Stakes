#include "main.h"
#include "lemlib/api.hpp"
#include "./devices.h"
#include "logging.hpp"
#include "json.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "./tasks.h"
#include "autons.h"

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
	vertical_tracker.set_data_rate(10);
	imu.set_data_rate(10);
	horizontal_tracker.set_position(0);
	vertical_tracker.set_position(0);
	horizontal_tracker.reset();
	vertical_tracker.reset();
	chassis.calibrate();
	chassis.setPose(0, 0, 0); 

	master.clear();

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
	//RELEASE INTAKE
	intake.move(-127);
	// delay(250);
	// intake.move(0);

	//sorter_active = false;


	// These ones below work
	//RED SIDE 
	//redLeft5RingElim();
	//redRightSoloAWP();
	redLeftSoloAWP();
	//BLUE SIDE
	//blueRightSoloAWP();
	//blueLeftSoloAWP();
	// blueRight5RingElim();


	//NONFUNCTIONAL
	//blueDoubleMogoAWP();
	//redDoubleMogoAWP();
	//redMogoRushSoloAWP();
	//blueMogoRushSoloAWP();
	//redTwoMogosAWP();
	//redRightTeammateAWP();
	//blueLeftTeammateAWP();
	//redLeftElims();
	//blueAllianceStake();
	//redAllianceStake();
	// skills();
	// redLeftAllianceStake4Ring();



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

	Task colour_task(colour_sorter_task);

	bool clampState = true;
	bool isDoinkerOut = false;

	sorter_active = false;

	// int count = 0; //used for automatic PID tuning

	while (true) {
		
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.arcade(leftY, rightX, false, 0.75);
		if(master.get_digital(E_CONTROLLER_DIGITAL_A)){
		}
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
			chassis.moveToPose(0, 0, 0, 3000, {.forwards = false});
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


		if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			if (!isDoinkerOut) {
				doinker.extend();
				isDoinkerOut = true;
			}
		}
		else if(isDoinkerOut){
			doinker.retract();
			isDoinkerOut = false;
		}

		// // print to brain screen
		lcd::print(0, "x: %f", chassis.getPose().x);
		lcd::print(1, "y: %f", chassis.getPose().y);
		// lcd::print(2, "theta: %f", imu.get_heading());
		// lcd::print(3, "horizontal rotations: %d", horizontal_tracker.get_position()/100);
		// lcd::print(4, "vertical rotations: %d", vertical_tracker.get_position()/100);

		// if (master.get_digital(E_CONTROLLER_DIGITAL_LEFT)) {
		// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
		// 		chassis.lateralPID.kD += 0.1;
		// 	} else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
		// 		chassis.lateralPID.kD -= 0.1;
		// 	}
		// } else {
		// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
		// 		chassis.lateralPID.kP += 0.1;
		// 	} else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
		// 		chassis.lateralPID.kP -= 0.1;
		// 	}
		// }


		// if (count == 3) {
		// 	master.print(0, 0, "P: %f", chassis.lateralPID.kP);
		// }
		// if (count == 6) {
		// 	master.print(1, 0, "D: %f", chassis.lateralPID.kD);
		// 	count = 0;
		// }

		// count++;

		delay(20);

	}
}