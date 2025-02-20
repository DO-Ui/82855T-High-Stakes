#include <math.h>

/// @brief A PIDF Controller for an armf
class ArmController {

    public:
        ArmController(double Kcos, const lemlib::PID& ArmPID) : Kcos(Kcos), ArmPID(ArmPID) {}

        /// @brief Updates the controller
        /// @param currTheta The desired angle in DEGREES
        /// @param error The error in the arm
        /// @return The power to the arm
        float update(double currTheta, double error) {
            return ArmPID.update(error) + (cos((currTheta-18.5)*0.01745329251)) * Kcos; // Radians to Degrees Conversion Factor
        }

    private:
        double Kcos;
        lemlib::PID ArmPID;

};