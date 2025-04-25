#pragma once


/**
 * Grant's Solo AWP Red Left side FOR PROVS
 * Score on alliance stake -> score 5 rings on left mogo -> touch ladder
 * Almost touching wall, 3 inches to outeroutermost boundary of tile from back high strength
 * ON RING SIDE
 */
inline void redLeftSoloAWP(){
	chassis.setPose(-62.8, 14.5, 180); // start hs 3 inches from tile edge, against wall
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	conveyor.move(127);
	chassis.turnToPoint(-47.353, 0, 800, {.minSpeed=80, .earlyExitRange=10});
	// set_LBPosition(0);
	stopNextRing = true; // Ensure reversed stack ring is held
	chassis.moveToPoint(-47.353, 0, 600, {.maxSpeed = 50}); //move to reversed ring stack
	chassis.waitUntilDone();
	delay(450);
	intakeRiser.toggle();
	delay(200);
	chassis.turnToPoint(-27.226, 21.3, 1000, {.forwards = false, .minSpeed=75, .earlyExitRange=5}); //move to mogo
	chassis.moveToPose(-27.226, 21.3, 225, 1200, {.forwards = false, .minSpeed=20, .earlyExitRange=2}); //move to mogo
	chassis.waitUntilDone();
	chassis.tank(-30, -30);
	delay(150);
	chassis.tank(0, 0);
	stopNextRing = false;
	delay(300);
	approachAndClampMogo(); // clamp ring side safe mogo
	delay(150);
	conveyor.move(127);
	delay(100);
	chassis.turnToPoint(-3.887, 43.209, 800); // turn to contested ring stack
	chassis.moveToPoint(-3.887, 43.209, 950); //move to ring stack
	delay(300);
	chassis.moveToPoint(-19, 35, 900, {.forwards=false, .minSpeed=75, .earlyExitRange=9}); // move to intermediate point
	delay(400);
	chassis.moveToPoint(-25, 48, 800, {.minSpeed=60, .earlyExitRange=2}); // move to safe
	chassis.turnToPoint(-4.5, 53, 800, {.minSpeed=40, .earlyExitRange=5}); // turn to 2nd contested ring stack
	chassis.moveToPoint(-4.5, 53, 1000); //move to second contested ring stack

	//following code goes to corner
	chassis.moveToPoint(-50, 52, 900, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // move to intermediate point
	chassis.turnToPoint(-66, 71, 800, {.minSpeed=15, .earlyExitRange=9}); // turn to corner
	chassis.moveToPoint(-66, 71, 1000, {.maxSpeed = 100}); // move to corner
	intake.move(127); // reverse intake while jamming into corner
	chassis.waitUntilDone();
	// set_LBPosition(2);
	conveyor.move(0);
	delay(400);
	// chassis.tank(45, 45);
	// delay(400);
	// chassis.tank(-60, -60);
	// intake.move(-127); // try and pull ring outta corner
	// delay(650);
	// chassis.tank(0, 0);
	// delay(300);
	// chassis.tank(30, 30);
	// delay(450);
	// chassis.tank(0, 0);
	chassis.tank(40, 40);
	delay(300);
	chassis.tank(110, 110);
	conveyor.move(127);
	delay(150);
	chassis.tank(90, 90);
	intake.move(-127);
	delay(300);
	chassis.tank(-20, -20);
	delay(400);
	chassis.moveToPose(-54.456, -57.507, 0, 2000, {.forwards = false});


	//following block moves to ladder
	// chassis.moveToPoint(-16, 30, 1000, {.forwards=false}); // move to ladder
	// chassis.turnToPoint(-16, 0, 900);
	// chassis.moveToPoint(-16, 0, 2000, {.maxSpeed=55}); // move to ladder
	// chassis.waitUntilDone();
	// // set_LBPosition(2);

}

/*
	Setup HS 2 inches from tile edge, same as solo awp red left
	FOR PROVS
*/
inline void globalRightsideSoloAWPSAFE(){
	chassis.setPose(62.8, 15.5, 180);
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	chassis.turnToPoint(50.939, 3.926, 800, {.minSpeed=80, .earlyExitRange=10});
	chassis.moveToPoint(50.939, 3.926, 600); //move to reversed ring stack
	chassis.turnToPoint(28, 20, 1000, {.forwards = false, .minSpeed=80, .earlyExitRange=5}); //move to mogo
	intakeRiser.toggle();
	chassis.moveToPose(28, 20, 131, 1000, {.forwards = false}); //move to mogo
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
	delay(250);
	chassis.turnToPoint(25, 47, 800, {.earlyExitRange=10});
	chassis.waitUntilDone();
	conveyor.move(127);
	intake.move(-127);
	delay(800);
	chassis.moveToPoint(23, 47, 900, {.minSpeed=90}); //get safe ring
	chassis.turnToPoint(11.676, 11.676, 1000, {.forwards = false});
	chassis.moveToPoint(11.676, 11.676, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //move underneath ladder
	conveyor.move(0);
	intake.move(0);
	chassis.waitUntilDone();
	// set_LBPosition(0);

}

/**
 * Setup the same as all other AWPs
 * FOR PROVS
 */
 inline void globalLeftsideSoloAWPSAFE(){
	chassis.setPose(-62.8, 15.5, 180);
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	chassis.turnToPoint(-50.939, 3.926, 800, {.minSpeed=80, .earlyExitRange=10});
	chassis.moveToPoint(-50.939, 3.926, 600); //move to reversed ring stack
	chassis.turnToPoint(-28, 20, 1000, {.forwards = false, .minSpeed=75, .earlyExitRange=5}); //move to mogo
	intakeRiser.toggle();
	chassis.moveToPose(-28, 20, 231, 1000, {.forwards = false}); //move to mogo
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
	delay(250);
	chassis.turnToPoint(-23, 52, 1000, {.minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntilDone();
	conveyor.move(127);
	intake.move(-127);

	chassis.moveToPoint(-23, 52, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToHeading(295, 1000, {.minSpeed = 50, .earlyExitRange = 20});
	chassis.moveToPose(-61, 65, 315, 1500, {.lead=0.2, .minSpeed = 70}); // move to corner
	chassis.waitUntilDone();
	chassis.tank(40, 40);
	intake.move(127);
	delay(300);
	chassis.tank(127, 127);
	delay(400);
	chassis.tank(90, 90);
	intake.move(-127);
	delay(250);
	chassis.tank(-40, -40);
	delay(650);
	chassis.moveToPoint(-11.676, 11.676, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //move underneath ladder
	chassis.waitUntilDone();
	// set_LBPosition(0);

}

/**
 * Grant's Solo AWP Blue Right Side (Mirrored from red side) FOR PROVS
 * Score on alliance stake -> score five rings on right mogo -> touch ladder / rush positive
 * ON RING SIDE
 */
inline void blueRightSoloAWP(){
	chassis.setPose(62.8, 14.5, 180); //3 inches high strength from furthest mat edge

	// set_LBPosition(2);
	delay(800);
	// set_LBPosition(0);
	intakeRiser.toggle();
	intake.move(-127);
	chassis.turnToPoint(50.939, 3.926, 800, {.minSpeed=80, .earlyExitRange=10});
	chassis.moveToPoint(50.939, 3.926, 600); //move to reversed ring stack
	chassis.turnToPoint(28, 20, 1000, {.forwards = false, .minSpeed=80, .earlyExitRange=5}); //move to mogo
	intakeRiser.toggle();
	chassis.moveToPose(26.303, 21.561, 131, 1000, {.forwards = false}); //move to mogo
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
	delay(250);
	chassis.turnToPoint(11.423, 39, 1000, {.minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntilDone();
	conveyor.move(127);
	intake.move(-127);

	
	chassis.moveToPoint(6.007, 41.18, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(6.007, 41.18, 500, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(22, 30, 750, {.forwards = false, .minSpeed=30, .earlyExitRange=3}); // back up
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(23, 52, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToPoint(8, 52, 550); 
	chassis.moveToPoint(8, 52, 750); //get final contested ring
	chassis.moveToPoint(16, 52, 750, {.forwards = false});

	//the following block is quick ring in the middle get
	// chassis.moveToPoint(8.768, 39.315, 1500, {.minSpeed=60, .earlyExitRange=3}); //move to contested rings
	// chassis.moveToPoint(6.8, 50.165, 1000);
	// chassis.moveToPoint(9.868, 31.566, 1000, {.forwards = false});
	// chassis.turnToPoint(20.458, 44.2, 1000, {.minSpeed=50, .earlyExitRange=10});
	// chassis.moveToPoint(20.458, 44.2, 1000); //get safe ring

	chassis.turnToHeading(90, 1000, {.minSpeed = 50, .earlyExitRange = 20});
	chassis.moveToPose(64.5, 64, 50, 2000, {.minSpeed = 70}); // move to corner
	chassis.waitUntilDone();
	chassis.tank(40, 40);
	intake.move(127);
	delay(300);
	chassis.tank(127, 127);
	delay(400);
	chassis.tank(0, 0);
	chassis.tank(90, 90);
	intake.move(-127);
	// set_LBPosition(2);
	delay(650);

	// the following block moves to the ladder
	chassis.moveToPoint(11.676, 11.676, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //move underneath ladder
	chassis.waitUntilDone();
	// set_LBPosition(0);

	// //the following block rushes positive corner
	// chassis.tank(-127, -127);
	// delay(500);
	// // set_LBPosition(0);
	// chassis.turnToPoint(60.91, -54.711, 700);
	// chassis.moveToPoint(60.91, -54.711, 3000);

}



/**
 * @brief 5 ring + alliance stake on blue ring side
 * Score on alliance stake -> score five rings on right mogo -> touch ladder / rush positive
 * ON RING SIDE
 */
inline void blueRightPROVSAlliancePlus5Ring(){
	chassis.setPose(62.8, 14.5, 180); // start hs 3 inches from tile edge, against wall
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	conveyor.move(127);
	chassis.turnToPoint(48.374, 1.434, 800, {.minSpeed=80, .earlyExitRange=10});
	// set_LBPosition(0);
	stopNextRing = true; // Ensure reversed stack ring is held
	chassis.moveToPoint(48.374, 1.434, 700, {.maxSpeed = 60}); //move to reversed ring stack
	chassis.waitUntilDone();
	delay(450);	
	intakeRiser.toggle();
	chassis.turnToPoint(25.204, 22.568, 1000, {.forwards = false, .minSpeed=75, .earlyExitRange=5}); //move to mogo
	chassis.moveToPose(25.204, 22.568, 135, 1200, {.forwards = false, .minSpeed=20, .earlyExitRange=3}); //move to mogo
	chassis.waitUntilDone();
	chassis.tank(-30, -30);
	delay(150);
	chassis.tank(0, 0);
	stopNextRing = false;
	delay(300);
	approachAndClampMogo(); // clamp ring side safe mogo
	delay(150);
	conveyor.move(127);
	delay(100);
	chassis.turnToPoint(4.5, 43.5, 800); // turn to contested ring stack
	chassis.moveToPoint(4.5, 43.5, 950); //move to ring stack
	chassis.moveToPoint(19, 35, 900, {.forwards=false, .minSpeed=75, .earlyExitRange=9}); // move to intermediate point
	delay(400);
	chassis.moveToPoint(25, 48, 800, {.minSpeed=60, .earlyExitRange=2}); // move to safe
	chassis.turnToPoint(4.5, 55, 800, {.minSpeed=40, .earlyExitRange=5}); // turn to 2nd contested ring stack
	chassis.moveToPoint(4.5, 55, 1000); //move to second contested ring stack

	//following code moves to corner
	chassis.moveToPoint(50, 52, 900, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // move to intermediate point
	chassis.turnToPoint(66, 66, 800, {.minSpeed=15, .earlyExitRange=9}); // turn to corner
	chassis.moveToPoint(66, 66, 1000); // move to corner
	intake.move(127); // reverse intake while jamming into corner
	chassis.waitUntilDone();
	delay(400);


	// chassis.tank(45, 45);
	// delay(400);
	// chassis.tank(-60, -60);
	// intake.move(-127); // try and pull ring outta corner
	// delay(650);
	// chassis.tank(-20, -20);
	// delay(300);
	// chassis.tank(50, 50);
	// delay(450);
	// chassis.tank(0, 0);


	chassis.tank(40, 40);
	delay(300);
	chassis.tank(127, 127);
	conveyor.move(0);
	delay(150);
	chassis.tank(90, 90);
	conveyor.move(127);
	intake.move(-127);
	delay(200);
	chassis.tank(-20, -20);

	//following code moves to ladder
	// chassis.moveToPoint(16, 30, 1000, {.forwards=false}); // move to ladder
	// chassis.turnToPoint(16, 0, 900);
	// chassis.moveToPoint(16, 0, 1500, {.maxSpeed=55}); // move to ladder
	// chassis.waitUntilDone();
	// // set_LBPosition(2);
	

}

/**
 * @brief Blue Ring Side Solo awp FOR PROVS
 * Score alliance stake -> score 1 on ring side mogo -> score 2 on mogo side mogo -> touch ladder -> ends with 2 rings on clamped mogo
 * 
 */
inline void blueRingSidePROVSSoloAWP() {
	chassis.setPose(62.8, 14.5, 180);
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	conveyor.move(127);
	stopNextRing = true;
	chassis.turnToPoint(46, -1, 800, {.minSpeed=80, .earlyExitRange=10});
	// set_LBPosition(0);
	chassis.moveToPoint(46, -1, 600); //move to reversed ring stack
	chassis.waitUntilDone();
	delay(300);
	intakeRiser.toggle();
	delay(200);
	chassis.turnToPoint(19, 26, 1000, {.forwards = false, .minSpeed=75, .earlyExitRange=5}); //move to mogo
	chassis.moveToPoint(19, 26, 1000, {.forwards = false, .minSpeed=20, .earlyExitRange=2}); //move to mogo
	chassis.waitUntilDone();
	approachAndClampMogo(); // clamp ring side safe mogo
	delay(200);
	conveyor.move(127);
	chassis.turnToPoint(20, 52, 800, {.earlyExitRange=10}); // turn to ring stack
	stopNextRing = false;
	chassis.moveToPoint(20, 52, 600); //move to ring stack
	stopNextRing = true;
	chassis.waitUntilDone();
	delay(500);
	chassis.turnToPoint(39, -5, 1000); // turn to intermediate point
	chassis.moveToPoint(39, -5, 1300, {.minSpeed=95, .earlyExitRange=9}); // move to intermediate point
	chassis.waitUntil(18);
	mogoclamp.toggle();
	delay(500);
	conveyor.move(0);
	chassis.turnToPoint(17.5, -30, 800, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // turn to mogo
	chassis.moveToPoint(17.5, -30, 800, {.forwards=false}); // move to mogo
	chassis.waitUntilDone();
	approachAndClampMogo(); // clamp mogo
	delay(200);
	intake.move(-127);
	delay(300);
	stopNextRing = false;
	chassis.turnToPoint(20, -53, 900, {.minSpeed=70, .earlyExitRange=10}); // turn to ring stack
	chassis.moveToPoint(20, -53, 700); // move to ring stack
	conveyor.move(127);
	chassis.waitUntilDone();
	delay(500);
	chassis.swingToPoint(20, -2.5, lemlib::DriveSide::LEFT, 2000, { .direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=30, .earlyExitRange=5 }); // swing to face ladder
	chassis.moveToPoint(20, -2.5, 4000, {.maxSpeed=75}); // move to ladder
	delay(200);
	// set_LBPosition(2);
	chassis.waitUntilDone();
	chassis.tank(10, 10);
	delay(400);
	chassis.tank(0, 0);
	delay(300);
	chassis.moveToPose(57.507, -55.647, 0, 2000, {.forwards = false});
}


/**
 * @brief Red Ring Side Solo awp FOR PROVS
 * Score alliance stake -> score 1 on ring side mogo -> score 2 on mogo side mogo -> touch ladder -> ends with 2 rings on clamped mogo
 */
inline void redRingSidePROVSSoloAWP() {
	chassis.setPose(-62.8, 14.5, 180);
	// set_LBPosition(2);
	delay(800);
	intakeRiser.toggle();
	intake.move(-127);
	conveyor.move(127);
	stopNextRing = true;
	chassis.turnToPoint(-49, 1, 800, {.minSpeed=80, .earlyExitRange=10});
	// set_LBPosition(0);
	chassis.moveToPoint(-49, 1, 600); //move to reversed ring stack
	chassis.waitUntilDone();
	delay(400);
	intakeRiser.toggle();
	chassis.turnToPoint(-19, 26, 1000, {.forwards = false, .minSpeed=75, .earlyExitRange=5}); //move to mogo
	chassis.moveToPoint(-19, 26, 1000, {.forwards = false, .minSpeed=20, .earlyExitRange=2}); //move to mogo
	chassis.waitUntilDone();
	approachAndClampMogo(); // clamp ring side safe mogo
	conveyor.move(127);
	chassis.turnToPoint(-19, 50, 800, {.earlyExitRange=10}); // turn to ring stack
	stopNextRing = false;
	chassis.moveToPoint(-19, 50, 600); //move to ring stack
	stopNextRing = true;
	chassis.waitUntilDone();
	delay(500);
	chassis.turnToPoint(-39, -5, 1000); // turn to intermediate point
	intake.move(0);
	chassis.moveToPoint(-39, -5, 1300, {.minSpeed=95, .earlyExitRange=9}); // move to intermediate point
	chassis.waitUntilDone();
	mogoclamp.toggle();
	conveyor.move(0);
	chassis.turnToPoint(-17.5, -30, 800, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // turn to mogo
	chassis.moveToPoint(-17.5, -30, 800, {.forwards=false}); // move to mogo
	chassis.waitUntilDone();
	approachAndClampMogo(); // clamp mogo
	intake.move(-127);
	delay(300);
	chassis.turnToPoint(-20, -53, 900, {.minSpeed=70, .earlyExitRange=10}); // turn to ring stack
	chassis.moveToPoint(-20, -53, 700); // move to ring stack
	conveyor.move(127);
	chassis.waitUntilDone();
	delay(500);
	chassis.swingToPoint(-20, -2.5, lemlib::DriveSide::RIGHT, 2000, { .direction=lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed=30, .earlyExitRange=5 }); // swing to face ladder
	chassis.moveToPoint(-20, -2.5, 900, {.minSpeed=30, .earlyExitRange=3}); // move to ladder
	chassis.waitUntilDone();
	// set_LBPosition(2);
	chassis.tank(10, 10);
	delay(400);
	chassis.tank(0, 0);


	// chassis.moveToPoint(-37,)

}

inline void stupid() {
	chassis.setPose(58, -25, 90);
	chassis.moveToPoint(27, -25, 5000, {.forwards=false, .maxSpeed=60}); // intermediate point
	chassis.waitUntilDone();
	approachAndClampMogo();
	delay(700);
	conveyor.move(127);


}


/**
 * RED RIGHT 3 RING PLUS CORNER
 * Score on alliance stake -> score 2 rings on right mogo -> touch ladder
 * ON MOGO SIDE
 * NOT WORKING
 */
inline void redRightSoloAWP(){
	chassis.setPose(-55.05, -14.5, 180);
	chassis.moveToPose(-55.05, 1.4, 180, 800, {.forwards = false}); // move to alliance stake
	chassis.turnToHeading(90, 700); // turn toward alliance stake
	chassis.moveToPoint(-62, 0, 700, {.forwards = false});
	chassis.waitUntilDone();
	conveyor.move(127);
	delay(400);
	chassis.moveToPoint(-55, 0, 600); // move away from alliance
	chassis.turnToPoint(-31.204, -18.5, 800, {.forwards=false}); // turn to right safe mogo
	chassis.moveToPoint(-31.204, -18.5, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp right safe mogo
	delay(100);
	chassis.turnToPoint(-23, -50, 1000);
	chassis.moveToPoint(-23, -50, 1500); //grab safe ring
	// // intake.move(-127);
	// chassis.turnToPoint(-62.029, -63.693, 1000);
	// conveyor.move(127);
	// chassis.moveToPoint(-62.029, -63.693, 1100); //move to right corner to grab lowest ring
	// chassis.waitUntilDone();
	// chassis.tank(80, 80);
	// // intake.move(127);
	// delay(1000);
	// conveyor.move(0);
	// chassis.tank(0, 0);

	delay(2000);
	intake.move(0);

	mogoclamp.toggle();//REMOVE IN FUTURE

	// intake.move(-100);
	delay(500);
	// chassis.moveToPose(-28.913, -7.98, 29.667, 3000); //move to ladder

	chassis.turnToPoint(-22.008, -47.478, 800, {.forwards = false}); //THIS CODE IS FOR RUSH SETUP
	chassis.moveToPose(-22.008, -47.478, 270, 2000, {.forwards = false});

	conveyor.move(127);
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(0);
}

/**
 * BLUE LEFT 3 RING PLUS CORNER
 * Score on alliance stake -> score 2 rings on left mogo -> touch ladder
 * ON MOGO SIDE
 */
inline void blueLeftSoloAWP(){
	chassis.setPose(55.05, -14.25, 180);
	chassis.moveToPose(55.05, .5, 180, 800, {.forwards = false}); // move to alliance stake
	chassis.turnToHeading(270, 700, {.direction = lemlib::AngularDirection::CW_CLOCKWISE}); // turn toward alliance stake
	chassis.moveToPoint(63.4, 0, 700, {.forwards = false});
	chassis.waitUntilDone();
	conveyor.move(127);
	delay(400);

	chassis.moveToPoint(55, 0, 600); // move away from alliance stake
	intake.move(0);
	chassis.turnToPoint(31.204, -18.5, 1000, {.forwards=false}); // turn to left safe mogo
	conveyor.move(0);
	chassis.moveToPoint(31.204, -18.5, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(550);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp left safe mogo
	delay(100);
	chassis.turnToPoint(23, -50, 1000);
	chassis.moveToPoint(23, -50, 1500); //grab safe ring

	intake.move(-127);

	//CORNER CODE FOLLOWING
	// intake.move(-127);
	// chassis.turnToPoint(62.029, -63.693, 1000);
	// conveyor.move(127);
	// chassis.moveToPoint(62.029, -63.693, 1100); //move to left corner to grab lowest ring
	// chassis.waitUntilDone();
	// chassis.tank(80, 80);
	// intake.move(127);
	// delay(1000);
	// conveyor.move(0);
	// chassis.tank(0, 0);
	// intake.move(-100);
	// delay(500);

	delay(4000);
	intake.move(0);
	mogoclamp.toggle();

	// chassis.moveToPose(23.455, -12.864, 330.333, 3000); //move to ladder
	chassis.turnToPoint(22.008, -47.478, 800, {.forwards = false}); //THIS CODE IS FOR RUSH SETUP
	chassis.moveToPose(22.008, -47.478, 90, 2000, {.forwards = false});
	// ladybrownMotor.move(127);
	conveyor.move(127);
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(0);


}

/**
 * CURRENTLY RAMS CORNER TOO HARD
 * If teammate has ring side Solo AWP, then run this
 * Grab mogo -> Score preload, safe ring, and corner ring -> move to ladder
 * ON MOGO SIDE
 */
inline void redRightTeammate3Ring(){
	chassis.setPose(-57.5, -40.5, 270);
	chassis.turnToPoint(-31, -28, 700, {.forwards=false, .minSpeed=5, .earlyExitRange=5}); // turn toward mogo flat side
	chassis.moveToPose(-31, -28, 245, 700, {.forwards = false, .lead=0.3}); //move to right mogo
	chassis.waitUntilDone();
	chassis.tank(-45, -45);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp right mogo
	delay(100);
	chassis.turnToPoint(-23, -50, 1000);
	chassis.moveToPoint(-23, -50, 1500); //grab safe ring
	intake.move(-127);
	chassis.turnToPoint(-62.029, -63.693, 1000);
	conveyor.move(127);
	chassis.moveToPoint(-62.029, -63.693, 1100); //move to right corner to grab lowest ring
	chassis.waitUntilDone();
	chassis.tank(80, 80);
	intake.move(127);
	delay(1000);
	conveyor.move(0);
	chassis.tank(0, 0);
	intake.move(-100);
	delay(500);
	chassis.moveToPose(-28.913, -7.98, 29.667, 3000); //move to ladder
	conveyor.move(127);
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(0);
}

/**
 * MOGO RUSH SOLO AWP BLUE SIDE
 * 4.5 inch from wall, ramp barely touching starting line
 */
inline void blueLeftMogoRush(){
	chassis.setPose(47.62, -60, 90);
	chassis.moveToPoint(24, -60, 1000, {.forwards = false});
	chassis.turnToHeading(120, 1000, { .minSpeed=20, .earlyExitRange=10});
	chassis.moveToPoint(10.528, -52.068, 1500, {.forwards = false});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(100);
	mogoclamp.extend();
	// approachAndClampMogo(); //clamp contested mogo
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(24, -47, 1000); //grab first ring
	chassis.waitUntilDone();
	conveyor.move(0); //store first ring
	chassis.turnToHeading(180, 1000);
	mogoclamp.retract(); //release first mogo
	chassis.moveToPose(24, -34, 180, 1500, {.forwards =  false}); //go to second mogo
	approachAndClampMogo();
	delay(300);
	conveyor.move(127);
	chassis.moveToPoint(48, -24, 2000);
	chassis.turnToHeading(0, 1000);
	mogoclamp.retract(); // release the mogo
	chassis.moveToPoint(47, -7.5, 1500); // move to reversed stack	
	chassis.waitUntilDone();
	chassis.moveToPoint(47, 7, 2000); // intake the stack and toss the first ring
	delay(780);
	conveyor.move(0);
	chassis.moveToPose(58.053, 0, 180, 1000); //push ring in front of alliance stake out of the way
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(61, 0, 1000);
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(127); //score on alliance stake
	delay(1000);


}
