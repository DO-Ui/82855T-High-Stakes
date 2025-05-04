#pragma once


inline void blueMogoRush(){
	clawDoinker.extend();
	chassis.setPose(50.319, -60.135, 291.7);
	intake.move(127);
	chassis.moveToPose(17.15, -47, 300, 1200, {.lead=0.2, .minSpeed=127});
	// chassis.moveToPoint(17.161, -46.94, 1500, { .minSpeed = 127 }); //rush mogo
	reactiveClawClampOn = true;
	chassis.moveToPoint(34.544, -53.857, 2000, { .forwards = false, .minSpeed = 127 });
	claw.extend();
	reactiveClawClampOn = false;
	chassis.waitUntil(20);
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(800);
	chassis.turnToPoint(19.064, -55.227, 1200, { .forwards = false}); //turn to the rushed mogo
	chassis.moveToPoint(19.064, -55.227, 1200, { .forwards = false, .maxSpeed = 100 });
	chassis.waitUntilDone();
	chassis.tank(0, -100);
	delay(150);
	approachAndAutoClampMogo(80, 400); //clamp the rushed mogo
	delay(400);
}
// delrin 5 inches from wall
inline void blueMogoSideCenterRing() {
	chassis.setPose(54, -13.5, 90);
	chassis.swingToHeading(35, lemlib::DriveSide::LEFT, 900); // swing to alliance stake
	//alliance
	chassis.waitUntil(8);
	ladybrownMotor.move(127);
	delay(800);
	chassis.moveToPoint(49.84, -23.817, 1500, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //prep to intake upside down rings
	chassis.waitUntil(9);
	ladybrownMotor.move(-127);
	intakeRiser.toggle();
	intake.move(127);
	chassis.turnToPoint(49.84, -2, 700, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.moveToPoint(49.84, -2, 1500, {.maxSpeed=60 }); // move to upside down rings
	stopNextRing = true;
	conveyor.move(60);
	chassis.waitUntil(20);
	intakeRiser.toggle();
	delay(200);
	chassis.moveToPose(34.374, -17.6, 45, 1200, {.forwards = false, .minSpeed = 70}); //go to mogo
	approachAndClampMogo();
	chassis.turnToPoint(14.65, -17, 900, { .minSpeed = 10, .earlyExitRange = 3 }); // turn to center ring
	chassis.moveToPose(14.65, -17, 287, 900, { .lead = 0.05, .maxSpeed = 100 }); // move to grab center ring
	chassis.waitUntilDone();
	ringDoinker.toggle();
	delay(300);
	chassis.moveToPoint(50, -20, 900, { .forwards = false, .minSpeed = 90 }); // move back to drag back ring
	chassis.turnToPoint(15, -55, 650); // drag ring sideways
	chassis.waitUntilDone();
	ringDoinker.toggle();
	delay(260);
	intake.move(127);
	conveyor.move(127);
	chassis.turnToPoint(10, -55, 900); // go to the safe ring stack
	chassis.moveToPose(35, -30, 190, 900, { .lead = 0.15, .maxSpeed = 90 }); // move to the grabbed ring
	chassis.waitUntilDone();
	chassis.moveToPoint(24.5, -51, 1100); // go to the safe ring stack
	delay(400);
	chassis.turnToPoint(65, -63, 900, {.minSpeed = 30, .earlyExitRange = 4}); // turn to corner

	chassis.moveToPoint(65, -63, 1000, {.maxSpeed = 100}); // move to corner
	intake.move(0);
	chassis.moveToPoint(70, -70, 1000, {.maxSpeed = 80});
	intake.move(127);
	delay(200);
	chassis.waitUntilDone();
	chassis.tank(-70, -70);
	delay(800);
	chassis.tank(0, 0);
	delay(300);
	intakeRiser.toggle();
	chassis.moveToPoint(70, -70, 700, {.maxSpeed = 80});
	chassis.waitUntilDone();
	intakeRiser.toggle();
	chassis.tank(-40, -40);
	delay(300);
	chassis.moveToPoint(50, -50, 900, { .forwards = false }); // move back

	// chassis.tank(-100, -100); // backup
	// delay(500);
	// chassis.tank(0, 0);
	// delay(200);
	// chassis.tank(100, 100); // ram for third ring
	// delay(450);
	// chassis.tank(-100, -100); // backup to clear corner
	// chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, 900); // swing away from corner
	// chassis.moveToPoint(40, -64, 900, {.forwards=false}); // move away from corner
	// chassis.waitUntilDone();
	// delay(500);
	ringDoinker.toggle();
	chassis.moveToPoint(64, -55, 900, { .maxSpeed = 75 }); // move into corner
	chassis.turnToHeading(270, 1200, { .direction = AngularDirection::CCW_COUNTERCLOCKWISE }); // clear ring stack
	chassis.waitUntilDone();
	ringDoinker.toggle(); // bring ring doinker back up
	delay(300);
	chassis.moveToPoint(65, -65, 900, { .forwards = false }); // push mogo into corner
	chassis.waitUntilDone();
	mogoclamp.toggle(); // release mogo


	// chassis.moveToPoint(62, -23, 900, {.minSpeed=60}); // move to grab preload
	// chassis.waitUntilDone();
	// delay(100);





	// chassis.moveToPoint(58, -30, 900); // move back away from corner
	// chassis.moveToPoint(58, -30, 900, {.forwards=false}); // move back away from corner
	// clawDoinker.toggle(); // bring claw down to clear
	// chassis.moveToPoint(66, -60, 900, {.maxSpeed=60}); // move to the safe ring stack
	// chassis.turnToHeading(270, 900); // clear ring stack
	// chassis.waitUntilDone();
	// clawDoinker.toggle(); // bring claw back up





}

inline void worldsSoloAWP() {
	chassis.setPose(-54, 13.5, 270);
	chassis.swingToHeading(215, lemlib::DriveSide::LEFT, 900); // swing to alliance stake
	//alliance
	chassis.waitUntil(8);
	ladybrownMotor.move(127);
	delay(900);
	chassis.moveToPose(-26, 24.3, 280, 1200, { .forwards = false, .maxSpeed=90, .minSpeed = 40}); // move to grab mogo
	chassis.waitUntil(9);
	ladybrownMotor.move(-127);
	approachAndClampMogo();
	intake.move(127);
	conveyor.move(127);
	chassis.moveToPoint(-25.4, 47, 900, { .minSpeed = 90 , .earlyExitRange=2}); // move to grab rings
	// chassis.turnToPoint(-47, 30, 900, { .minSpeed = 80, .earlyExitRange = 5 }); // turn to rings
	chassis.moveToPose(-45, 29, 180, 900, {.minSpeed=120, .earlyExitRange=5}); // move to upside down rings intermediate
	ladybrownMotor.move(0); // stop lb
	chassis.moveToPose(-49.5, 2, 180, 1500, { .lead = 0.2 , .maxSpeed=60 }); // move to upside down rings
	intakeRiser.toggle();
	chassis.waitUntil(16);
	mogoclamp.toggle(); // release mogo


	// intakeRiser.toggle(); // raise intake
	// conveyor.move(0);
	// chassis.waitUntilDone();
	// delay(200);
	// intakeRiser.toggle(); // lower intake
	// conveyor.move(127);
	// delay(600);
	// conveyor.move(0);
	chassis.waitUntilDone();
	delay(300);
	intakeRiser.toggle();
	// chassis.moveToPoint(-49.5, -3, 600, {.maxSpeed = 70, .minSpeed = 30, .earlyExitRange = 1}); // move past upside down rings
	conveyor.move(0);
	chassis.moveToPoint(-49.5, -9, 600, {.minSpeed = 120});
	
	// chassis.waitUntil(8);
	// conveyor.move(0); // stop conveyor
	// intakeRiser.toggle();



	chassis.turnToPoint(-32.5, -21, 900, { .forwards = false , .minSpeed=30, .earlyExitRange=5}); // turn to mogo
	chassis.moveToPose(-32.5, -21, 300, 1000, {.forwards = false , .lead=0.2, .minSpeed=90 }); // move mogo

	// chassis.swingToPoint(-24, -24, DriveSide::RIGHT, 900, {.forwards=false, .minSpeed=45, .earlyExitRange=2}); // swing to corner
	// chassis.swingToPoint(-24, -24, DriveSide::LEFT, 900, {.forwards=false, .minSpeed=45, .earlyExitRange=2}); // swing to corner
	// chassis.moveToPose(-32.5, -19, 35, 900, {.forwards=false, .lead=0.2, .minSpeed=80, .earlyExitRange=2}); // move to corner
	
	approachAndClampMogo(); // clamp mogo
	delay(150);
	conveyor.move(127); // start conveyor
	chassis.turnToPoint(-28, -48, 900, { .minSpeed = 80, .earlyExitRange = 5 }); // turn to stack
	chassis.moveToPoint(-28, -48, 1000, {.minSpeed=90, .earlyExitRange=2}); // move to safe ring 

	// Corner grab stuff:
	// chassis.moveToPose(-66, -66, 225, 1000, {.minSpeed = 80, .earlyExitRange=1}); // go into corner
	// chassis.waitUntil(11.5);
	// ladybrownMotor.move(127); // start lb
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-52, -52, 1000, {.forwards = false});
	// ladybrownMotor.move(0); // stop lb
	// ladybrownMotor.brake();
	// delay(700);
	// chassis.moveToPoint(-64, -64, 1500);
	// intakeRiser.toggle();
	// conveyor.move(127);
	// intake.move(127);
	// chassis.moveToPoint(-50, -50, 1000, {.forwards = false});
	// delay(400);
	// intakeRiser.toggle();
	// ladybrownMotor.move(-127);


	chassis.turnToPoint(-21, -21, 900);
	chassis.moveToPose(-21, -21, 45, 900, {.lead=0.2, .maxSpeed=80});
	chassis.waitUntil(12);

	ladybrownMotor.move(127);
	delay(900);
	ladybrownMotor.move(0);



	//move to clamp
	// chassis.swingToHeading(265, lemlib::DriveSide::LEFT, 400);
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-32, 16, 1000, { .forwards = false, .minSpeed = 80, .earlyExitRange = 8 });
	// chassis.waitUntil(5);
	// ladybrownMotor.move(0); //sped lb
	// chassis.waitUntilDone();
	// approachAndClampMogo();

	// // //move to rings top
	// delay(150);
	// chassis.turnToPoint(-26, 32, 600, { .minSpeed = 30, .earlyExitRange = 5 });
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-26, 32, 600, { .minSpeed = 100, .earlyExitRange = 5 });
	// intake.move(127);
	// conveyor.move(127);
	// chassis.waitUntilDone();
	// //corner
	// chassis.turnToPoint(-53, 32, 1000);
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-53, 32, 1000, { .minSpeed = 80, .earlyExitRange = 5 });
	// chassis.waitUntilDone();
	// chassis.turnToPoint(-64, 52, 1000, { .minSpeed = 30, .earlyExitRange = 5 });
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-64, 52, 1000, { .minSpeed = 100, .earlyExitRange = 8 });
	// chassis.waitUntilDone();
	// chassis.tank(100, 100);
	// delay(200);
	// chassis.tank(-100, -100);
	// delay(400);
	// chassis.tank(0, 0);



	// // lemlib::Pose temp = chassis.getPose();
	// // chassis.setPose(-48, 44, temp.theta);
	// chassis.turnToPoint(-52, -50, 800, { .minSpeed = 30, .earlyExitRange = 10 });
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-52, -50, 1000, { .maxSpeed = 70, .minSpeed = 50, .earlyExitRange = 5 });
	// chassis.waitUntilDone();
	// mogoclamp.toggle();
	// delay(1500);
	// conveyor.move(0);
	// chassis.turnToHeading(290, 1000, { .minSpeed = 30, .earlyExitRange = 10 });
	// // temp = chassis.getPose();
	// // chassis.setPose(-45, -6, temp.theta);
	// //chassis.turnToPoint(-30,-46,1000, {.minSpeed = 30, .earlyExitRange = 5});
	// //chassis.waitUntilDone();
	// //chassis.moveToPoint(-30,-46,1000, {.minSpeed = 80, .earlyExitRange = 5}); 
	// chassis.waitUntilDone();

	// // //move to mogo2
	// //chassis.turnToPoint(-22,-31, 1000);
	// //chassis.waitUntilDone();
	// // intake.move(0);
	// chassis.moveToPoint(-30, -20, 1000, { .forwards = false, .minSpeed = 80, .earlyExitRange = 5 });
	// chassis.waitUntilDone();
	// approachAndClampMogo();
	// chassis.turnToPoint(-28, -40, 600);
	// chassis.waitUntilDone();
	// conveyor.move(127);
	// chassis.moveToPoint(-28, -40, 700);
	// chassis.waitUntilDone();
	// chassis.tank(-100, -100);
	// delay(200);
	// chassis.tank(0, 0);
	// chassis.turnToPoint(-14, -10, 600);
	// ladybrownMotor.move(127);
	// chassis.waitUntil(160);
	// ladybrownMotor.move(0);
	// chassis.waitUntilDone();
	// chassis.tank(100, 100);
	// delay(350);
	// chassis.tank(0, 0);
	// intake.move(0);
	// conveyor.move(0);

}


