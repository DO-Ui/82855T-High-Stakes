using namespace pros;
/**
 * SAFE TWO MOGOS AWP BLUE SIDE
 */
inline void blueDoubleMogoAWP(){
    chassis.setPose(58, -35, 90); // setPose modified
	chassis.moveToPoint(41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	chassis.turnToPoint(30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(30, -28.5, 120, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1800); // TODO change delay
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.waitUntilDone();
	// delay(500);
	conveyor.move(0);

	mogoclamp.retract(); // release mogo
	chassis.moveToPose(45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
	intake.move(-100);
	conveyor.move(127);
	chassis.moveToPose(45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
	delay(790);
	conveyor.move(0);
	intake.move(0);
	chassis.turnToPoint(30, 15, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(30, 15, 120, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(127);	
	chassis.moveToPoint(23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
	chassis.waitUntilDone();
	conveyor.move(0);
	intake.move(0);


	chassis.setPose(58, -35, 90);
	chassis.moveToPoint(15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
	chassis.turnToPoint(8.5, -41.5, 800, {.forwards=false, .earlyExitRange=10}); // turn toward mogo flat side
	// chassis.moveToPoint(8.5, -42, 2000, {.forwards=false}); // move to mogo
	chassis.moveToPose(8.5, -41.75, 60, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp contested mogo
	delay(400);
	chassis.turnToPoint(25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
	conveyor.move(127); // score preload onto mogo
	chassis.moveToPose(25, -47, 90, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1200);
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.moveToPose(49, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
	delay(500);
	intake.move(127); // make sure blue ring goes away
	delay(1000);
	conveyor.move(0);	
	mogoclamp.retract(); // release the mogo
	chassis.moveToPose(49, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
	intake.move(-100);
	conveyor.move(127);
	chassis.waitUntilDone();
	chassis.moveToPose(49, 8, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
	delay(780);
	conveyor.move(0);
	chassis.moveToPose(32, -23, 60, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	intake.move(-25);
	chassis.waitUntilDone();
	mogoclamp.extend(); // clamp new mogo
	conveyor.move(127); // score ring onto mogo
	delay(1000);
	conveyor.move(0);
	mogoclamp.retract(); // release mogo
	chassis.moveToPose(25, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
	intake.move(0);
}

/**
 * SAFE TWO MOGOS AWP RED SIDE
 */
inline void redDoubleMogoAWP(){
	chassis.setPose(-58, -35, 90); // setPose modified
	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1800); // TODO change delay
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.waitUntilDone();
	chassis.turnToPoint(-45, -10.5, 1000, {.earlyExitRange=10}); // turn toward reversed stack intermediate point
	delay(500);
	mogoclamp.retract(); // release mogo
	chassis.moveToPose(-45, -10.5, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=10}); // move to reversed stack intermediate point
	intake.move(-100);
	conveyor.move(127);
	chassis.moveToPose(-45, 2, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 55}); // intake the stack and toss the first ring
	delay(790);
	conveyor.move(0);
	intake.move(0);
	chassis.turnToPoint(-30, 15, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(-30, 15, 240, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=5}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(127);	
	chassis.moveToPoint(-23.6, 2, 1000, {.maxSpeed=60}); // Move to ladder
	chassis.waitUntilDone();
	conveyor.move(0);
	intake.move(0);
}

/**
 * MOGO RUSH SOLO AWP RED SIDE
 */
inline void redMogoRushSoloAWP(){
	chassis.setPose(-58, -35, 270);
	chassis.moveToPoint(-15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
	chassis.turnToPoint(-8.5, -41.5, 800, {.forwards=false, .earlyExitRange=10}); // turn toward mogo flat side
	// chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
	chassis.moveToPose(-8.5, -41.75, 300, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp contested mogo
	delay(400);
	chassis.turnToPoint(-25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
	conveyor.move(127); // score preload onto mogo
	chassis.moveToPose(-25, -47, 270, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1200);
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.moveToPose(-52, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
	delay(500);
	intake.move(127); // make sure blue ring goes away
	delay(1000);
	conveyor.move(0);	
	mogoclamp.retract(); // release the mogo
	chassis.moveToPose(-52, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
	intake.move(-100);
	conveyor.move(127);
	chassis.waitUntilDone();
	chassis.moveToPose(-52, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
	delay(780);
	conveyor.move(0);
	chassis.moveToPose(-32, -23, 300, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	intake.move(-25);
	chassis.waitUntilDone();
	mogoclamp.extend(); // clamp new mogo
	conveyor.move(127); // score ring onto mogo
	delay(1000);
	conveyor.move(0);
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPose(-30, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
	intake.move(0);
}

/**
 * MOGO RUSH SOLO AWP BLUE SIDE
 */
inline void blueMogoRushSoloAWP(){
	chassis.setPose(59, -35, 90);
	chassis.moveToPoint(15, -36.7, 1000, {.forwards=false, .earlyExitRange=1.5}); // Move to intermediate point
	chassis.turnToPoint(8.5, -41.5, 800, {.forwards=false, .earlyExitRange=5}); // turn toward mogo flat side
	// chassis.moveToPoint(-8.5, -42, 2000, {.forwards=false}); // move to mogo
	chassis.moveToPose(8.5, -41.5, 60, 1000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .maxSpeed = 75}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp contested mogo
	delay(400);
	chassis.turnToPoint(25, -47, 1000, {.earlyExitRange = 5}); // turn toward ring stack
	conveyor.move(127); // score preload onto mogo
	chassis.moveToPose(25, -47, 90, 3500, {.horizontalDrift = 8, .lead = 0.3}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1200);
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.moveToPose(50, -20, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to intermediate point
	delay(500);
	intake.move(127); // make sure blue ring goes away
	delay(1000);
	conveyor.move(0);	
	mogoclamp.retract(); // release the mogo
	chassis.moveToPose(50, -7.5, 0, 1500, {.horizontalDrift = 8, .lead = 0.5, .earlyExitRange=4}); // move to reversed stack	
	intake.move(-100);
	conveyor.move(127);
	chassis.waitUntilDone();
	chassis.moveToPose(50, 7, 0, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed = 50}); // intake the stack and toss the first ring
	delay(780);
	conveyor.move(0);
	chassis.moveToPose(32, -22, 60, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	intake.move(-25);
	chassis.waitUntilDone();
	mogoclamp.extend(); // clamp new mogo
	conveyor.move(127); // score ring onto mogo
	delay(1000);
	conveyor.move(0);
	// mogoclamp.retract(); // release mogo
	// chassis.moveToPose(-30, -5, 0, 3000, {.horizontalDrift = 8, .lead = 0.5}); // move to ladder
	intake.move(0);
}

/**
 * SAFE TWO MOGOS AWP
 */
inline void redTwoMogosAWP(){
	chassis.setPose(-58, -35, 270);
	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1800); // TODO change delay
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(0);

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
 * TEAMMATE AWP RIGHT SIDE RED
 */

inline void redRightTeammateAWP(){
	chassis.setPose(-58, -35, 270);
	chassis.moveToPoint(-41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	chassis.turnToPoint(-30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(-30, -28.5, 240, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(-23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(-23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1800);
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.waitUntilDone();
	mogoclamp.retract(); // release mogo
	chassis.moveToPoint(-23.6, -2.5, 10000, {.maxSpeed=80}); // Move to ladder
	chassis.waitUntilDone();
	conveyor.move(0);
	intake.move(0);
	chassis.tank(30, 30);
	delay(2000);
	chassis.tank(0, 0);
}


/**
 * TEAMMATE AWP LEFT SIDE BLUE
 */
inline void blueLeftTeammateAWP(){
	chassis.setPose(58, -35, 90); // setPose modified
	chassis.moveToPoint(41.258, -35, 1000, {.forwards=false, .earlyExitRange=5}); // Move to intermediate point
	chassis.turnToPoint(30, -28.5, 800, {.forwards=false}); // turn toward mogo flat side
	chassis.moveToPose(30, -28.5, 120, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5, .earlyExitRange=3}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(23.6, -47.6, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(23.6, -47.6, 180, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1800);
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.waitUntilDone();
	mogoclamp.retract(); // release mogo
	chassis.moveToPoint(23.6, -2.5, 10000, {.maxSpeed=80}); // Move to ladder
	chassis.waitUntilDone();
	conveyor.move(0);
	intake.move(0);
	chassis.tank(30, 30);
	delay(2000);
	chassis.tank(0, 0);
}

/**
 * ELIMS RED LEFT SIDE (Unfinished)
 */
inline void redLeftElims(){
	chassis.setPose(-58.5, 48, 270);
	chassis.turnToPoint(-32, 28.7, 1500, {.forwards=false, .earlyExitRange=5}); // turn toward mogo flat side
	chassis.moveToPose(-32, 28.7, 300, 2000, {.forwards=false, .horizontalDrift = 8, .lead = 0.5}); // move to mogo
	chassis.waitUntilDone();
	delay(100);
	mogoclamp.extend(); // clamp mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(-23.5, 47, 1000, {.earlyExitRange=10}); // turn toward ring stack
	chassis.moveToPose(-23.5, 47, 43, 2000, {.horizontalDrift = 8, .lead = 0.5}); // move into ring stack
	intake.move(-127); // start intaking bottom ring of stack
	delay(1100);
	intake.move(127); // ensure the blue isn't intaken
	chassis.moveToPoint(-9, 60, 1000, {.earlyExitRange=5}); // move to intermediate point
	chassis.moveToPose(-4, 37, 180, 2000, {.horizontalDrift = 8, .lead = 0.5, .maxSpeed=80}); // move into double ring stack
	intake.move(-127); // start intaking double ring stack
	chassis.waitUntilDone();
	intake.move(0); // stop intake to ensure conveyor grabs
	chassis.moveToPose(-47, 37, 90, 2000, {.horizontalDrift = 8, .lead = 0.2}); // move back
	chassis.waitUntilDone();
	conveyor.move(0);
}

/**
 * SAFE ALLIANCE STAKE BLUE (Unfinished?)
 */
inline void blueAllianceStake(){
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
	chassis.moveToPose(22, 0, 270, 1000, {.maxSpeed=60}); // move to ladder
}

/**
 * SAFE ALLIANCE STAKE RED (Unfinished?)
 */
inline void redAllianceStake(){
	chassis.setPose(-55, -15.65, 0);
	chassis.moveToPose(-55, 0, 0, 1000); // move to alliance stake
	intake.move(127);
	chassis.turnToHeading(90, 1200); // turn toward alliance stake
	chassis.waitUntilDone();
	chassis.setPose(-55, 0, 90);
	intake.move(0);

	chassis.moveToPose(-62, 0, 90, 1000, {.forwards=false, .maxSpeed=60}); // move to alliance stake
	chassis.waitUntilDone();
	conveyor.move(120);
	delay(1000);
	conveyor.move(0);
}

/**
 * SKILLS ROUTE
 * by Grant
 */
inline void skills(){
	//upper left corner
	chassis.setPose(-62, 0, 90); 
	conveyor.move(120); //score on red alliance stake 
	delay(1000);
	chassis.moveToPoint(-47, 0, 1500);	
	chassis.turnToHeading(180, 1000); //turn towards mogo
	chassis.moveToPoint(-47, 24, 2000, {.forwards=false, .earlyExitRange=5}); //move to mogo
	chassis.waitUntilDone();
	mogoclamp.extend(); //clamp mogo
	delay(400);
	chassis.turnToHeading(90, 500); 
	chassis.waitUntilDone();
	intake.move(-127);
	conveyor.move(120);
	chassis.moveToPoint(-24, 24, 2000); //move to first ring
	chassis.moveToPose(-2.132, 56.514, 29, 3000, {.horizontalDrift = 8, .lead = 0.5}); //move to wall stake ring
	chassis.turnToPoint(-23.721, 47.496, 1000); //turn to next ring
	chassis.moveToPoint(-23.721, 47.496, 2000); //move to next ring
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(-54.328, 47.496, 3000); //grab two corner rings
	chassis.moveToPose(-47.496, 58.974, 90, 2000, {.horizontalDrift = 8, .lead = 0.5}); //grab last corner ring
	chassis.turnToHeading(110, 1000);
	chassis.moveToPose(-59.52, 58.427, 140, 2000, {.forwards=false, .earlyExitRange=5}); //drive to corner
	mogoclamp.retract();
	//lower left corner
	chassis.moveToPose(-47, -12.131, 0, 3000); //move to mogo in lower left corner
	chassis.moveToPoint(-47, -24, 1000, {.forwards = false, .earlyExitRange = 5}); //plow mogo a bit
	chassis.waitUntilDone();
	mogoclamp.extend();
	chassis.turnToPoint(-23.672, -23.714, 1000);
	chassis.moveToPoint(-23.672, -23.714, 1000);
	chassis.moveToPose(0.811, -58.991, 180, 2000); //move to middle bottom ring

	chassis.turnToPoint(-6.287, -47.15, 1000);
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(-55.198, -47.15, 270); //pick up three horizontally aligned rings
	// chassis.moveToPose(-17.435, -49.518, 295, 2000); using only moveToPose to grab the three horizontally aligned rings in lower left corner
	// chassis.moveToPose(-59.738, -47.407, 270, 2000);

	chassis.turnToPoint(-47.365, -58.991, 1000);
	chassis.moveToPoint(-47.365, -58.991, 1000); //pick up last ring in corner
	chassis.turnToHeading(70, 1000);
	chassis.moveToPoint(-56.788, -61.543, 1000, {.forwards = false, .earlyExitRange = 5});
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop off mogo in lower left corner
	//lower right corner
	chassis.moveToPose(23.879, -47.111, 75, 3000); //move to first ring on right side
	chassis.waitUntilDone();
	conveyor.move(0); //turn off conveyor to store the ring
	delay(100);
	chassis.moveToPoint(47, -16, 2000); //setup to clamp middle mogo
	chassis.turnToHeading(180, 1000);
	delay(200);
	chassis.moveToPoint(47, -7, 1000, {.forwards = false, .earlyExitRange = 5}); //plow middle mogo
	chassis.waitUntilDone();
	mogoclamp.extend(); //clamp middle mogo
	delay(400);
	conveyor.move(120);
	chassis.turnToPoint(24.746, -22, 1000);
	chassis.moveToPoint(24.746, -22, 1000); //grab ring before going under ladder
	delay(200);
	chassis.turnToPoint(2.496, -2.591, 1000); //grab ring under ladder
	chassis.moveToPoint(2.496, -2.591, 2000);
	chassis.turnToPoint(21.113, 20.567, 1000); 
	chassis.moveToPoint(21.113, 20.567, 1000); //grab first ring in upper right corner
	delay(200);
	chassis.turnToPoint(23.714, 47.102, 1000); //grab the rest of the rings
	chassis.moveToPoint(23.714, 47.102, 1000);
	chassis.turnToHeading(90, 1000);
	chassis.moveToPoint(47.407, 47.102, 1000); 
	delay(300);
	chassis.turnToHeading(45, 1000); //turn to position to intake ring in upper right corner (TODO color sort out)
	chassis.moveToPoint(59.903, 59.247, 1000); //intake ring
	delay(500);
	chassis.moveToPoint(57.443, 55.968, 1000); //go out a bit to have room to turn
	chassis.turnToHeading(225, 1000);
	chassis.moveToPoint(59.254, 58.948, 1000); //move to upper right corner 
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop mogo off
	chassis.turnToHeading(180, 1000);
	chassis.moveToPoint(59.254, 39.59, 1000);
	delay(500);
	chassis.turnToHeading(0, 1000);
	chassis.moveToPoint(59.254, 27.884, 1500, {.forwards = false, .earlyExitRange = 5});
	chassis.waitUntilDone();
	mogoclamp.extend(); //grab upper mogo on right side
	delay(200);
	//lower right corner
	chassis.turnToPoint(32.138, -61.097, 1000);
	chassis.moveToPoint(32.138, -61.097, 1000);
	chassis.turnToHeading(90, 1000);
	chassis.moveToPoint(58.727, -62.15, 1000);
	delay(500);
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(58.727, -62.15, 1000, {.forwards = false, .earlyExitRange = 5});
	chassis.waitUntilDone();
	mogoclamp.retract(); //drop off final mogo in lower right corner
	conveyor.move(0);
	intake.move(0);
}

/**
 * RED 6 RING ELIM
 */
inline void redLeft6RingElim(){
	chassis.setPose(-57.5, 40.539, 270);
	chassis.moveToPose(-31.749, 28.329, 300, 1000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 7}); //move to left mogo
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp left mogo
	delay(100);
	chassis.turnToPoint(-10.219, 40.291, 600);
	chassis.waitUntilDone();
	conveyor.move(120);
	intake.move(-127);
	chassis.moveToPoint(-10.447, 39.294, 1500, {.forwards = true, .minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(-10.447, 39.294, 1500, {.forwards = true, .maxSpeed= 20}); //go to first contested ring
	chassis.moveToPoint(-23.957, 30.871, 1000, {.forwards = false});
	chassis.turnToHeading(0, 1000);
	chassis.moveToPoint(-23.957, 50.759, 1000); //get ring behind contested rings
	chassis.turnToPoint(-9.303, 50.759, 700);
	chassis.moveToPoint(-9.303, 50.759, 1000); //get final contested ring
	chassis.moveToPoint(-43.605, 42.498, 1500, {.forwards = false});
	chassis.turnToHeading(319, 7000);
	doinker.extend();
	chassis.moveToPoint(-57.274, 57.316, 1000);
	//chassis.swingToHeading(110, DriveSide::RIGHT, 1000);
	chassis.turnToHeading(100, 1000, {.minSpeed = 100}); //spin robot to clear rings out of corner
	chassis.turnToPoint(-59.478, 59.529, 1000);
	doinker.retract();
	delay(200);
	chassis.moveToPose(-59.478, 59.529, 319, 1000); //move to left corner to grab lowest ring
	delay(200);
	chassis.moveToPoint(-47, 47, 1000, {.forwards = false});
	chassis.turnToHeading(180, 1000);
	chassis.moveToPoint(-47, -9, 2000);
}

/**
 * Grant's Solo AWP Red Left side
 */
inline void redLeftSoloAWP(){
	chassis.setPose(-54, 14.2, 0);
	chassis.moveToPose(-54, 0, 0, 800, {.forwards = false}); // move to alliance stake
	chassis.turnToHeading(90, 700); // turn toward alliance stake
	chassis.moveToPoint(-60, 0, 700, {.forwards = false});
	chassis.waitUntilDone();
	conveyor.move(127);
	delay(400);
	chassis.moveToPoint(-55, 0, 600);
	chassis.turnToPoint(-32.628, 18.083, 1000, {.forwards=false});
	chassis.moveToPose(-32.628, 18.083, 240, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp left mogo
	delay(100);
	chassis.turnToPoint(-10.219, 40.291, 1000);
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(-10.447, 39.294, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(-10.447, 39.294, 1000, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(-23.957, 30.871, 750, {.forwards = false});
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(-23.957, 50.759, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToPoint(-9.303, 50.759, 750); 
	conveyor.move(0);
	chassis.moveToPoint(-9.303, 50.759, 750); //get final contested ring
	conveyor.move(110);
	chassis.moveToPoint(-20.303, 50.759, 1000, {.forwards = false});
	conveyor.move(0);
	chassis.turnToPoint(-24.605, 4.648, 1000);
	chassis.moveToPose(-24.67, 11.623, 180, 1000);
	conveyor.move(110);
	chassis.waitUntilDone();
	intake.move(0);


	//following code does the original grab mogo -> grab left ring -> clear negative corner
	// chassis.moveToPose(-44.778, 1.198, 60, 1000); //intake red ring
	// chassis.waitUntilDone();
	// intake.move(0);
	// conveyor.move(0); //store red ring in robot
	// chassis.turnToHeading(180, 1000); //begin moving to left mogo
	// chassis.moveToPoint(-43.901, 12.524, 1500, {.forwards = false});
	// chassis.turnToHeading(240, 1000);
	// chassis.moveToPoint(-32.427, 18.926, 2000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 5}); //move to left mogo
	// chassis.moveToPoint(-32.427, 18.926, 2000, {.forwards = false, .maxSpeed = 40}); //move to left mogo
	// chassis.waitUntilDone();
	// mogoclamp.extend(); //clamp left mogo
	// delay(200);
	// chassis.turnToPoint(-22.892, 38.719, 1000);
	// chassis.moveToPose(-22.892, 38.719, 0, 2000); //move to left ring 
	// chassis.waitUntilDone();
	// intake.move(-127);
	// conveyor.move(120);
	// chassis.moveToPoint(-24, 51.659, 1000); //intake ring
	// chassis.moveToPoint(-57.274, 57.316, 3000); //move to corner to get ready to clear it
	// doinker.extend();
	// chassis.turnToHeading(100, 1000, {.minSpeed = 100}); //spin robot to clear rings out of corner
	// chassis.turnToPoint(-59.478, 59.529, 1000);
	// doinker.retract();
	// chassis.moveToPose(-59.478, 59.529, 315, 1000); //move to left corner to grab lowest ring
	// delay(200);
	// chassis.waitUntilDone();
	// intake.move(0);
	// conveyor.move(0);
	// chassis.turnToPoint(-29.051, 8.814, 1000);
	// chassis.moveToPose(-28.701, 9.339, 150, 3000); //move to ladder

}

inline void blueRightSoloAWP(){
	chassis.setPose(54, 14.2, 0);
	chassis.moveToPose(54, -0.17, 0, 800, {.forwards = false}); // move to alliance stake
	chassis.turnToHeading(270, 700); // turn toward alliance stake
	chassis.moveToPoint(61.7, 0.16, 700, {.forwards = false});
	chassis.waitUntilDone();
	conveyor.move(127);
	delay(400);
	chassis.moveToPoint(55, 0, 600);
	chassis.turnToPoint(32.628, 18.083, 1000, {.forwards=false});
	chassis.moveToPose(32.628, 18.083, 120, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp left mogo
	delay(100);
	chassis.turnToPoint(10.219, 40.291, 1000);
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(10.447, 39.294, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(10.447, 39.294, 1000, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(23.957, 30.871, 750, {.forwards = false});
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(23.957, 50.759, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToPoint(9.303, 50.759, 750); 
	conveyor.move(0);
	chassis.moveToPoint(9.303, 50.759, 750); //get final contested ring
	conveyor.move(110);
	chassis.moveToPoint(20.303, 50.759, 1000, {.forwards = false});
	conveyor.move(0);
	chassis.turnToPoint(24.605, 4.648, 1000);
	chassis.moveToPose(24.67, 11.623, 180, 1000);
	conveyor.move(110);
	chassis.waitUntilDone();
	intake.move(0);
}

/**
 * NOT DONE Grant's Solo AWP Red Right side
 */
inline void redRightSoloAWP(){
	chassis.setPose(-55, -15.65, 180);
	chassis.turnToHeading(140, 1000);
	chassis.moveToPoint(-61.813, -8.375, 1000, {.forwards = false}); // move to alliance stake
	chassis.waitUntilDone();
	conveyor.move(120); //score on alliance stake
	delay(500);
	intake.move(-127);
	chassis.turnToPoint(-54.72, -4.389, 1000);
	chassis.moveToPoint(-54.72, -4.389, 1000); //move to middle rings, intake bottom blue ring while ramming red ring forwards
	delay(300);
	chassis.moveToPose(-44.778, 1.198, 60, 1000); //intake red ring
	chassis.waitUntilDone();
	intake.move(0);
	conveyor.move(0); //store red ring in robot
	chassis.turnToHeading(0, 1000); //begin moving to right mogo
	chassis.moveToPoint(-43.901, -12.524, 1500, {.forwards = false});
	chassis.turnToHeading(300, 1000);
	chassis.moveToPoint(-32.427, -18.926, 2000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 5}); //move to right mogo
	chassis.moveToPoint(-32.427, -18.926, 2000, {.forwards = false, .maxSpeed = 40}); //move to right mogo
	chassis.waitUntilDone();
	mogoclamp.extend(); //clamp right mogo
	delay(200);
	chassis.turnToPoint(-22.892, -38.719, 1000);
	chassis.moveToPose(-22.892, -38.719, 0, 2000); //move to right ring 
	chassis.waitUntilDone();
	intake.move(-127);
	conveyor.move(120);
	chassis.moveToPoint(-24, -51.659, 1000); //intake ring
	chassis.moveToPoint(-57.274, -57.316, 3000); //move to corner to get ready to clear it
	doinker.extend();
	chassis.turnToHeading(260, 1000, {.minSpeed = 100}); //spin robot to clear rings out of corner
	chassis.turnToPoint(-59.478, -59.529, 1000);
	doinker.retract();
	chassis.moveToPose(-59.478, -59.529, 225, 1000); //move to right corner to grab lowest ring
	chassis.waitUntilDone();
	delay(200);
	intake.move(0);
	conveyor.move(0);
	chassis.turnToPoint(-29.051, -8.814, 1000);
	chassis.moveToPose(-28.701, -9.339, 30, 3000); //move to ladder
}

/**
 * TESTING RED LEFT SOLO AWP 
 */
inline void redLeftSoloAWPTEST(){
	chassis.setPose(-54, 14.2, 0);
	chassis.moveToPose(-54, 0, 0, 800, {.forwards = false}); // move to alliance stake
	chassis.turnToHeading(90, 700); // turn toward alliance stake
	chassis.moveToPoint(-60, 0, 700, {.forwards = false});
	chassis.waitUntilDone();
	conveyor.move(127);
	delay(400);
	chassis.moveToPoint(-55, 0, 600);
	chassis.turnToPoint(-32.628, 18.083, 1000, {.forwards=false});
	chassis.moveToPose(-32.628, 18.083, 240, 800, {.forwards = false, .minSpeed = 60, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp left mogo
	delay(100);
	chassis.turnToPoint(-10.219, 40.291, 1000);
	conveyor.move(127);
	intake.move(-127);
	chassis.moveToPoint(-10.447, 39.294, 1000, {.minSpeed = 50, .earlyExitRange = 7}); //go to first contested ring
	chassis.moveToPoint(-10.447, 39.294, 1000, {.maxSpeed= 35}); //go to first contested ring
	chassis.moveToPoint(-23.957, 30.871, 750, {.forwards = false});
	conveyor.move(0); // stop conveyor while reversing
	chassis.turnToHeading(0, 800, {.minSpeed = 20, .earlyExitRange = 10});
	chassis.moveToPoint(-23.957, 50.759, 1000); //get ring behind contested rings
	conveyor.move(127);
	chassis.turnToPoint(-9.303, 50.759, 750); 
	conveyor.move(0);
	chassis.moveToPoint(-9.303, 50.759, 750); //get final contested ring
	conveyor.move(110);
	chassis.moveToPoint(-20.303, 50.759, 1000, {.forwards = false});
	conveyor.move(0);
	chassis.turnToPoint(-24.605, 4.648, 1000);
	chassis.moveToPose(-24.67, 11.623, 180, 1000);
	conveyor.move(110);
	chassis.waitUntilDone();
	intake.move(0);
}
