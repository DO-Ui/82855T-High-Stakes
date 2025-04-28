#pragma once 


/**
 *
 * @brief Rounds a float to 2 decimal places
 *
 * @param num The number to round
 * @return float The rounded number
 */
float round2dp(float num) {
	return std::ceil(num * 100.0) / 100.0;
}

// float conveyor_start_time = 0;
// bool conveyor_powered = false;

bool in_range(double value, double bottom, double top) {
	return (value >= bottom) && (value <= top);
}

/**
 * checks if a given point is located within the rectangle defined by the lower left corner x1, y1, and the upper right corner x2, y2
 * input the x, y coordinates of the point first, then x1, y1, x2, y2
 */
bool coordinateWithinRectangle(float coordX, float coordY, float x1, float y1, float x2, float y2) {
	if (x1 <= coordX && coordX <= x2 && y1 <= coordY && coordY <= y2) return true;
	else return false;
}


/**
 * given the current arm angle, returns the closest position in the positions[] array to that arm angle
 * @findPositionBehind whether to return the closest position behind or in front of the current angle  
 */
int find_closest_LBPosition(float lbArmAngle, bool findPositionBehind){
    if(lbArmAngle > 340 || lbArmAngle < 0) lbArmAngle = 1; //if the angle is slightly past hard stop, making it do a full rotation over to 359.99 degrees, this accounts for that case
    if(lbArmAngle > positions[sizeof(positions)/sizeof(positions[0])-1]) return sizeof(positions)/sizeof(positions[0])-1; //arm is greater than the maximum target angle, so return the max target angle
    for(int i = 0; i < sizeof(positions)/sizeof(positions[0])-1; i++){
        float lowerBound = positions[i];
        float upperBound = positions[i+1];
        if(lowerBound <= lbArmAngle && lbArmAngle < upperBound){
            if(findPositionBehind) return i;
            else return i+1;
        }
    }
    return -1;
}

// void find_tracking_center(uint32_t time){
// 	chassis.setPose(0, 0, 0);
// 	unsigned long n = 0;
// 	float heading;

// 	std::cout << std::fixed << "\033[1mCopy this:\033[0m\n\\left[";
// 	right.move(-100);
// 	left.move(100);

// 	std::ostringstream out;

// 	delay(1500);

// 	auto end_time = time + millis();

// 	int i = 0;

// 	while(millis() < end_time && i++ < 10000){
// 		std::cout << "\\left(" << chassis.getPose().x << "," << chassis.getPose().y << "\\right),";
// 		if(i % 50 == 0){
// 			std::cout.flush();
// 		}
// 		delay(20);
// 	}
// 	right.move(0);
// 	left.move(0);

// 	std::cout << "\b\\right]" << std::endl;
// }


// /**
//  * THETA IS ANGLE IN RADIANS
//  * Everything else in inches
//  * If the output is negative, that means the sensor is behind the tracking sensor
//  */
// inline float calculateSensorOffsetY(float theta, float xOffset, float yOffset){
// 	float yComponentXOffset = xOffset * cos(theta);
// 	float yComponentYOffset = yOffset * cos(theta+M_PI/2);
// 	return yComponentYOffset+yComponentXOffset;
// }

// /**
//  * THETA IS ANGLE IN RADIANS
//  * Everything else in inches
//  * If the output is negative, that means the sensor is to the left of the tracking sensor
//  */
// inline float calculateSensorOffsetX(float theta, float xOffset, float yOffset){
// 	float xComponentXOffset = xOffset * sin(theta);
// 	float xComponentYOffset = yOffset * sin(theta+M_PI/2);
// 	return xComponentYOffset+xComponentXOffset;
// }


// /**
//  * Bottom wall on Jerryio
//  * Make sure the bot is at an angle from 270-90 deg
//  */
// inline float check_distance_back_BOTTOM_WALL(){
// 	float currTheta = chassis.getPose().theta;
// 	currTheta = lemlib::sanitizeAngle(currTheta);
// 	float theta = 0;
// 	if(currTheta > 270){
// 		theta = 360 - currTheta; 
// 	}
// 	else {
// 		theta = currTheta;
// 	}
// 	float d = (float)back_distance.get()*0.0393701; //mm to inch conversion
// 	float wallToDistance = cos(lemlib::degToRad(theta))*d;
// 	float distanceSensorOffset = calculateSensorOffsetY(lemlib::degToRad(currTheta), backDistanceXOffset, backDistanceYOffset);
// 	lcd::print(3, "LastDistanceCalcResultBACKWALL %f", distanceSensorOffset + wallToDistance);
// 	lcd::print(4, "distanceSensorOffset %f", distanceSensorOffset);
// 	lcd::print(5, "wallToDistanceSensor %f", wallToDistance);
// 	lcd::print(6, "theta %f", theta);
// 	return distanceSensorOffset + wallToDistance;
// }

// /**
//  * Right wall on Jerryio
//  * Make sure the bot is at an angle from 90 to 270 deg
//  */
// inline float check_distance_left_RIGHT_WALL(){
// 	bool rotatedLeft = false;
// 	float currTheta = chassis.getPose().theta;
// 	if(currTheta < 180) rotatedLeft = true;
// 	float theta = abs(180-currTheta);

// 	float d = (float)left_distance.get()*0.0393701; //mm to inch conversion
// 	float wallToDistance = cos(lemlib::degToRad(theta))*d;
// 	float distanceSensorOffset = calculateSensorOffsetX(lemlib::degToRad(currTheta), leftDistanceXOffset, leftDistanceYOffset);
// 	lcd::print(3, "LastDistanceCalcResultRIGHTWALL %f", distanceSensorOffset + wallToDistance);
// 	lcd::print(4, "distanceSensorOffset %f", distanceSensorOffset);
// 	lcd::print(5, "wallToDistanceSensor %f", wallToDistance);
// 	lcd::print(6, "theta %f", theta);
// 	return distanceSensorOffset + wallToDistance;
// }
