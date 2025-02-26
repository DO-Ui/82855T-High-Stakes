#pragma once
#define leftDistanceXOffset -6
#define leftDistanceYOffset 0.25
#define backDistanceXOffset 5.25
#define backDistanceYOffset -1.5
#define backHypo sqrt(pow(backDistanceYOffset, 2) + pow(backDistanceXOffset, 2));
const float backDistanceOffsetAngle = lemlib::radToDeg(atan(abs(backDistanceXOffset/backDistanceYOffset)));

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

inline float check_distance_back_BOTTOM_WALL(){
	float currTheta = chassis.getPose().theta;
	float theta = 0;
	if(currTheta > 270){
		theta = 360 - currTheta;
	}
	else {
		theta = currTheta;
	}

	float d = (float)back_distance.get()*0.0393701; //mm to inch conversion
	float wallToDistance = cos(lemlib::degToRad(theta))*d;
	float finalAngleThing = 90 - theta - backDistanceOffsetAngle;
	float distanceSensorOffset = sin(lemlib::degToRad(finalAngleThing)) * backHypo;
	lcd::print(4, "distanceSensorOffset %f", distanceSensorOffset);
	lcd::print(5, "wallToDistanceSensor %f", wallToDistance);
	lcd::print(6, "finalAngleThing %f", finalAngleThing);
	return distanceSensorOffset + wallToDistance;
}

void check_distance_back(){

}