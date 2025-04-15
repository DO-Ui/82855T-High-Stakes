#pragma once
#define leftDistanceXOffset -6
#define leftDistanceYOffset -0.25
#define backDistanceXOffset -5.25
#define backDistanceYOffset -1.5
// #define backHypo sqrt(pow(backDistanceYOffset, 2) + pow(backDistanceXOffset, 2));
// #define leftHypo sqrt(pow(leftDistanceYOffset, 2) + pow(leftDistanceXOffset, 2));
// const float backDistanceOffsetAngle = lemlib::radToDeg(atan(abs(backDistanceXOffset/backDistanceYOffset))); //74.0546
// const float leftDistanceOffsetAngle = lemlib::radToDeg(atan(abs(leftDistanceXOffset/leftDistanceYOffset))); 

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
	chassis.tank(-100, -100);
	delay(250);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
}
