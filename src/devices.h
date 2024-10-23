#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({1, 8, 10}, MotorGearset::blue);
MotorGroup left({-11, -16, -20}, MotorGearset::blue);

Motor intake(20, MotorGears::blue);
Motor conveyor(6, MotorGears::blue);
adi::Pneumatics clamp('a', false);

lemlib::Drivetrain drivetrain(&left, &right, 11.5, lemlib::Omniwheel::NEW_325, 360, 2);
lemlib::ControllerSettings lateral_controller(10, 0, 3, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(4, 0, 40, 3, 1, 100, 3, 500, 0);
lemlib::OdomSensors sensors(nullptr, nullptr, nullptr, nullptr, nullptr);
lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.019);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);
