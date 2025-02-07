#pragma once

Controller master(E_CONTROLLER_MASTER);

MotorGroup right({14, -15, 16}, v5::MotorGears::blue, v5::MotorUnits::rotations);
MotorGroup left({11, -12, 13}, v5::MotorGears::blue, v5::MotorUnits::rotations);



Motor intake(10, v5::MotorGears::green);
Motor conveyor(-9, v5::MotorGears::green);
Motor ladybrownMotor(0, v5::MotorGears::green); //UPDATE MOTOR GEAR SET TO CORRECT ONE
Imu imu(12);

Rotation horizontal_tracker(-14); // 3.75 inches back
Rotation vertical_tracker(15); // 1.25in to left
Rotation ladybrownSensor(1); 

Optical colour_sensor(16);
Distance distance_sensor(11);
GPS gps_sensor(13);


adi::Pneumatics mogoclamp1('a', false);
adi::Pneumatics mogoclamp2('b', false);
adi::Pneumatics doinker('c', false);
adi::Pneumatics hang('d', false);

lemlib::PID ladybrownPID(5, // kP
                0, // kI
                20, // kD
                5, // integral anti windup range
                false); // don't reset integral when sign of error flips

lemlib::Drivetrain drivetrain(&left, &right, 11.5, lemlib::Omniwheel::NEW_325, 450, 2);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::NEW_2, -3.75);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_2, -1.25);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
lemlib::ControllerSettings lateral_controller(12, 0, 92, 4, 1, 500, 3, 750, 0);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
lemlib::ControllerSettings angular_controller(6.3, 0, 64, 3, 1, 100, 3, 500, 0);



lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);