inline void redRingRush() {
	ringDoinker.extend();
	chassis.setPose(-50.165, 62.047, 100);
	chassis.moveToPoint(-20.975, 58.947, 1000, { .minSpeed = 30, .earlyExitRange = 5 }); //move to intermediate point
	chassis.moveToPoint(-11.676, 54.298, 1000); //rush the rings
	intake.move(127);
	conveyor.move(127);
	stopNextRing = true;
	chassis.swingToHeading(270, DriveSide::RIGHT, 1000);
	chassis.moveToPoint(-41.382, 36.216, 1000); //thread the needle
	ringDoinker.retract();
	chassis.turnToPoint(-31.308, 29.499, 1000, { .forwards = false }); //go to grab mogo
	chassis.moveToPoint(-31.308, 29.499, 1000, { .forwards = false }); //go to grab mogo
	approachAndAutoClampMogo(500);
	conveyor.move(127);
	chassis.moveToPoint(-54.298, 51.714, 1500); //move to preload ring that was left beside bot


}

inline void blueRingRush() {
	chassis.setPose(49.5, 29, 285);
	ringDoinker.extend();
	intake.move(127);
	chassis.moveToPoint(9.743, 41, 1200); //rush rings
	delay(500);
	chassis.turnToPoint(14.156, 26.758, 700, {.forwards = false});
	chassis.moveToPoint(14.156, 26.758, 700, {.forwards = false});
	chassis.swingToHeading(300, DriveSide::RIGHT, 400);
	// chassis.moveToPoint(14.78, 39.565, 700, { .forwards = false });
	// chassis.turnToPoint(10.023, 30.791, 700, { .forwards = false, .maxSpeed = 80 });
	// chassis.moveToPose(11.056, 24.591, 300, 1200, { .forwards = false });
	// chassis.turnToHeading(300, 600, {.minSpeed = 20, .earlyExitRange = 10});
	// chassis.moveToPoint(14.78, 28.385, 600, {.forwards = false});
	// chassis.moveToPoint(18.896, 37.585, 600, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1}); //move to intermediate point
	// chassis.turnToPoint(21, 24.789, 600, {.forwards = false}); //move back into mogo
	// chassis.moveToPoint(21, 24.789, 1300, {.forwards = false}); //move back into mogo
	approachAndAutoClampMogo(500); //clamp first mogo
	conveyor.move(127);
	ringDoinker.retract();
	chassis.turnToPoint(21, 53, 1000);
	chassis.moveToPoint(21, 53, 1000, { .maxSpeed = 80 }); //move to double ring stack behind rushed rings
	conveyor.move(0);
	delay(400); //intake ring
	chassis.turnToPoint(59, 59, 800); //move to corner
	chassis.moveToPoint(59, 59, 1500, {.minSpeed = 30, .earlyExitRange = 2}); //move to corner
	conveyor.move(127);
	chassis.turnToHeading(45, 700);
	chassis.waitUntilDone();
	chassis.tank(80, 80);
	intake.move(127);
	delay(500);
	chassis.tank(100, 60);
	delay(500);
	chassis.tank(60, 100);
	delay(500);
	chassis.tank(80, 80);
	delay(500);
	chassis.moveToPoint(51, 51, 1000, { .forwards = false }); //move back out
	intakeRiser.toggle();
	chassis.moveToPoint(59.327, 57.974, 1500); //move back to corner
	chassis.tank(80, 80);
	intake.move(127);
	delay(2000);
	chassis.moveToPoint(53, 53, 1000, { .forwards = false }); //move back out
	intakeRiser.toggle();
	chassis.turnToPoint(54.242, 42.237, 600);
	chassis.moveToPoint(54.242, 42.237, 1000); //move back to ring preload and intake it
}



