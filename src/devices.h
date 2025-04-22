#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({11, 12, 13}, v5::MotorGears::blue, v5::MotorUnits::rotations);
MotorGroup left({-14, -15, -16}, v5::MotorGears::blue, v5::MotorUnits::rotations);



Motor intake(10, v5::MotorGears::rpm_200);
Motor conveyor(18, v5::MotorGears::blue);
Motor ladybrownMotor(17, v5::MotorGears::green, v5::MotorUnits::degrees);
Imu imu(1);

Rotation horizontal_tracker(19);
Rotation vertical_tracker(-20);

Distance mogo_distance(7);

Optical colour_sensor(9);
Distance distance_sensor(8);

Distance left_distance(10);
Distance back_distance(13);
GPS gps_sensor(10);


adi::Pneumatics mogoclamp('a', false);
adi::Pneumatics clawDoinker('b', false);
adi::Pneumatics claw('c', false);
adi::Pneumatics ringDoinker('d', false);
adi::Button clawLimitSwitch('e');
adi::Pneumatics intakeRiser('f', false);

// lemlib::PID ladybrownPID(3, // kP
//                 0, // kI
//                 3, // kD
//                 5, // integral anti windup range
//                 false); // don't reset integral when sign of error flips

// armController ladybrownController(
//     14, // Kcos
//     ladybrownPID
// );

//drivetrain is 12 inches wide and 11.5 inches from back to front, all measured from midwheels
lemlib::Drivetrain drivetrain(&left, &right, 12, lemlib::Omniwheel::NEW_275, 450, 2);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::NEW_275, 1.59448913102);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_275, -1.2087590096);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(18.5, 0, 200, 3, 1, 100, 3, 500, 20);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(7.2, 0, 71.3, 0, 2, 65, 3, 115, 20);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::ExpoDriveCurve steer_curve(1, 10, 1.025);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);