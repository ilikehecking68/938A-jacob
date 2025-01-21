#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 127;
const int TURN_SPEED = 110;
const int SWING_SPEED = 127;

///
// Constants
///
void set_pid_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(5, 0, 220);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

void red_left() {
  mogo.set_value(true);

  arm_pid.target_set(arm_loading);
  intake.move(-127);
  pros::delay(100);
  arm_pid.target_set(180);
  pros::delay(100);
  arm_pid.target_set(arm_noninterfere);

  chassis.pid_turn_set(28, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(-17, 120);
  chassis.pid_wait();
  mogo.set_value(false);

  // chassis.pid_turn_set(80, 120);
  // chassis.pid_wait();

  // chassis.pid_drive_set(40, 120);
  // chassis.pid_wait();

  // doinker.set_value(true);

  // doinker the stack

  // chassis.pid_drive_set(30, 120);
  // chassis.pid_wait();

  chassis.pid_turn_set(130, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(12, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(150, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(10, 120);
  chassis.pid_wait();
  
//   chassis.pid_turn_set(-30, 120);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-50, 120);
//   chassis.pid_wait();
 }

void red_right() {
  mogo.set_value(false);

  arm_pid.target_set(arm_loading);
  intake.move(127);

  chassis.pid_drive_set(40, 120);
  chassis.pid_wait();

  arm_pid.target_set(arm_scoring);
  pros::delay(100);
  arm_pid.target_set(arm_noninterfere);

  chassis.pid_turn_set(30, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(-20, 120);
  chassis.pid_wait();

  mogo.set_value(true);

  chassis.pid_turn_set(30, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(15, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(50, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(50, 120);
  chassis.pid_wait();

  //use doinker

  arm_pid.target_set(arm_loading);
  chassis.pid_drive_set(60, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(40, 120);
  chassis.pid_wait();

  arm_pid.target_set(arm_scoring);
  pros::delay(100);
  arm_pid.target_set(arm_noninterfere);

  chassis.pid_drive_set(50, 120);
  chassis.pid_wait();
} 

#define pw chassis.pid_wait
#define pds chassis.pid_drive_set
#define pts chassis.pid_turn_set
void safe_wp(){
    mogo.set_value(true);

    arm_motor.move(100);
    pros::delay(1111);
    //arm_motor.move(-97);
    //arm_sensor.reset_position();
    pds(-4, 127);
    arm_motor.move(-100);
    pw();

    pts(-39, 127);
    pw();

    pds(-39, 100);
    pw();
    mogo.set_value(false);
    pros::delay(222);
    pts(-146, 120);
    pw();
    intake.move(-127);
    pds(22, 127);
    pw();
    pros::delay(22);
    pts(-90, 127);
    pw();
    pds(44, 127);
    pw();
    intake.move(0);
    arm_sensor.reset_position();
}

void blue_four_ring() {
    mogo.set_value(true);

    pds(50, 127);
    pw();
    // doinker out
    intake.move(-127);
    pros::delay(800);
    intake.move(0);

    pds(-10, 127);
    pw();

    pts(55, 127);
    pw();
    // doinker in

    pds(-20, 127);
    pw();

    mogo.set_value(false);
    intake.move(-127);

    pts(75, 127);
    pw();

    pds(20, 127);
    pw();
    intake.move(0);

    pts(180, 127);
    pw();
    intake.move(-127);

    pds(40, 127);
    pw();
}
void red_goal_rush_wp() {
    mogo.set_value(true);

    pds(50.75, 127);
    pw();

    arm_motor.move(100);
    pros::delay(800);
    pds(-30, 127);
    pw();
    arm_motor.move(-100);

    pts(120, 127);
    pw();

    pds(-16, 127);
    pw();

    mogo.set_value(false);
    intake.move(-127);
    pros::delay(500);

    pts(42, 127);
    pw();

    pds(30, 127);
    pw();

    pts(200, 127);
    pw();

    pds(50, 127);
    pw();

    //doinker out
}

//! UNFINISHED
//TODO: FINISH
void auton_skills() {
  mogo.set_value(true);

  //score on alliance stake
  intake.move(-127);
  pros::delay(500);
  intake.move(127);

  chassis.pid_drive_set(10, 127);
  chassis.pid_wait();

  chassis.pid_turn_set(-100, 127);
  chassis.pid_wait();

  intake.move(-127);

  chassis.pid_drive_set(-25, 127);
  chassis.pid_wait();

  //grab first mogo
  mogo.set_value(false);
  pros::delay(100);

  chassis.pid_turn_set(26, 127);
  chassis.pid_wait();

  chassis.pid_drive_set(80, 127);
  chassis.pid_wait();

  chassis.pid_turn_set(140, 120);
  chassis.pid_wait();

  arm_pid.target_set(arm_loading);

  chassis.pid_drive_set(13, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(45, 120);
  chassis.pid_wait();

  arm_pid.target_set(arm_scoring);
  pros::delay(100);
  arm_pid.target_set(arm_noninterfere);
}

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  //red_left();
  //red_solo_awp();
  safe_wp();
  //ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}



///
// Auton selector
///

void add_autons(){
  ez::as::auton_selector.autons_add({
    {"auton red left", red_left},
    {"auton red right", red_right},
    {"auton skills", auton_skills},
  });
}
