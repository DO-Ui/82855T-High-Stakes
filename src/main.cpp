#include "main.h"
#include "lemlib/api.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"
#include "constants.h"
#include "globalStates.h"
// #include "armController.h"
#include "./devices.h"
#include "macros.h"
#include <cmath>
#include <iostream>
#include <string>
#include <type_traits>
#include "util.h"
#include "logging.hpp"
#include "json.hpp"
#include "pong.h"
#include "./autoSelector.h"
#include "./tasks.h"
#include "autons.h"

bool holdLB = false;
int preCatch = 1; // 1 is precatch, -1 is needs press again, 0 is in postcatch
bool LBUpRefreshed = false;

void lbController() {

	if (holdLB) {
		float LBPower = cos(((ladybrownMotor.get_position() - 60) * 0.3333333333 * 0.01745329251));
		ladybrownMotor.move(LBPower * 10);
	}

	if (master.get_digital(E_CONTROLLER_DIGITAL_Y) && preCatch == 1) {
		ladybrownMotor.move(127);
		if (ladybrownMotor.get_position() > 30) {
			holdLB = true;
			preCatch = -1;
		}
		LBUpRefreshed = true;
	}

	if (LBUpRefreshed && !master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
		LBUpRefreshed = false;
		preCatch = 0;
	}

	if ((preCatch == 0 && master.get_digital(E_CONTROLLER_DIGITAL_Y))) {
		holdLB = false;
		ladybrownMotor.move(127);
		conveyor.move(-50); // get hook out of the way
		if (ladybrownMotor.get_position() < 40.0) {
			holdLB = false;
			preCatch = 1;
		}
	}

	if (!holdLB && preCatch == 0 && !master.get_digital(E_CONTROLLER_DIGITAL_Y)) {
		holdLB = true;
		LBUpRefreshed = false;
	}


	if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
		ladybrownMotor.move(-127);
	}
}



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
	Task reacClawClamp(reactiveClawClamp);
	Task autoClamp(autoClampTask);
	Task stopRing(monitor_and_stop_conveyor);
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
	team_color = 'r'; //KEEP THiS COLOR IN BOT

	// revealRingRush();

	//WORLDS AUTOS
	//RED SIDE
	// redMogoRush();
	redRingRush();





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
	// hang.retract();
	
	// auton_active = false; //CHANGE BEFORE PROVS TO FALSE
	// sorter_active = true; //CHANGE BACK TO TRUE
	// auton_active = true;
	// skills(); //REMOVE LATER
	// auton_active = false;
	chassis.setPose(0, 0, 0);


	// int count = 0; //used for automatic PID tuning

	while (true) {
		
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		
		chassis.arcade(leftY, rightX, false, 0.75);

		if(master.get_digital(E_CONTROLLER_DIGITAL_A)){
			// find_tracking_center(10000);
			// chassis.moveToPoint(0, 24, 3000);
			// chassis.moveToPose(0, 48, 0, 2000);
			// chassis.turnToHeading(180, 1000);
		}
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
			// chassis.moveToPoint(0, 0, 3000, {.forwards = false});
			// chassis.moveToPose(0, 0, 0, 2000, {.forwards = false});
			// chassis.turnToHeading(0, 1000);
			intakeRiser.toggle();
		}

		lbController();
		
		if(master.get_digital(E_CONTROLLER_DIGITAL_L2)){ //claw doinker mode activated
			if(!clawDoinker.is_extended()){
				clawDoinker.extend();
			}
			if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)){
				claw.toggle();
			}
		}
		else {
			clawDoinker.retract();
			if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
				if (mogoclamp.is_extended()) {
					mogoclamp.retract();
				} else {
					clampRequested = true;
				}
			}
		}
		

		
		


		// // print to brain screen
		lcd::print(0, "x: %f", chassis.getPose().x);
		lcd::print(1, "y: %f", chassis.getPose().y);
		lcd::print(2, "theta: %f", chassis.getPose().theta);
		lcd::print(3, "hori tracker: %f", horizontal_tracking_wheel.getDistanceTraveled());
		lcd::print(4, "verti tracker: %f", vertical_tracking_wheel.getDistanceTraveled());

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