/**
 * DON'T CALL IN MAIN
 */
inline void redMogoRushSuccessfulMogoClamp() {
	chassis.waitUntilDone();
	conveyor.move(127);


	// chassis.moveToPoint(-14.001, -43.862, 1000, {.forwards = false});
	// chassis.waitUntilDone();
	// delay(600);
	// mogoclamp.retract(); //unclamp first mogo

	chassis.moveToPose(-59.722, -23.455, 0, 2000, {.lead = 5, .minSpeed = 20, .earlyExitRange = 3});
	chassis.waitUntil(38);
	mogoclamp.toggle(); //drop off first mogo
	// chassis.turnToPoint(-51, -9.764, 700, {.minSpeed = 10, .earlyExitRange = 10});
	// chassis.moveToPoint(-51, -9.764, 1500, {.minSpeed = 30, .earlyExitRange = 2}); //go to reversed stack
	// intakeRiser.toggle();
	// chassis.moveToPoint(-46.065, 0.31, 1000, {.maxSpeed = 60}); //grab reversed stack
	// chassis.waitUntil(5);
	// intakeRiser.toggle();
	// conveyor.move(50);
	// stopNextRing = true;
	// delay(400);
	// chassis.turnToPoint(-31.566, -18.03, 1000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 10});
	// chassis.moveToPose(-31.566, -18.03, 300, 1300, {.forwards = false}); //move to second mogo
	chassis.moveToPose(-28.724, -25.279, 235, 2000, {.forwards = false});
	approachAndClampMogo();
	conveyor.move(127);
	chassis.moveToPoint(-52, -61, 2000, {.minSpeed = 100}); //move to corner
	chassis.moveToPose(-66, -76, 223, 1000, {.maxSpeed = 50}); //move to corner
	intake.move(127);
	chassis.moveToPose(-66, -74, 223, 400, {.minSpeed = 100}); //move to corner
	intake.move(127);
	chassis.waitUntilDone();
	chassis.tank(-30, -30);
	delay(200);
	chassis.tank(-50, -50);
	delay(500);
	chassis.tank(0, 0);
	delay(550);
	intakeRiser.toggle();
	chassis.moveToPose(-68, -76, 223, 1000, {.maxSpeed = 55}); //move to corner
	chassis.waitUntilDone();
	intakeRiser.toggle();
	chassis.tank(-70, -70);
	delay(300);
}

