#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({3, 4, 5}, MotorGearset::blue);
MotorGroup left({-1, -8, -10}, MotorGearset::blue);

Motor intake(20, MotorGears::green);
Motor conveyor(6, MotorGears::green);
Imu imu(19);

Rotation horizontal_tracker(16); // 3.5 inches back
Rotation vertical_tracker(18); // 1.15in to left


adi::Pneumatics mogoclamp('a', false);
adi::Pneumatics wallmech('b', false);

lemlib::Drivetrain drivetrain(&left, &right, 11.49, lemlib::Omniwheel::NEW_325, 450, 2);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::OLD_275_HALF, -3.5);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::OLD_275_HALF, -1.15);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

int lateral_kP = 30;
int lateral_kD = 180;

lemlib::ControllerSettings lateral_controller(lateral_kP, 0, lateral_kD, 3, 1, 100, 3, 500, 20);

int angular_kP = 2;
int angular_kD = 10;

lemlib::ControllerSettings angular_controller(2, 0, 10, 3, 1, 100, 3, 500, 0);

lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.019);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);

pros::Serial serial (11, 9600);