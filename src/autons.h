#pragma once
using namespace pros;
/**
 * SKILLS ROUTE
 * by Grant
 */
inline void skills(){
	//The commments in this funtion relate to the jerryio field, so "bottom left" would be on the red positive side
	chassis.setPose(-62.8, -15.5, 0);
	set_LBPosition(2); //score alliance stake
	delay(800);
	//upper left corner
	chassis.turnToPoint(-47.581, -0.207, 1000, {.forwards = false});
	chassis.moveToPoint(-47.581, -0.207, 1000, {.forwards = false});
	chassis.moveToPose(-47.581, 13.484, 180, 1000);
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(350);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp first mogo
	delay(250);
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(-24, 24, 2000); //move to first ring
	chassis.moveToPose(-2.132, 56.514, 29, 3000, {.horizontalDrift = 8}); //move to wall stake ring
	conveyor.move(0);
	chassis.turnToPoint(-23.721, 47.496, 1000); //turn to next ring
	chassis.moveToPoint(-23.721, 47.496, 2000); //move to next ring
	conveyor.move(127);
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(-58.328, 47, 3000, {.maxSpeed = 80}); //grab two corner rings
	chassis.turnToPoint(-47.733, 58.524, 700);
	chassis.moveToPoint(-47.733, 58.524, 1000); //grab last corner ring
	chassis.turnToHeading(110, 1000);
	chassis.moveToPose(-60, 60, 135, 1500, {.forwards=false, .earlyExitRange=3}); //drive to corner
	conveyor.move(0);
	chassis.waitUntilDone();
	mogoclamp.toggle();
	chassis.waitUntilDone();
	chassis.moveToPoint(-47, 47, 800);
	//lower left corner
	chassis.moveToPose(-48, -13, 0, 2500, {.forwards = false}); //move to mogo in lower left corner
	approachAndClampMogo();
	intake.move(-127);
	delay(100);
	chassis.turnToPoint(-23.672, -23.714, 700);
	chassis.moveToPose(-23.672, -23.714, 90, 1000); //move to first ring lower left corner
	chassis.moveToPose(0, -58.991, 180, 2000); //move to middle bottom ring


	chassis.moveToPoint(-6.287, -47.921, 2000);
	conveyor.move(127);
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(-55.198, -47.767, 3000); //pick up three horizontally aligned rings
	// chassis.moveToPose(-17.435, -49.518, 295, 2000); using only moveToPose to grab the three horizontally aligned rings in lower left corner
	// chassis.moveToPose(-59.738, -47.407, 270, 2000);

	chassis.moveToPoint(-47.365, -58.991, 1500); //pick up last ring in corner
	chassis.turnToHeading(70, 1000);
	chassis.moveToPoint(-59.439, -61.721, 1000, {.forwards = false, .earlyExitRange = 5});
	conveyor.move(0);
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop off mogo in lower left corner
	//lower right corner
	chassis.moveToPose(23.879, -47.111, 75, 4000); //move to first ring on right side
	chassis.waitUntilDone();
	conveyor.move(0); //turn off conveyor to store the ring
	delay(100);
	chassis.moveToPoint(47, -16, 2000); //setup to clamp middle mogo
	chassis.turnToHeading(180, 1000);
	delay(200);
	chassis.moveToPoint(47, -5, 1000, {.forwards = false, .earlyExitRange = 5}); //plow middle mogo
	approachAndClampMogo();
	conveyor.move(127);
	chassis.turnToPoint(24.746, -22, 1000);
	chassis.moveToPoint(24.746, -22, 1000); //grab ring before going under ladder
	chassis.turnToPoint(2.496, -2.591, 1000); //grab ring under ladder
	delay(500);
	chassis.moveToPoint(2.496, -2.591, 2000);
	chassis.turnToPoint(21.113, 20.567, 1000); 
	chassis.moveToPoint(21.113, 20.567, 1000); //grab first ring in upper right corner
	delay(500);
	chassis.turnToPoint(23.714, 47.102, 1000); //grab the rest of the rings
	chassis.moveToPoint(23.714, 47.102, 1000);
	chassis.turnToHeading(90, 1000);
	chassis.moveToPoint(47.407, 47.102, 1000); 
	chassis.turnToHeading(45, 1000); //turn to position to intake ring in upper right corner (TODO color sort out)
	chassis.moveToPoint(59.903, 59.247, 1000); //intake ring
	chassis.moveToPoint(57.443, 55.968, 1000); //go out a bit to have room to turn
	chassis.turnToHeading(225, 1000);
	chassis.moveToPoint(59.254, 58.948, 1000); //move to upper right corner 
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop mogo off
	chassis.turnToHeading(180, 1000);
	chassis.moveToPoint(59.254, 39.59, 1000);
	delay(500);
	chassis.turnToHeading(0, 1000);
	chassis.moveToPoint(59.254, 34.706, 1500, {.forwards = false, .earlyExitRange = 5});
	approachAndClampMogo();
	//lower right corner
	chassis.turnToPoint(32.138, -61.097, 1000);
	chassis.moveToPoint(32.138, -61.097, 1000);
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(58.727, -62.15, 1000, {.forwards = false, .earlyExitRange = 5});
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop off final mogo in lower right corner
	conveyor.move(0);
	intake.move(0);
}


