#pragma once

/**
 * Slowly backs up and clamps onto mogo using chassis.tank();
 * @param motorPower desired speed of motors when moving back
 */
void approachAndClampMogo(int motorPower){
	chassis.waitUntilDone();
	chassis.tank(-motorPower, -motorPower);
	delay(500);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp mogo
}

/**
 * Slowly backs up and clamps onto mogo using chassis.tank();
 * Motor speed is defaulted to -60
 */
void approachAndClampMogo(){
	chassis.waitUntilDone();
	chassis.tank(-60, -60);
	delay(450);
	chassis.tank(0, 0);
	mogoclamp.extend(); //clamp mogo
}