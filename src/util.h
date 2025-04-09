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
bool coordinateWithinBounds(float coordX, float coordY, float x1, float y1, float x2, float y2){
	if(x1 <= coordX && coordX <= x2 && y1 <= coordY && coordY <= y2) return true;
	else return false;
}