/**
 * Setup center tile, right of blue ring, hs far forward, on the start line
 * FOR PROVS
 */
inline void redMogoRush() {
	clawDoinker.extend();
	chassis.setPose(-49.906, -36.887, 110);
	intake.move(127);
	chassis.moveToPoint(-17.875, -47.8, 1500, { .minSpeed = 127 }); //rush mogo
	reactiveClawClampOn = true;
	chassis.moveToPoint(-34.407, -42.57, 2000, { .forwards = false, .minSpeed = 127 });
	claw.extend();
	reactiveClawClampOn = false;
	chassis.waitUntil(20);
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(800);
	chassis.turnToPoint(-18.935, -41, 1200, { .forwards = false}); //turn to the rushed mogo
	chassis.moveToPoint(-18.935, -41, 1200, { .forwards = false, .maxSpeed = 100 });
	chassis.waitUntilDone();
	chassis.tank(0, -100);
	delay(150);
	approachAndAutoClampMogo(80, 400); //clamp the rushed mogo
	delay(400);
	if (mogo_distance.get_distance() < 15) { //we have clamped mogo
		redMogoRushSuccessfulMogoClamp();
	} else { //misses mogo
		mogoclamp.retract();
		delay(200);
		chassis.turnToPoint(-19.5, -35.5, 1000, { .forwards = false }); //go to second mogo
		intake.move(0);
		conveyor.move(0);
		chassis.moveToPoint(-19.5, -35.5, 1000, { .forwards = false });
		chassis.waitUntilDone();
		chassis.tank(0, -100);
		delay(200);
		// chassis.moveToPose(-24, -34, 180, 1000, {.forwards = false});
		approachAndAutoClampMogo(500);
		conveyor.move(127);
		delay(300);
		// chassis.turnToPoint(-40, -10.314, 700);
		// intakeRiser.toggle();
		// chassis.moveToPoint(-40, -10.314, 1500, {.minSpeed = 30, .earlyExitRange = 3}); //go to reversed stack
		// intake.move(127);
		// chassis.moveToPoint(-51, 3.118, 1000, {.maxSpeed = 50}); //grab reversed stack
		// chassis.waitUntil(10);
		// intakeRiser.toggle();
		chassis.turnToPoint(-52, -60, 1000);
		chassis.moveToPose(-50, -58, 223, 1500); //move to corner
		chassis.moveToPose(-64, -72, 223, 1500, {.maxSpeed = 50}); //move to corner
		intake.move(127);
		chassis.moveToPose(-64, -72, 223, 1500, {.minSpeed = 100}); //move to corner
		intake.move(127);
		chassis.waitUntilDone();
		chassis.tank(-30, -30);
		delay(200);
		chassis.tank(-50, -50);
		delay(500);
		chassis.tank(0, 0);
		delay(550);
		intakeRiser.toggle();
		chassis.moveToPose(-64, -72, 223, 1500, {.lead = 0.1, .maxSpeed = 70}); //move to corner
		chassis.waitUntilDone();
		intakeRiser.toggle();
		chassis.tank(-70, -70);
		delay(500);
	}

}

