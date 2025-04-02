#include "main.h"
#include "lemlib/api.hpp"
#include "ArmController.h"
#include "./devices.h"
#include "logging.hpp"
#include "json.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "./tasks.h"
#include "macros.h"
#include "autons.h"
#include "particle.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"

//controller mappings (all should be done now):
//R1: intake + conveyor 
//R2: reverse intake & conveyor
//L1: mogoclamp 
//L2: doinker 
//y (right paddle): ladybrown up macro
//right arrow (left paddle): ladybrown down macro
//down arrow: intake lower
//up arrow: intake riser
//left arrow: intake 
//X: ladybrown up manual 
//B: ladybrown down manual 

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

	colour_sensor.set_led_pwm(100);
	colour_sensor.set_integration_time(60);
	horizontal_tracker.set_data_rate(5);
	vertical_tracker.set_data_rate(5);
	ladybrownSensor.set_data_rate(5);
	imu.set_data_rate(5);
	horizontal_tracker.set_position(0);
	vertical_tracker.set_position(0);
	horizontal_tracker.reset();
	vertical_tracker.reset();
	chassis.calibrate();
	ladybrownSensor.reset();
	// gps_sensor.set_data_rate(5);
	// gps_sensor.set_offset(-6.0*0.0254, -0.25*0.0254);
	// gps_sensor.set_position(-62.2343, 0, 90);
	// chassis.setPose(-62.2343, 0, 90);
	master.clear();

	// Task odom_task([&]() {
	// 	while (true) {
	// 		lemlib::Pose pose = chassis.getPose();
	// 		// Odometry odom = {std::ceil((double)pose.x * 100.0) / 100.0, std::ceil((double)pose.y * 100.0) / 100.0, std::ceil((double)pose.theta * 100.0) / 100.0};
	// 		Odometry odom = {round2dp(pose.x), round2dp(pose.y), round2dp(pose.theta)};
	// 		Message odom_message = {"odometry", odom};
	// 		std::cout << static_cast<json>(odom_message) << std::flush;
	// 		delay(25);
	// 	}
	// });

	Task lbtask(ladybrown_and_color_task);
	Task stopRing(monitor_and_stop_conveyor);
	Task lbunjam(unjamLBTask);
	

	// Task gps_task(gps_sensor_task);

	// NOTE: colour_task has logging, remove if not needed

	//screen is 480 by 272 wide

	screen::set_pen(Color::blue);
	screen::fill_rect(0, 0, 480, 136);
	screen::set_pen(Color::red);
	screen::fill_rect(0, 136, 480, 272);
	screen::set_pen(Color::black);

	int numSeperatingLines = 5;
	for(int i = 1; i <= numSeperatingLines; i++){
		screen::draw_line(i*480/(numSeperatingLines+1), 0, i*480/(numSeperatingLines+1), 272);
	}


	screen::set_eraser(Color::white);
	screen::print(E_TEXT_MEDIUM, 15, 50, "RING");
	screen::print(E_TEXT_MEDIUM, 15, 70, "RUSH");

	screen_touch_status_s_t status;

    while(true) {
		status = c::screen_touch_status();
		if(status.touch_status == pros::E_TOUCH_HELD){
			pros::screen::fill_rect(status.x-10,status.y-10, status.x+10, status.y+10);
		}
    	pros::delay(5);
    }
	// while(true){
	// 	if(screen)
	// }


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
	current_sort = 'r'; //SORT OUT THIS COLOR

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
	blueRightPROVSAlliancePlus5Ring(); //WORKS FOR PROVS
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
	set_LBPosition(0);
	float lastDistFuncReading = 0;

	// hang.retract();
	
	auton_active = false; //CHANGE BEFORE PROVS TO FALSE
	sorter_active = true; //CHANGE BACK TO TRUE
	// auton_active = true;
	// skills(); //REMOVE LATER
	// auton_active = false;
	// chassis.setPose(0, 0, 0); vc
	

	// int count = 0; //used for automatic PID tuning

	while (true) {
		
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		
		chassis.arcade(leftY, rightX, false, 0.75);

		// if(master.get_digital(E_CONTROLLER_DIGITAL_A)){
		// 	chassis.moveToPoint(0, 24, 3000);
		// 	// chassis.moveToPose(0, 48, 0, 2000);
		// 	// chassis.turnToHeading(90, 1000);
		// 	// lastDistFuncReading = check_distance_back_BOTTOM_WALL();
		// }
		// if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
		// 	chassis.moveToPoint(0, 0, 3000, {.forwards = false});
		// 	// chassis.moveToPose(0, 0, 0, 2000, {.forwards = false});
		// 	// chassis.turnToHeading(0, 1000);
		// }

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
			mogoclamp.toggle();
		}

		if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			if(!doinker.is_extended()){
				doinker.extend();
			}
			
		} else if(doinker.is_extended()){
			doinker.retract();
		}

		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
			intakeRiser.toggle();
		}


		// // print to brain screen
		// lcd::print(0, "x: %f", chassis.getPose().x);
		// lcd::print(1, "y: %f", chassis.getPose().y);
		// lcd::print(2, "theta: %f", chassis.getPose().theta);
		// lcd::print(3, "Hori Tracking Wheel Distance: %f", horizontal_tracking_wheel.getDistanceTraveled());
		// lcd::print(4, "Verti tracking wheel distance: %f", vertical_tracking_wheel.getDistanceTraveled());
		// lcd::print(3, "LastDistanceCalcResult %f", lastDistFuncReading);
		// lcd::print(3, "LBRotation: %f", ((float)ladybrownSensor.get_angle())/100);
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