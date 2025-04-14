#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({11, 12, 13}, v5::MotorGears::blue, v5::MotorUnits::rotations);
MotorGroup left({-14, -15, -16}, v5::MotorGears::blue, v5::MotorUnits::rotations);



Motor intake(16, v5::MotorGears::rpm_200);
Motor conveyor(-17, v5::MotorGears::blue);
Motor ladybrownMotor(17, v5::MotorGears::green, v5::MotorUnits::degrees);
Imu imu(7);

Rotation horizontal_tracker(-9);
Rotation vertical_tracker(8);

Optical colour_sensor(20);
Distance distance_sensor(18); //FIRST COLOR DISTANCE SENSOR
Distance final_distance_sensor(21); //COLOR FINAL DISTANCE SENSOR

Distance left_distance(10);
Distance back_distance(13);
GPS gps_sensor(10);


adi::Pneumatics mogoclamp('a', false);
adi::Pneumatics doinker('b', false);
adi::Pneumatics intakeRiser('c', false);
adi::Pneumatics hang('d', false);

lemlib::PID ladybrownPID(3, // kP
                0, // kI
                3, // kD
                5, // integral anti windup range
                false); // don't reset integral when sign of error flips

ArmController ladybrownController(
    14, // Kcos
    ladybrownPID
);

lemlib::Drivetrain drivetrain(&left, &right, 12, lemlib::Omniwheel::NEW_275, 450, 2);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::OLD_275_HALF, -1.5);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_2, -1.25);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(18.5, 0, 200, 3, 1, 100, 3, 500, 1.5);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(7.2, 0, 71.3, 0, 2, 65, 3, 115, 20);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::ExpoDriveCurve steer_curve(1, 10, 1.025);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);

bool stopNextRing = false;

bool unjamLB = false;