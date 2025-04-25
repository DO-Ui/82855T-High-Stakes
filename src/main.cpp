#include "main.h"
#include "lemlib/api.hpp"
#include "armController.h"
#include "./devices.h"
// #include "pros/screen.h"
// #include "pros/screen.hpp"
// #include "constants.h"
#include "globalStates.h"
// #include "macros.h"
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <type_traits>
#include "util.h"
// #include "logging.hpp"
// #include "json.hpp"
// #include "pong.h"
// #include "./autoSelector.h"
#include "./tasks.h"
// #include "autons.h"


// using json = nlohmann::json;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	ladybrownMotor.tare_position();
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
	Task reactClawClamp(reactiveClawClamp);

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

	// sorter_active = true;
	// auton_active = true;
	// curr_color_sort_out = 'r'; //SORT OUT THIS COLOR

	// blueLeftMogoRush();
	// These ones below work
	// skills(); // FOR PROVS
	//RED SIDE
	// redRightSoloAWP(); // NOT WOKRING
	// redLeftSoloAWP(); //WORKS FOR PROVS
	// redMogoRush(); // FOR PROVS
	// redRingSidePROVSSoloAWP(); // FOR PROVS runs across half the field
	// globalRightsideSoloAWPSAFE(); //should also work FOR PROVS
	//BLUE SIDE
	// blueRingSidePROVSSoloAWP(); // FOR PROVS runs across half the field
	// blueMogoRush();
	// stupid();
	// blueRightPROVSAlliancePlus5Ring(); //WORKS FOR PROVS
	// globalLeftsideSoloAWPSAFE(); //should also work FOR PROVS
	// blueLeftSoloAWP();

	//NONFUNCTIONAL
		// blueRightSoloAWP(); //should work FOR PROVS


	// redLeftAllianceStake4Ring();
	// blueRight5RingElim();
	// redLeft5RingElim()
	//redMogoRushSoloAWP();
	//blueMogoRushSoloAWP();
	//redTwoMogosAWP();
	//redRightTeammateAWP();
	//blueLeftTeammateAWP();

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

	while (true) {
		
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		
		chassis.arcade(leftY, rightX, false, 0.75);


		
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
			ringDoinker.toggle();
		}

		
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
			intakeRiser.toggle();
		}
		
		if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) { //claw doinker mode activated
			if (!clawDoinker.is_extended()) {
				clawDoinker.extend();
			}
			if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
				if (claw.is_extended()) {
					claw.retract();
				} else {
					reactiveClawClampOn = true;
				}
			}
		} else {
			clawDoinker.retract();
			reactiveClawClampOn = false;
			claw.retract();
			if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
				mogoClamp.toggle();
			}
		}


		delay(20);

	}
}