
/// @brief A PIDF Controller for an armf
class armController {

    public:
        armController(const lemlib::PID& ArmPID) : Kcos(Kcos), ArmPID(ArmPID) {}

        /// @brief Updates the controller
        /// @param currTheta The desired angle in DEGREES
        /// @param error The error in the arm
        /// @return The power to the arm
        float update(double currTheta, double error) {
            return ArmPID.update(error) + LB_STABILIZER; // Radians to Degrees Conversion Factor
        }

    private:
        double Kcos;
        lemlib::PID ArmPID;

};