/**
 * Grant's Solo AWP Red Left side
 * Score on alliance stake -> score 5 rings on left mogo -> touch ladder
 * Gear touching wall, 2 inches to outeroutermost boundary of tile from back high strength
 * ON RING SIDE
 */
inline void redLeftSoloAWP(){
	chassis.setPose(-62.8, 15.5, 180);
	set_LBPosition(2);
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
	delay(350);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
	delay(250);
	chassis.turnToPoint(-11.423, 39, 1000, {.minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntilDone();
	conveyor.move(127);
	intake.move(-127);

	//following block is slow middle ring approach
	chassis.moveToPoint(-6.5, 40, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(-6.5, 41, 500, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(-23, 30, 750, {.forwards = false, .minSpeed=30, .earlyExitRange=3}); // back up
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(-23, 52, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToPoint(-6.5, 54, 550); 
	chassis.moveToPoint(-6.5, 54, 750); //get final contested ring
	chassis.moveToPoint(-16, 54, 750, {.forwards = false});

	//following is quick ring get
	// chassis.moveToPoint(8.768, 39.315, 1500, {.minSpeed=60, .earlyExitRange=3}); //move to contested rings
	// chassis.moveToPoint(6.8, 50.165, 1000);
	// chassis.moveToPoint(9.868, 31.566, 1000, {.forwards = false});
	// chassis.turnToPoint(20.458, 44.2, 1000, {.minSpeed=50, .earlyExitRange=10});
	// chassis.moveToPoint(20.458, 44.2, 1000); //get safe ring

	chassis.turnToHeading(320, 1000, {.minSpeed = 50, .earlyExitRange = 20});
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
	
	//the following block ensures ladder touch
	// chassis.moveToPoint(-11.676, 11.676, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //move underneath ladder
	// chassis.waitUntilDone();
	// set_LBPosition(0);

	//the following block rushes positive corner
	chassis.tank(-127, -127);
	delay(500);
	set_LBPosition(0);
	chassis.turnToPoint(-56.364, -53.678, 700);
	chassis.moveToPoint(-56.364, -53.678, 3000);

}


inline void globalRightsideSoloAWPSAFE(){
	chassis.setPose(62.8, 15.5, 180);
	set_LBPosition(2);
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
	set_LBPosition(0);

}

/**
 * 
 */

 inline void globalLeftsideSoloAWPSAFE(){
	chassis.setPose(-62.8, 15.5, 180);
	set_LBPosition(2);
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
	set_LBPosition(0);

}

/**
 * Grant's Solo AWP Blue Right Side (Mirrored from red side)
 * Score on alliance stake -> score five rings on right mogo -> touch ladder / rush positive
 * ON RING SIDE
 */
inline void blueRightSoloAWP(){
	chassis.setPose(62.8, 15.5, 180);
	set_LBPosition(2);
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
	chassis.turnToPoint(11.423, 39, 1000, {.minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntilDone();
	conveyor.move(127);
	intake.move(-127);

	
	chassis.moveToPoint(8, 40, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(8, 40, 500, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(22, 30, 750, {.forwards = false, .minSpeed=30, .earlyExitRange=3}); // back up
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(22, 52, 1000); //get ring behind contested rings
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
	delay(650);

	//the following block moves to the ladder
	// chassis.moveToPoint(11.676, 11.676, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //move underneath ladder
	// chassis.waitUntilDone();
	// set_LBPosition(0);

	//the following block rushes positive corner
	chassis.tank(-127, -127);
	delay(500);
	set_LBPosition(0);
	chassis.turnToPoint(60.91, -54.711, 700);
	chassis.moveToPoint(60.91, -54.711, 3000);

}


inline void redMogoRush(){
	chassis.setPose(-53.5, -64.75, 90);
	chassis.moveToPoint(-22, -64.75, 1000, {.minSpeed = 60, .earlyExitRange = 10});
	chassis.moveToPose(-10.79, -59.5, 33, 800, {.minSpeed = 80}); //rush mogo
	chassis.waitUntilDone();
	doinker.toggle();
	delay(800);
	chassis.turnToPoint(-18.7, -62, 700, {.forwards = false});
	chassis.moveToPoint(-18.7, -62, 1600, {.forwards = false}); //bring mogo back
	delay(500);
	doinker.toggle();
	chassis.turnToHeading(230, 1000);
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
	delay(250);
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(-60.181, -61.054, 1500, {.minSpeed = 40, .earlyExitRange = 1});
	chassis.turnToHeading(225, 700);
	chassis.waitUntilDone(); //grab corner ring
	chassis.tank(40, 40);
	intake.move(127);
	delay(400);
	chassis.tank(127, 127);
	delay(700);
	chassis.tank(0, 0);
	delay(200);
	chassis.tank(90, 90);
	intake.move(-127);
	delay(800);
	chassis.moveToPoint(-52.719, -52.156, 1000, {.forwards = false}); //do a little turn to release the first mogo
	chassis.turnToPoint(-30.906, -30.917, 1000);
	delay(1000);
	chassis.turnToPoint(-30.906, -30.917, 1000, {.forwards = false});
	mogoclamp.toggle(); //release first mogo
	chassis.moveToPoint(-30.906, -30.917, 1000, {.forwards = false});
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp second mogo
	delay(250);
	chassis.turnToPoint(-22.869, -47.564, 1000);
	chassis.moveToPoint(-22.869, -47.564, 1000); //grab safe ring
	set_LBPosition(2);
	delay(300);
	chassis.moveToPoint(-12.824, -15.418, 1500, {.forwards = false, .minSpeed = 80, .earlyExitRange = 3}); //move to ladder
	chassis.waitUntilDone();
	set_LBPosition(0); //touch ladder

}
/**
 * RED RIGHT 3 RING PLUS CORNER
 * Score on alliance stake -> score 2 rings on right mogo -> touch ladder
 * ON MOGO SIDE
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


	// chassis.setPose(59, -35, 90);
	// chassis.moveToPoint(15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
	// chassis.turnToPoint(8.5, -41.5, 800, {.forwards=false, .earlyExitRange=5}); // turn toward mogo flat side
	// // chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
	// chassis.moveToPose(8.5, -41.5, 60, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
	// chassis.waitUntilDone();
	// delay(100);
	// mogoclamp.extend(); // clamp contested mogo
	// delay(400);
	// chassis.turnToPoint(25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
	// conveyor.move(127); // score preload onto mogo
	// chassis.moveToPose(25, -47, 90, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
	// intake.move(-127); // start intaking bottom ring of stack
	// delay(1200);
	// intake.move(0); // stop intake to ensure conveyor grabs
	// chassis.moveToPose(50, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
	// delay(500);
	// intake.move(127); // make sure blue ring goes away
	// delay(1000);
	// conveyor.move(0);	
	// mogoclamp.retract(); // release the mogo
	// chassis.moveToPose(50, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
	// intake.move(-100);
	// conveyor.move(127);
	// chassis.waitUntilDone();
	// chassis.moveToPose(50, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
	// delay(780);
	// conveyor.move(0);
	// chassis.moveToPose(32, -22, 60, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	// intake.move(-25);
	// chassis.waitUntilDone();
	// mogoclamp.extend(); // clamp new mogo
	// conveyor.move(127); // score ring onto mogo
	// delay(1000);
	// conveyor.move(0);
	// // mogoclamp.retract(); // release mogo
	// // chassis.moveToPose(-30, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
	// intake.move(0);
}



//OLD ONES



// /**
//  * RED 5 RING ELIM
//  * Grab mogo -> score 5 rings on it -> run to positive corner
//  * ON RING SIDE
//  */
// inline void redLeft5RingElim(){
// 	chassis.setPose(-57.5, 40.5, 270);
// 	chassis.turnToPoint(-31, 28, 700, {.forwards=false, .minSpeed=5, .earlyExitRange=5}); // turn toward mogo flat side
// 	chassis.moveToPose(-31, 28, 300, 700, {.forwards = false, .lead=0.3}); //move to left mogo
// 	// chassis.moveToPoint(-31, 28, 700, {.forwards = false, .minSpeed=5, .earlyExitRange=10}); //move to left mogo
// 	chassis.waitUntilDone();
// 	chassis.tank(-45, -45);
// 	delay(450);
// 	chassis.tank(0, 0);
// 	mogoclamp.extend(); //clamp left mogo
// 	delay(100);
// 	chassis.turnToPoint(-11.423, 39, 500);
// 	chassis.waitUntilDone();
// 	conveyor.move(127);
// 	intake.move(-127);
// 	chassis.moveToPoint(-11.423, 39, 1500, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
// 	chassis.moveToPoint(-11.423, 39, 1500, {.maxSpeed= 20}); //go to first contested ring
// 	chassis.moveToPoint(-24, 30, 1000, {.forwards = false});
// 	chassis.turnToHeading(0, 1000);
// 	chassis.moveToPoint(-24, 51, 1000); //get ring behind contested rings
// 	delay(200);
// 	chassis.turnToPoint(-11.423, 51, 700);
// 	chassis.moveToPoint(-11.423, 51, 1000); //get final contested ring
// 	chassis.moveToPoint(-43.605, 42.498, 1500, {.forwards = false});
// 	chassis.waitUntilDone();

// 	// Doinker mech

// 	// doinker.extend();
// 	// chassis.turnToPoint(-57, 57, 1000);
// 	// chassis.moveToPoint(-57, 57, 1000);
// 	// chassis.turnToHeading(340, 500);
// 	// delay(200);
// 	// chassis.turnToHeading(60, 1000, {.minSpeed = 100}); //spin robot to clear rings out of corner
// 	// chassis.turnToPoint(-60, 60, 1000);
// 	// doinker.retract();
// 	// delay(200);
// 	// chassis.moveToPose(-60, 60, 315, 1000); //move to left corner to grab lowest ring
// 	// delay(200);
// 	// chassis.moveToPoint(-47, 47, 1000, {.forwards = false});
// 	// chassis.turnToHeading(180, 1000);
// 	// chassis.moveToPoint(-47, -9, 2000);


// 	// Terrence autism
// 	chassis.moveToPose(-61, 61, 315, 1000); //move to left corner to grab lowest ring
// 	chassis.waitUntilDone();
// 	chassis.tank(100, 100);
// 	intake.move(127);
// 	delay(1000);
// 	chassis.tank(0, 0);
// 	intake.move(-100);
// 	delay(500);

// 	//MOVE TO POSITIVE CORNER
// 	chassis.moveToPoint(-51, -51, 1000, {.forwards = false});
// 	chassis.turnToHeading(0, 1000);
// 	chassis.moveToPoint(-51, 0, 2000, {.forwards = false, .minSpeed=50, .earlyExitRange = 5});

// 	// //MOVE TO LADDER
// 	// chassis.turnToPoint(25.743, 5.138, 700);
// 	// chassis.moveToPoint(25.743, 5.138, 1500);
	
// 	chassis.waitUntilDone();
// 	conveyor.move(0);
// 	intake.move(0);



// }

// /**
//  * BLUE 5 RING ELIM
//  * Grab mogo -> score 5 rings on it -> run to positive corner
//  * ON RING SIDE
//  */
// inline void blueRight5RingElim(){
// 	chassis.setPose(57.5, 40.5, 90);
// 	chassis.turnToPoint(31, 28, 700, {.forwards=false, .minSpeed=5, .earlyExitRange=5}); // turn toward mogo flat side
// 	chassis.moveToPose(31, 28, 60, 700, {.forwards = false, .lead=0.3}); //move to right mogo
// 	// chassis.moveToPoint(31, 28, 700, {.forwards = false, .minSpeed=5, .earlyExitRange=10}); //move to right mogo
// 	chassis.waitUntilDone();
// 	chassis.tank(-45, -45);
// 	delay(450);
// 	chassis.tank(0, 0);
// 	mogoclamp.extend(); //clamp right mogo
// 	delay(100);
// 	chassis.turnToHeading(305, 1000);
// 	chassis.waitUntilDone();
// 	conveyor.move(127);
// 	intake.move(-127);
// 	chassis.moveToPoint(11.423, 39, 1500, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
// 	chassis.moveToPoint(11.423, 39, 1500, {.maxSpeed= 20}); //go to first contested ring
// 	chassis.moveToPoint(24, 30, 1000, {.forwards = false});
// 	chassis.turnToHeading(0, 1000);
// 	chassis.moveToPoint(24, 51, 1000); //get ring behind contested rings
// 	delay(200);
// 	chassis.turnToPoint(11.423, 52, 700);
// 	chassis.moveToPoint(11.423, 52, 1000); //get final contested ring
// 	chassis.moveToPoint(43.605, 42.498, 1500, {.forwards = false});
// 	chassis.waitUntilDone();


// 	// Terrence autism
// 	chassis.moveToPose(61.5, 61.5, 45, 1000); //move to left corner to grab lowest ring
// 	chassis.waitUntilDone();
// 	chassis.tank(100, 100);
// 	intake.move(127);
// 	delay(1000);
// 	chassis.tank(0, 0);
// 	intake.move(-100);
// 	delay(500);

// 	//MOVE TO POSITIVE CORNER
// 	chassis.moveToPoint(51, -51, 1000, {.forwards = false});
// 	chassis.turnToHeading(0, 1000);
// 	chassis.moveToPoint(51, -9, 2000, {.forwards = false, .minSpeed=50, .earlyExitRange = 5});

// 	// //MOVE TO LADDER
// 	// chassis.turnToPoint(-25.743, 5.138, 700);
// 	// chassis.moveToPoint(-25.743, 5.138, 1500);
	
// 	chassis.waitUntilDone();
// 	conveyor.move(0);
// 	intake.move(0);

// }



// /**
//  * Alliance stake and 4 ring (8pts)
//  * ON RING SIDE
//  */
// inline void redLeftAllianceStake4Ring(){
// 	chassis.setPose(-54, 14.2, 0);
// 	chassis.moveToPose(-54, 1, 0, 800, {.forwards = false}); // move to alliance stake
// 	chassis.turnToHeading(90, 700); // turn toward alliance stake
// 	chassis.moveToPoint(-61.9, -.1, 700, {.forwards = false});
// 	chassis.waitUntilDone();
// 	conveyor.move(127);
// 	delay(400);
// 	chassis.moveToPoint(-55, 0, 600);
// 	chassis.turnToPoint(-32.628, 18.083, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPoint(-32.628, 18.083, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
// 	chassis.waitUntilDone();
// 	chassis.tank(-60, -60);
// 	delay(450);
// 	chassis.tank(0, 0);
// 	mogoclamp.extend(); //clamp left mogo
// 	delay(100);
// 	chassis.turnToPoint(-10.219, 40.291, 1000);
// 	conveyor.move(127);
// 	intake.move(-127);
// 	chassis.moveToPoint(-11.423, 39, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
// 	chassis.moveToPoint(-11.423, 39, 500, {.maxSpeed= 35}); //go to first contested ring
// 	chassis.moveToPoint(-24, 30, 750, {.forwards = false, .minSpeed=30, .earlyExitRange=3}); // back up
// 	conveyor.move(0); // stop conveyor while reversing
// 	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
// 	chassis.moveToPoint(-24, 51, 1000); //get ring behind contested rings
// 	conveyor.move(127);
// 	chassis.turnToPoint(-11.423, 51, 550); 
// 	chassis.moveToPoint(-11.423, 51, 750); //get final contested ring
// 	chassis.moveToPoint(-20.303, 50.759, 750, {.forwards = false});
// 	conveyor.move(127);
// 	chassis.turnToPoint(-61, 61, 800);
// 	chassis.moveToPose(-61, 61, 315, 1500, {.minSpeed=60, .earlyExitRange=3}); //move to left corner to grab lowest ring
// 	chassis.waitUntilDone();
// 	chassis.tank(100, 100);
// 	intake.move(127);
// 	delay(400);
// 	chassis.tank(0, 0);
// 	intake.move(-100);
// 	delay(500);
// 	chassis.moveToPoint(-42, 42, 1000, {.forwards = false});


// }

// /**
//  * Alliance stake and 4 ring (8pts)
//  * ON RING SIDE
//  */
// inline void blueRightAllianceStake4Ring(){
// 	chassis.setPose(54, 14.2, 0);
// 	chassis.moveToPose(54, 1, 0, 800, {.forwards = false}); // move to alliance stake
// 	chassis.turnToHeading(270, 700); // turn toward alliance stake
// 	chassis.moveToPoint(61.9, -.1, 700, {.forwards = false});
// 	chassis.waitUntilDone();
// 	conveyor.move(127);
// 	delay(400);
// 	chassis.moveToPoint(55, 0, 600);
// 	chassis.turnToPoint(32.628, 18.083, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPoint(32.628, 18.083, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
// 	chassis.waitUntilDone();
// 	chassis.tank(-60, -60);
// 	delay(450);
// 	chassis.tank(0, 0);
// 	mogoclamp.extend(); //clamp left mogo
// 	delay(100);
// 	chassis.turnToPoint(10.219, 40.291, 1000);
// 	conveyor.move(127);
// 	intake.move(-127);
// 	chassis.moveToPoint(11.423, 39, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
// 	chassis.moveToPoint(11.423, 39, 500, {.maxSpeed= 35}); //go to first contested ring
// 	chassis.moveToPoint(24, 30, 750, {.forwards = false, .minSpeed=30, .earlyExitRange=3}); // back up
// 	conveyor.move(0); // stop conveyor while reversing
// 	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
// 	chassis.moveToPoint(24, 51, 1000); //get ring behind contested rings
// 	conveyor.move(127);
// 	chassis.turnToPoint(11.423, 51, 550); 
// 	chassis.moveToPoint(11.423, 51, 750); //get final contested ring
// 	chassis.moveToPoint(20.303, 50.759, 750, {.forwards = false});
// 	conveyor.move(127);
// 	chassis.turnToPoint(61, 61, 800);
// 	chassis.moveToPose(61, 61, 45, 1500, {.minSpeed=60, .earlyExitRange=3}); //move to left corner to grab lowest ring
// 	chassis.waitUntilDone();
// 	chassis.tank(100, 100);
// 	intake.move(127);
// 	delay(400);
// 	chassis.tank(0, 0);
// 	intake.move(-100);
// 	delay(500);
// 	chassis.moveToPoint(42, 42, 1000, {.forwards = false});


// }

//OLDOLDOLD ONES

// /**
//  * SAFE TWO MOGOS AWP BLUE SIDE
//  */
// inline void blueDoubleMogoAWP(){
//     chassis.setPose(58, -35, 90); // setPose modified
// 	chassis.moveToPoint(41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
// 	chassis.turnToPoint(30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPose(30, -28.5, 120, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp mogo
// 	delay(400);
// 	conveyor.move(127);
// 	chassis.turnToPoint(23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
// 	chassis.moveToPose(23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1800); // TODO change delay
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.waitUntilDone();
// 	// delay(500);
// 	conveyor.move(0);

// 	mogoclamp.retract(); // release mogo
// 	chassis.moveToPose(45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
// 	intake.move(-100);
// 	conveyor.move(127);
// 	chassis.moveToPose(45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
// 	delay(790);
// 	conveyor.move(0);
// 	intake.move(0);
// 	chassis.turnToPoint(30, 15, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPose(30, 15, 120, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp mogo
// 	delay(400);
// 	conveyor.move(127);	
// 	chassis.moveToPoint(23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
// 	chassis.waitUntilDone();
// 	conveyor.move(0);
// 	intake.move(0);


// 	chassis.setPose(58, -35, 90);
// 	chassis.moveToPoint(15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
// 	chassis.turnToPoint(8.5, -41.5, 800, {.forwards=false, .earlyExitRange=10}); // turn toward mogo flat side
// 	// chassis.moveToPoint(8.5, -42, 2000, {.forwards=false}); // move to mogo
// 	chassis.moveToPose(8.5, -41.75, 60, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp contested mogo
// 	delay(400);
// 	chassis.turnToPoint(25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
// 	conveyor.move(127); // score preload onto mogo
// 	chassis.moveToPose(25, -47, 90, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1200);
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.moveToPose(49, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
// 	delay(500);
// 	intake.move(127); // make sure blue ring goes away
// 	delay(1000);
// 	conveyor.move(0);	
// 	mogoclamp.retract(); // release the mogo
// 	chassis.moveToPose(49, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
// 	intake.move(-100);
// 	conveyor.move(127);
// 	chassis.waitUntilDone();
// 	chassis.moveToPose(49, 8, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
// 	delay(780);
// 	conveyor.move(0);
// 	chassis.moveToPose(32, -23, 60, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
// 	intake.move(-25);
// 	chassis.waitUntilDone();
// 	mogoclamp.extend(); // clamp new mogo
// 	conveyor.move(127); // score ring onto mogo
// 	delay(1000);
// 	conveyor.move(0);
// 	mogoclamp.retract(); // release mogo
// 	chassis.moveToPose(25, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
// 	intake.move(0);
// }

// /**
//  * SAFE TWO MOGOS AWP RED SIDE
//  */
// inline void redDoubleMogoAWP(){
// 	chassis.setPose(-58, -35, 90); // setPose modified
// 	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
// 	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp mogo
// 	delay(400);
// 	conveyor.move(127);
// 	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
// 	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1800); // TODO change delay
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.waitUntilDone();
// 	chassis.turnToPoint(-45, -10.5, 1000, {.earlyExitRange=10}); // turn toward reversed stack intermediate point
// 	delay(500);
// 	mogoclamp.retract(); // release mogo
// 	chassis.moveToPose(-45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
// 	intake.move(-100);
// 	conveyor.move(127);
// 	chassis.moveToPose(-45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
// 	delay(790);
// 	conveyor.move(0);
// 	intake.move(0);
// 	chassis.turnToPoint(-30, 15, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPose(-30, 15, 240, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp mogo
// 	delay(400);
// 	conveyor.move(127);	
// 	chassis.moveToPoint(-23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
// 	chassis.waitUntilDone();
// 	conveyor.move(0);
// 	intake.move(0);
// }

// /**
//  * MOGO RUSH SOLO AWP RED SIDE
//  */
// inline void redMogoRushSoloAWP(){
// 	chassis.setPose(-58, -35, 270);
// 	chassis.moveToPoint(-15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
// 	chassis.turnToPoint(-8.5, -41.5, 800, {.forwards=false, .earlyExitRange=10}); // turn toward mogo flat side
// 	// chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
// 	chassis.moveToPose(-8.5, -41.75, 300, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp contested mogo
// 	delay(400);
// 	chassis.turnToPoint(-25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
// 	conveyor.move(127); // score preload onto mogo
// 	chassis.moveToPose(-25, -47, 270, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1200);
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.moveToPose(-52, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
// 	delay(500);
// 	intake.move(127); // make sure blue ring goes away
// 	delay(1000);
// 	conveyor.move(0);	
// 	mogoclamp.retract(); // release the mogo
// 	chassis.moveToPose(-52, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
// 	intake.move(-100);
// 	conveyor.move(127);
// 	chassis.waitUntilDone();
// 	chassis.moveToPose(-52, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
// 	delay(780);
// 	conveyor.move(0);
// 	chassis.moveToPose(-32, -23, 300, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
// 	intake.move(-25);
// 	chassis.waitUntilDone();
// 	mogoclamp.extend(); // clamp new mogo
// 	conveyor.move(127); // score ring onto mogo
// 	delay(1000);
// 	conveyor.move(0);
// 	// mogoclamp.retract(); // release mogo
// 	// chassis.moveToPose(-30, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
// 	intake.move(0);
// }

// /**
//  * MOGO RUSH SOLO AWP BLUE SIDE
//  */
// inline void blueMogoRushSoloAWP(){
// 	chassis.setPose(59, -35, 90);
// 	chassis.moveToPoint(15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
// 	chassis.turnToPoint(8.5, -41.5, 800, {.forwards=false, .earlyExitRange=5}); // turn toward mogo flat side
// 	// chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
// 	chassis.moveToPose(8.5, -41.5, 60, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp contested mogo
// 	delay(400);
// 	chassis.turnToPoint(25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
// 	conveyor.move(127); // score preload onto mogo
// 	chassis.moveToPose(25, -47, 90, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1200);
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.moveToPose(50, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
// 	delay(500);
// 	intake.move(127); // make sure blue ring goes away
// 	delay(1000);
// 	conveyor.move(0);	
// 	mogoclamp.retract(); // release the mogo
// 	chassis.moveToPose(50, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
// 	intake.move(-100);
// 	conveyor.move(127);
// 	chassis.waitUntilDone();
// 	chassis.moveToPose(50, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
// 	delay(780);
// 	conveyor.move(0);
// 	chassis.moveToPose(32, -22, 60, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
// 	intake.move(-25);
// 	chassis.waitUntilDone();
// 	mogoclamp.extend(); // clamp new mogo
// 	conveyor.move(127); // score ring onto mogo
// 	delay(1000);
// 	conveyor.move(0);
// 	// mogoclamp.retract(); // release mogo
// 	// chassis.moveToPose(-30, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
// 	intake.move(0);
// }

// /**
//  * SAFE TWO MOGOS AWP
//  */
// inline void redTwoMogosAWP(){
	// 	chassis.setPose(-58, -35, 270);
	// 	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	// 	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	// 	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	// 	chassis.waitUntilDone();
	// 	delay(100);
	// 	mogoclamp.extend(); // clamp mogo
	// 	delay(400);
	// 	conveyor.move(127);
	// 	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	// 	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	// 	intake.move(-127); // start intaking bottom ring of stack
	// 	delay(1800); // TODO change delay
	// 	intake.move(0); // stop intake to ensure conveyor grabs
	// 	chassis.waitUntilDone();
	// 	intake.move(0);
	// 	conveyor.move(0);

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
// }

// /**
//  * TEAMMATE AWP RIGHT SIDE RED
//  */

// inline void redRightTeammateAWP(){
// 	chassis.setPose(-58, -35, 270);
// 	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
// 	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
// 	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
// 	chassis.waitUntilDone();
// 	delay(100);
// 	mogoclamp.extend(); // clamp mogo
// 	delay(400);
// 	conveyor.move(127);
// 	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
// 	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
// 	intake.move(-127); // start intaking bottom ring of stack
// 	delay(1800);
// 	intake.move(0); // stop intake to ensure conveyor grabs
// 	chassis.waitUntilDone();
// 	mogoclamp.retract(); // release mogo
// 	chassis.moveToPoint(-23.6, -2.5, 10000, {.maxSpeed=80}); // Move to ladder
// 	chassis.waitUntilDone();
// 	conveyor.move(0);
// 	intake.move(0);
// 	chassis.tank(30, 30);
// 	delay(2000);
// 	chassis.tank(0, 0);
// }
