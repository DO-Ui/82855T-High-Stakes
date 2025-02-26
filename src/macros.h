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

/**
 * THETA IS ANGLE IN RADIANS
 * Everything else in inches
 * If the output is negative, that means the sensor is behind the tracking sensor
 */
inline float calculateSensorOffsetY(float theta, float xOffset, float yOffset){
	float yComponentXOffset = xOffset * cos(theta);
	float yComponentYOffset = yOffset * cos(theta+M_PI/2);
	return yComponentYOffset+yComponentXOffset;
}

/**
 * THETA IS ANGLE IN RADIANS
 * Everything else in inches
 * If the output is negative, that means the sensor is to the left of the tracking sensor
 */
inline float calculateSensorOffsetX(float theta, float xOffset, float yOffset){
	float xComponentXOffset = xOffset * sin(theta);
	float xComponentYOffset = yOffset * sin(theta+M_PI/2);
	return xComponentYOffset+xComponentXOffset;
}


/**
 * Bottom wall on Jerryio
 * Make sure the bot is at an angle from 270-90 deg
 */
inline float check_distance_back_BOTTOM_WALL(){
	float currTheta = chassis.getPose().theta;
	currTheta = lemlib::sanitizeAngle(currTheta);
	float theta = 0;
	if(currTheta > 270){
		theta = 360 - currTheta; 
	}
	else {
		theta = currTheta;
	}
	float d = (float)back_distance.get()*0.0393701; //mm to inch conversion
	float wallToDistance = cos(lemlib::degToRad(theta))*d;
	float distanceSensorOffset = calculateSensorOffsetY(lemlib::degToRad(currTheta), backDistanceXOffset, backDistanceYOffset);
	lcd::print(3, "LastDistanceCalcResultBACKWALL %f", distanceSensorOffset + wallToDistance);
	lcd::print(4, "distanceSensorOffset %f", distanceSensorOffset);
	lcd::print(5, "wallToDistanceSensor %f", wallToDistance);
	lcd::print(6, "theta %f", theta);
	return distanceSensorOffset + wallToDistance;
}

/**
 * Right wall on Jerryio
 * Make sure the bot is at an angle from 90 to 270 deg
 */
inline float check_distance_left_RIGHT_WALL(){
	bool rotatedLeft = false;
	float currTheta = chassis.getPose().theta;
	if(currTheta < 180) rotatedLeft = true;
	float theta = abs(180-currTheta);

	float d = (float)left_distance.get()*0.0393701; //mm to inch conversion
	float wallToDistance = cos(lemlib::degToRad(theta))*d;
	float distanceSensorOffset = calculateSensorOffsetX(lemlib::degToRad(currTheta), leftDistanceXOffset, leftDistanceYOffset);
	lcd::print(3, "LastDistanceCalcResultRIGHTWALL %f", distanceSensorOffset + wallToDistance);
	lcd::print(4, "distanceSensorOffset %f", distanceSensorOffset);
	lcd::print(5, "wallToDistanceSensor %f", wallToDistance);
	lcd::print(6, "theta %f", theta);
	return distanceSensorOffset + wallToDistance;
}
