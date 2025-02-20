#include <math.h>
#include "lemlib/api.hpp"

/// @brief A PIDF Controller for an armf
class ArmController {

    public:
        ArmController(double Kcos, const lemlib::PID& ArmPID) : Kcos(Kcos), ArmPID(ArmPID) {}

        /// @brief Updates the controller
        /// @param targetTheta The desired angle in DEGREES
        /// @param error The error in the arm
        /// @return The power to the arm
        float update(double targetTheta, double error) {
            return ArmPID.update(error) + (cos(targetTheta*57.2957795131) * Kcos); // Radians to Degrees Conversion Factor
        }

    private:
        double Kcos;
        lemlib::PID ArmPID;

};