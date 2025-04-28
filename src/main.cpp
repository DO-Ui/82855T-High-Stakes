#include "main.h"
#include "lemlib/api.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"
#include "constants.h"
#include "globalStates.h"
#include "armController.h"
#include "./devices.h"
#include "macros.h"
#include <cmath>
#include <iostream>
#include <string>
#include "util.h"
#include "logging.hpp"
#include "json.hpp"
#include "./autoSelector.h"
#include "./tasks.h"
#include "autons.h"

// using json = nlohmann::json;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	// std::cout << "foxglove" << std::endl;
	lcd::initialize();

	colour_sensor.set_led_pwm(100);
	colour_sensor.set_integration_time(60);
	horizontal_tracker.set_data_rate(5);
	vertical_tracker.set_data_rate(5);
	imu.set_data_rate(5);
	horizontal_tracker.set_position(0);
	vertical_tracker.set_position(0);
	horizontal_tracker.reset();
	vertical_tracker.reset();
	chassis.calibrate();
	ladybrownMotor.tare_position();
	// // gps_sensor.set_data_rate(5);
	// // gps_sensor.set_offset(-6.0*0.0254, -0.25*0.0254);
	// // gps_sensor.set_position(-62.2343, 0, 90);
	master.clear();

	// // Task odom_task([&]() {
	// // 	while (true) {
	// // 		lemlib::Pose pose = chassis.getPose();
	// // 		// Odometry odom = {std::ceil((double)pose.x * 100.0) / 100.0, std::ceil((double)pose.y * 100.0) / 100.0, std::ceil((double)pose.theta * 100.0) / 100.0};
	// // 		Odometry odom = {round2dp(pose.x), round2dp(pose.y), round2dp(pose.theta)};
	// // 		Message odom_message = {"odometry", odom};
	// // 		std::cout << static_cast<json>(odom_message) << std::flush;
	// // 		delay(25);
	// // 	}
	// // });

	Task lbtask(ladybrown_and_color_task);
	Task reactClawClamp(reactiveClawClamp);
	Task autoClamp(autoClampTask);
	Task stopRing(monitor_and_stop_conveyor);
	// Task lbAngleReset(lbAngleResetTask);

	// autoSelector();
	// Task lbunjam(unjamLBTask);

	// // Task gps_task(gps_sensor_task);

	// // NOTE: colour_task has logging, remove if not needed




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

	sorter_active = true;
	auton_active = true;
	team_color = 'b'; //KEEP THiS COLOR IN BOT


	// lbTarget = 2;
	// delay(100);
	// ladybrownMotor.move(127);
	// delay(2000);
	// ladybrownMotor.move(0);

	SORAuto();


	// ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	// revealRingRush();

	//WORLDS AUTOS
	//RED SIDE
	// redMogoRush();

	// redRingRush();
	// redRightCenterRingAlliance5Ring();
	// revealRingRush();
	// blueRingRush();





	// blueLeftMogoRush();
	// These ones below work
	// skills(); // FOR PROVS
	//RED SIDE
	// redRightSoloAWP(); // NOT WOKRING
	// redLeftSoloAWP(); //WORKS FOR PROVS
	// redRingSidePROVSSoloAWP(); // FOR PROVS runs across half the field
	// globalRightsideSoloAWPSAFE(); //should also work FOR PROVS
	//BLUE SIDE
	// blueRingSidePROVSSoloAWP(); // FOR PROVS runs across half the field
	// blueMogoRush();
	// blueRightPROVSAlliancePlus5Ring(); //WORKS FOR PROVS
	// globalLeftsideSoloAWPSAFE(); //should also work FOR PROVS
	// blueLeftSoloAWP();

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



	sorter_active = true;
	auton_active = false;
	team_color = 'b'; //KEEP THiS COLOR IN BOT

	// revealRingRush();

	//WORLDS AUTOS
	//RED SIDE
	// redMogoRush();





	//FOLLOWING LINES SHOULD BE UNCOMMENTED WHEN AUTO MOVES BACK TO autonomous() function
	// auton_active = false; 
	// sorter_active = true;
	// chassis.setPose(0, 0, 0);

	// team_color = 'b';

	// int count = 0; //used for automatic PID tuning

	while (true) {

		// if (auton_active) {
		// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
		// 		if (auto_selected == 1) {
		// 			redMogoRush();
		// 		} else if (auto_selected == 2) {
		// 			redRightCenterRingAlliance5Ring();
		// 		} else {
		// 			revealRingRush();
		// 		}
		// 		auton_active = false;
		// 	} else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
		// 		auton_active = false;
		// 	}
		// }

		// else { //THIs ELSE SHOULD BE REMOVED WHEN AUTO MOVES BACK TO autonomous() function




			int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
			int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

			chassis.arcade(leftY, rightX, false, 0.75);

			// if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
				// find_tracking_center(10000);
				// chassis.moveToPoint(0, 24, 3000);
				// chassis.moveToPose(0, 48, 0, 2000);
				// chassis.turnToHeading(180, 1000);
				// ringDoinker.toggle();
			// }
			// if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
				// chassis.moveToPoint(0, 0, 3000, {.forwards = false});
				// chassis.moveToPose(0, 0, 0, 2000, {.forwards = false});
				// chassis.turnToHeading(0, 1000);
			// }

			// lbController();

			// if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) { //claw doinker mode activated
			// 	if (!clawDoinker.is_extended()) {
			// 		clawDoinker.extend();
			// 	}
			// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
			// 		if (claw.is_extended()) {
			// 			claw.retract();
			// 		} else {
			// 			reactiveClawClampOn = true;
			// 		}
			// 	}
			// } else {
				// clawDoinker.retract();
				// reactiveClawClampOn = false;
				// claw.retract();
				if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
					// if (mogoclamp.is_extended()) {
					// 	mogoclamp.retract();
					// } else {
					// 	clampRequested = true;
					// }
					mogoclamp.toggle();
				}

				if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
					if (!ringDoinker.is_extended()) {
						ringDoinker.extend();
					}
				}  else {
					if (ringDoinker.is_extended()) {
						ringDoinker.retract();
					}		
				}


			// }

				if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
					ladybrownMotor.tare_position();
				}





			// // print to brain screen
			// lcd::print(0, "x: %f", chassis.getPose().x);
			// lcd::print(1, "y: %f", chassis.getPose().y);
			// lcd::print(2, "theta: %f", chassis.getPose().theta);
			// lcd::print(3, "hori tracker: %f", horizontal_tracking_wheel.getDistanceTraveled());
			// lcd::print(4, "verti tracker: %f", vertical_tracking_wheel.getDistanceTraveled());
		// }

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
		// 	master.print(0, 0, "P: %f", ch	assis.lateralPID.kP);
		// }
		// if (count == 6) {
		// 	master.print(1, 0, "D: %f", chassis.lateralPID.kD);
		// 	count = 0;
		// }

		// count++;

		delay(20);

	}
}