#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({-1, -2, -3}, v5::MotorGears::blue, v5::MotorUnits::rotations);
MotorGroup left({4, 5, 6}, v5::MotorGears::blue, v5::MotorUnits::rotations);


Motor ladybrownMotor(8, v5::MotorGears::green, v5::MotorUnits::degrees);
Motor intake(9, v5::MotorGears::rpm_200);
Motor conveyor(10, v5::MotorGears::blue);

adi::Pneumatics claw('a', false);
adi::Pneumatics clawDoinker('b', false);
adi::Pneumatics ringDoinker('c', false);
adi::Pneumatics intakeRiser('d', false);
adi::Pneumatics mogoclamp('e', false);
adi::DigitalIn clawLimitSwitch('g');

lemlib::PID ladybrownPID(3, // kP
                0, // kI
                3, // kD
                5, // integral anti windup range
                false); // don't reset integral when sign of error flips

ArmController ladybrownController(
    14, // Kcos
    ladybrownPID
);

lemlib::Drivetrain drivetrain(&left, &right, 12, lemlib::Omniwheel::NEW_275, 600, 2);

// lemlib::TrackingWheel horizontal_tracking_wheel(nullptr, lemlib::Omniwheel::OLD_275_HALF, -1.5);
// lemlib::TrackingWheel vertical_tracking_wheel(nullptr, lemlib::Omniwheel::NEW_2, -1.25);

lemlib::OdomSensors sensors(nullptr, nullptr, nullptr, nullptr, nullptr);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(18.5, 0, 200, 3, 1, 100, 3, 500, 1.5);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(7.2, 0, 71.3, 0, 2, 65, 3, 115, 20);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::ExpoDriveCurve steer_curve(1, 10, 1.025);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);