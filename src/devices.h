#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({3, 4, 5}, MotorGears::blue);
MotorGroup left({-1, -8, -10}, MotorGears::blue);



Motor intake(20, MotorGears::green);
Motor conveyor(6, MotorGears::green);
Imu imu(19);

Rotation horizontal_tracker(-16); // 3.75 inches back
Rotation vertical_tracker(18); // 1.25in to left


adi::Pneumatics mogoclamp('a', false);
adi::Pneumatics wallmech('b', false);

lemlib::Drivetrain drivetrain(&left, &right, 11.5, lemlib::Omniwheel::NEW_325, 450, 8);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::OLD_275_HALF, -3.75);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::OLD_275_HALF, -1.25);

lemlib::OdomSensors sensors(nullptr, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(9, 0.2, 85, 4, 1, 500, 3, 750, 5);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(6.3, 0, 64, 3, 1, 100, 3, 500, 0);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);