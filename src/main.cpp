#include "main.h"
#include "lemlib/api.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"
#include "constants.h"
#include "globalStates.h"
#include "armController.h"
#include "./devices.h"
#include "macros.h"
#include <string>
#include <cmath>
#include <iostream>
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

	Task lbtask(ladybrownTask);
	Task colorTask(colorSortTask);
	Task reactClawClamp(reactiveClawClamp);
	Task autoClamp(autoClampTask);
	Task stopRing(monitorAndStopConveyor);
	Task controllerPrint(controllerPrinting);
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
void disabled() {
	ladybrownMotor.move(0);
}

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
	team_color = 'b'; //KEEP THIS COLOR IN BOT


	//WORLDS AUTOS
	//RED SIDE
	// redMogoRush();
	// redRingSideTeammateAWP();
	// redRingTeammateSwinging();
	// redRingRush();
	// redRightCenterRingAlliance5Ring();

	//BLUE SIDE`
	// blueRingRush();
	// blueMogoSideCenterRing();
	blueRingSideTeammateAWP();
	// blueMogoRush();

	//GLOBAL
	// worldsSoloAWP();


	// chassis.setPose(-54, 13.5, 270);
	// setLBTargetPosition(CAPTURE);
	// delay(200);
	// conveyor.move(105);
	// delay(300);
	// conveyor.move(0);
	// chassis.swingToHeading(215, lemlib::DriveSide::LEFT, 900); // swing to alliance stake
	// //alliance
	// chassis.waitUntil(8);
	// setLBTargetPosition(WALLSTAKE);
	// delay(800);
	// chassis.moveToPoint(-49.84, 23.817, 1500, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //prep to intake upside down rings
	// chassis.waitUntil(9);
	// setLBTargetPosition(REST);


	//corner testing
	// mogoclamp.toggle();
	// conveyor.move(127);
	// chassis.setPose(-50, -50, 225);
	// chassis.moveToPose(-70, -70, 223, 1000, {.maxSpeed = 50}); //move to corner
	// intake.move(0);
	// chassis.moveToPose(-70, -70, 223, 1500, {.minSpeed = 100}); //move to corner
	// intake.move(127);
	// chassis.waitUntilDone();
	// chassis.tank(-30, -30);
	// delay(200);
	// chassis.tank(-70, -70);
	// delay(500);
	// intakeRiser.toggle();
	// chassis.moveToPose(-65, -65, 223, 1500, {.maxSpeed = 70}); //move to corner
	// chassis.waitUntilDone();
	// intakeRiser.toggle();
	// chassis.tank(-40, -40);
	// delay(300);
	// conveyor.move(50);
	// stopNextRing = true;


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

		if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) { //claw doinker mode activated
			if (!clawDoinker.is_extended()) {
				clawDoinker.extend();
			}
			if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
				claw.toggle();
			}
		} else {
			clawDoinker.retract();
			claw.retract();
		}

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
			mogoclamp.toggle();
		}


		// }
  
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
			ladybrownMotor.tare_position();
			// ringDoinker.toggle();
			// intakeRiser.toggle();
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