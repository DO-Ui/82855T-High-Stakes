#pragma once
// #define leftDistanceXOffset -6
// #define leftDistanceYOffset -0.25
// #define backDistanceXOffset -5.25
// #define backDistanceYOffset -1.5
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
 * Backs up and uses auto clamp to clamp
 * @param motorPower desired speed of motors when moving back
 * @param timeout timeout in milliseconds
*/
void approachAndAutoClampMogo(int motorPower, int timeout) {
	chassis.waitUntilDone();
	chassis.tank(-motorPower, -motorPower);
	mogoClampRequested = true;
	int start = millis();
	while (millis() <= start+timeout) {
		if (!mogoClampRequested) {
			chassis.tank(0, 0);
			mogoClampRequested = false;
			return;
		}
		delay(10);
	}
	chassis.tank(0, 0);
	mogoClampRequested = false;
	mogoclamp.extend();
}

/**
 * Backs up and uses auto clamp to clamp (default speed of -100)
 * @param timeout timeout in milliseconds
*/
void approachAndAutoClampMogo(int timeout) {
	approachAndAutoClampMogo(100, timeout);
}


/**
 * Slowly backs up and clamps onto mogo using chassis.tank();
 * Motor speed is defaulted to -100
 */
void approachAndClampMogo(){
	chassis.waitUntilDone();
	chassis.tank(-100, -100);
	delay(300);
	chassis.tank(0, 0);
	mogoclamp.toggle(); //clamp mogo
}