//score alliance stake -> grab upside down stack -> clamp mogo, get all rings in center, get corner, go to ladder
inline void redRingSideTeammateAWP(){
	chassis.setPose(-54, 13.5, 270);
	chassis.swingToHeading(215, lemlib::DriveSide::LEFT, 900); // swing to alliance stake
	//alliance
	chassis.waitUntil(8);
	ladybrownMotor.move(127);
	delay(800);
	chassis.moveToPoint(-49.84, 23.817, 1500, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //prep to intake upside down rings
	chassis.waitUntil(9);
	ladybrownMotor.move(-127);
	intakeRiser.toggle();
	intake.move(127);
	chassis.turnToPoint(-49.84, 2, 700, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.moveToPoint(-49.84, 2, 1500, {.maxSpeed=60 }); // move to upside down rings
	stopNextRing = true;
	conveyor.move(60);
	chassis.waitUntil(20);
	intakeRiser.toggle();
	delay(200);
	chassis.moveToPose(-34.374, 17.6, 230, 1200, {.forwards = false, .minSpeed = 70}); //go to mogo
	approachAndClampMogo();
	conveyor.move(127);
	delay(100);
	chassis.turnToPoint(-13.484, 35.441, 800); // turn to contested ring stack
	chassis.moveToPoint(-13.484, 35.441, 950); //move to ring stack
	stopNextRing = false;
	delay(300);
	chassis.moveToPoint(-27, 25, 1500, {.forwards=false, .minSpeed=75, .earlyExitRange=5}); // move to intermediate point
	chassis.moveToPoint(-27, 48, 800, {.minSpeed=60, .earlyExitRange=2}); // move to safe
	chassis.turnToPoint(-14, 52, 800, {.minSpeed=40, .earlyExitRange=5}); // turn to 2nd contested ring stack
	chassis.moveToPoint(-14, 52, 1000); //move to second contested ring stack

	chassis.moveToPoint(-50, 52, 900, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // move to intermediate point
	chassis.turnToPoint(-64, 64, 800, {.minSpeed=15, .earlyExitRange=9}); // turn to corner
	chassis.moveToPoint(-64, 64, 1000, {.maxSpeed = 100}); // move to corner
	intake.move(0);
	chassis.moveToPoint(-70, 70, 500, {.maxSpeed = 65});
	intake.move(127);
	delay(200);
	chassis.waitUntilDone();
	chassis.tank(-70, -70);
	delay(500);
	// intakeRiser.toggle();
	// chassis.moveToPoint(-70, 70, 700, {.maxSpeed = 80});
	// chassis.waitUntilDone();
	// intakeRiser.toggle();
	// chassis.tank(-40, -40);
	// delay(500);

	
	
	chassis.turnToPoint(-21.75, 23.3, 700);
	chassis.moveToPose(-21.75, 23.3, 140, 2000, {.lead = 0.2, .minSpeed = 30}); //go to ladder
	chassis.waitUntil(32);
	ladybrownMotor.move(127);
	delay(1000);
	ladybrownMotor.move(0);
	// chassis.moveToPose(-54.456, -57.507, 0, 2000, {.forwards = false}); rush positive corner

}


//score alliance stake -> grab upside down stack -> clamp mogo, get all rings in center, get corner, go to ladder
inline void blueRingSideTeammateAWP(){
	chassis.setPose(54, 13.5, 90);
	chassis.swingToHeading(145, lemlib::DriveSide::RIGHT, 900); // swing to alliance stake
	//alliance
	chassis.waitUntil(8);
	ladybrownMotor.move(127);
	delay(800);
	chassis.moveToPoint(49.84, 23.817, 1500, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3}); //prep to intake upside down rings
	chassis.waitUntil(9);
	ladybrownMotor.move(-127);
	intakeRiser.toggle();
	intake.move(127);
	chassis.turnToPoint(49.84, 2, 700, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.moveToPoint(49.84, 2, 1500, {.maxSpeed=60 }); // move to upside down rings
	stopNextRing = true;
	conveyor.move(60);
	chassis.waitUntil(20);
	intakeRiser.toggle();
	delay(200);
	chassis.moveToPose(34.374, 17.6, 130, 1200, {.forwards = false, .minSpeed = 70}); //go to mogo
	approachAndClampMogo();
	conveyor.move(127);
	delay(100);
	chassis.turnToPoint(13.484, 35.441, 800); // turn to contested ring stack
	chassis.moveToPoint(13.484, 35.441, 950); //move to ring stack
	stopNextRing = false;
	delay(300);
	chassis.moveToPoint(27, 25, 1500, {.forwards=false, .minSpeed=75, .earlyExitRange=5}); // move to intermediate point
	chassis.moveToPoint(27, 48, 800, {.minSpeed=60, .earlyExitRange=2}); // move to safe
	chassis.turnToPoint(14, 52, 800, {.minSpeed=40}); // turn to 2nd contested ring stack
	chassis.moveToPoint(14, 52, 1000); //move to second contested ring stack

	chassis.moveToPoint(50, 52, 900, {.forwards=false, .minSpeed=40, .earlyExitRange=5}); // move to intermediate point
	chassis.turnToPoint(64, 64, 800, {.minSpeed=15, .earlyExitRange=9}); // turn to corner
	chassis.moveToPoint(64, 64, 1000, {.maxSpeed = 100}); // move to corner
	intake.move(0);
	chassis.moveToPoint(70, 70, 500, {.maxSpeed = 65});
	intake.move(127);
	delay(200);
	chassis.waitUntilDone();
	chassis.tank(-70, -70);
	delay(500);
	// intakeRiser.toggle();
	// chassis.moveToPoint(-70, 70, 700, {.maxSpeed = 80});
	// chassis.waitUntilDone();
	// intakeRiser.toggle();
	// chassis.tank(-40, -40);
	// delay(500);

	
	
	chassis.turnToPoint(21.75, 23.3, 700);
	chassis.moveToPose(21.75, 23.3, 220, 2000, {.lead = 0.2, .minSpeed = 30}); //go to ladder
	chassis.waitUntil(32);
	ladybrownMotor.move(127);
	delay(1000);
	ladybrownMotor.move(0);
	// chassis.moveToPose(-54.456, -57.507, 0, 2000, {.forwards = false}); rush positive corner

}



