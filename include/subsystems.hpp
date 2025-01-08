

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

#ifndef PORTS_HPP
#define PORTS_HPP
#include "api.h"
using namespace pros;
using namespace ez;

//example: inline Motor(1);
#define imu_port 15

#define drive_motor_gearset MotorGears::blue
#define drive_motor_encoder_unit MotorE
#define drive_left_ports -11, -12, 13
#define drive_right_ports 18, 19, -20
#define drive_track_width 12.75 /*measurement of right side to left side in inches*/
#define drive_wheel_diameter 2.75 /*drivetrain wheel diameter(should be same) in inches*/
#define drive_rpm 600 /*wheel rpm*/

#define arm_loading_high 19/*top loading position*/
#define arm_loading 29/*bottom loading position*/
#define arm_noninterfere 0 /*lowest position(should be 0)*/
#define arm_scoring 150 /*scoring position*/

#define get_arm_sensor_degrees()((double)((arm_sensor).get_position() / 100))
#define arm_move_to_position(target) arm_motor.move(arm_pid.update((target) - get_arm_sensor_degrees()))
#define mogo mogo_clamp
inline pros::Motor intake(1, pros::MotorGears::blue, pros::MotorEncoderUnits::degrees);
inline pros::ADIDigitalOut mogo_clamp(4, false);
inline pros::ADIDigitalOut doinker(1, false);
inline pros::Motor arm_motor(-16, pros::MotorGears::green, pros::MotorEncoderUnits::degrees);
inline pros::Rotation arm_sensor(4);
inline PID arm_pid(2.5, 0, 0, 0, "Arm pid");


inline ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {drive_left_ports},     // Left Chassis Ports (negative port will reverse it!)
    {drive_right_ports},  // Right Chassis Ports (negative port will reverse it!)

    imu_port,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

#endif