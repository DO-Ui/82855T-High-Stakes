#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({4, 5, -6}, v5::MotorGears::blue, v5::MotorUnits::rotations);
MotorGroup left({-1, 2, -3}, v5::MotorGears::blue, v5::MotorUnits::rotations);



Motor intake(16, v5::MotorGears::rpm_200);
Motor conveyor(-17, v5::MotorGears::blue);
Motor ladybrownMotor(14, v5::MotorGears::rpm_200);
Imu imu(7);

Rotation horizontal_tracker(-9);
Rotation vertical_tracker(8);
Rotation ladybrownSensor(19);

Optical colour_sensor(20);
Distance distance_sensor(18);
Distance final_distance_sensor(21);
// GPS gps_sensor(13);


adi::Pneumatics mogoclamp('a', false);
adi::Pneumatics doinker('b', false);
adi::Pneumatics intakeRiser('c', false);
adi::Pneumatics hang('d', false);

lemlib::PID ladybrownPID(4, // kP
                0, // kI
                8, // kD`
                5, // integral anti windup range
                false); // don't reset integral when sign of error flips

ArmController ladybrownController(
    0.5, // Kcos
    ladybrownPID
);

lemlib::Drivetrain drivetrain(&left, &right, 12, lemlib::Omniwheel::NEW_275, 450, 2);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::NEW_2, -0.925);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_2, 1);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(18.5, 0, 250, 3, 1, 100, 3, 500, 25);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(7.2, 0, 71.3, 0, 2, 65, 3, 115, 30);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);