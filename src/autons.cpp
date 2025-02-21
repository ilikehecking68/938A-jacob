#include "colorsort.hpp"
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
  // chassis.pid_heading_constants_set(11, 0, 20);
  // chassis.pid_drive_constants_set(20, 0, 100);
  // chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  // chassis.pid_swing_constants_set(6, 0, 65);
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 105);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  // chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_exit_condition_set(1_ms, 4_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(1_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}
#define pw chassis.pid_wait
#define pds chassis.pid_drive_set
#define pts chassis.pid_turn_set

void red_left() {
  mogo.set_value(true);
  arm_motor.move(127);
  pros::delay(750);
  arm_motor.move(0);
  pds(-10,127);
  pw();
  arm_motor.move(-127);
  pros::delay(300);
  arm_motor.move(0);
  pts(-60,127);
  pw();
  pds(-45,80);
  pw();
  pros::delay(300);
  mogo.set_value(false);
  pros::delay(200);
  pts(-159,127);
  pw();
  intake.move(-127);
  pds(23, 100);
  pw();
  pds(-3, 100);
  pw();
  pros::delay(100);
  pts(-230, 100);
  pw();
  pds(10, 90);
  pw();
  pds(-12, 100);
  pw();
  pts(-196, 100);
  pw();
  pds(15, 80);
  pw();
  pts(-100, 90);
  pw();
  pds(80, 120);
  pw();

  //   chassis.pid_turn_set(-30, 120);
  //   chassis.pid_wait();

  //   chassis.pid_drive_set(-50, 120);
  //   chassis.pid_wait();
}

void arm_no_sync_move(double pos) {
  arm_pid.target_set(pos);
  while (arm_pid.exit_condition() != ez::SMALL_EXIT) {
    arm_move_to_set_position();
  }
}

void red_right() {
  mogo.set_value(true);
  pds(30, 127);
  pw();
  pts(-25, 127);
  pw();
  arm_motor.move(80);
  pds(18, 127);
  pw();
  pros::delay(300);
  arm_motor.move(-80);
  pros::delay(200);
  pts(-133, 127);
  pw();
  intake.move(-127);
  pds(8, 127);
  pw();
  pros::delay(20);
  intake.move(0);
  pts(-280, 127);
  pw();
  pds(-27, 127);
  pw();
  mogo.set_value(false);
  pros::delay(100);
  pds(40, 127);
  pw();
  pts(-190, 127);
  pw();
  pds(45, 127);
  pw();
  intake.move(-127);
  pw();
  pds(15, 30);
  pw();
  pds(-15, 30);
  pw();
  pds(15, 30);
  pw();
  pds(-10, 30);
  pw();
  arm_no_sync_move(arm_noninterfere);
}

void skills_v1(){
  intake.move(-127);

  pds(10, 127);
  pw();

  pts(90, 127);
  pw();

  pds(-50, 120, true);
  pw();
  pds(-15, 80, true);
  pw();

  pros::delay(100);

  mogo.set_value(false);

  pros::delay(200);

  pts(-90, 120);
  pw();

  pds(30, 80);
  pw();
}

void red_safe_wp(){
    //USE THIS AUTO
    mogo.set_value(true);

    arm_motor.move(100);
    pros::delay(1420);
    //arm_motor.move(-97);
    //arm_sensor.reset_position();
    arm_motor.move(-32);
    pds(-10, 127);
    pw();
    pts(45, 127);
    pw();
    pds(9.5, 127);
    pw();
    doinker.set_value(true);
    pds(-11.125, 127);
    pw();
    pts(11, 127);
    pw();
    pds(-8, 127);
    pw();
    doinker.set_value(false);
    intake.move(-127);
    chassis.pid_swing_set(LEFT_SWING, 27, 120, 65);
    pw();
    pros::delay(500);
    //chassis.pid_swing_set(LEFT_SWING, -98, 60, 22);
    //pw();
    chassis.pid_swing_set(LEFT_SWING, -98, 60, 13);
    pw();

    pds(-22, 70);
    pw();
    pros::delay(200);
    mogo.set_value(false);
    pros::delay(300);
    chassis.pid_swing_set(RIGHT_SWING, -230, 120, 15);
    pw();
    pds(8, 80);
    pw();
    pros::delay(300);
    pts(35, 100);
    pw();
    pds(50, 100);
    pw();
    arm_motor.move(127);
    /*pros::delay(50);
    pts(-260, 70);
    pw();
    doinker.set_value(true);
    pros::delay(100);
    intake.move(0);
    pds(16, 60);
    pw();
    pts(0, 100);
    pw();
    intake.move(-127);
    pds(20, 100);
    pw();
    pts(90, 80);
    pw();
    pds(40, 90);
    pw();*/

    /*pds(-16, 60);
    pw();
    doinker.set_value(false);
    pds(10, 70);
    pw();

    pts(-120, 100);
    pw();
    pds(-53, 80);
    pw();
    intake.move(-127);*/


    /*pts(-51, 127);
    pw();
    arm_motor.move(-100);
    pts(30, 127);
    pw();
    doinker.set_value(true);

    pds(-39.82, 100);
    pw();
    arm_motor.move(0);
    delay(333);
    mogo.set_value(false);
    pros::delay(222);
    pts(-157, 120);
    pw();
    intake.move(-127);
    pds(24, 127);
    pw();
    pros::delay(22);
    /*pts(-73, 127);
    pw();
    pds(41, 127);
    pw();
    pts(-110, 127);
    pw();
    doinker.set_value(true);
    pts(-126, 127);
    pw();
    delay(690);
    pts(-95, 127);
    pw();
    doinker.set_value(false);    
    pds(12, 127);
    pw();*/
    
    /*intake.move(0);
    mogo.set_value(true);
    pts(-127, 130);
    pw();
    pds(-1000, 127);
    pw();
    arm_sensor.reset_position();*/
}

void red_new_max_score(){
  mogo.set_value(true);

}

void blue_safe_wp() {
  // USE THIS AUTO
  mogo.set_value(true);

  arm_motor.move(100);
  pros::delay(800);
  // arm_motor.move(-97);
  // arm_sensor.reset_position();
  arm_motor.move(-40);
  pros::delay(100);
  pds(-10, 127);
  pw();
  pts(-65, 127);
  pw();
  pds(11, 127);
  pw();
  doinker.set_value(true);
  pros::delay(500);
  pds(-11, 127);
  pw();
  pts(-30, 127);
  pw();
  doinker.set_value(false);
  intake.move(-127);
  pds(15, 127);
  pw();
  pds(-20, 127);
  pw();
  intake.move(0);
  pts(68, 127);
  pw();
  // chassis.pid_swing_set(LEFT_SWING, -98, 60, 22);
  // pw();
  pds(-40, 70);
  pw();
  pros::delay(200);
  mogo.set_value(false);
  pros::delay(300);
  intake.move(-127);
  pts(120, 125);
  pw();
  pds(25, 127);
  pw();
  pds(-60, 100);
  pw();
  /*chassis.pid_swing_set(LEFT_SWING, -230, 120, 32);
  pw();

  pros::delay(50);
  pts(260, 70);
  pw();
  doinker.set_value(true);
  pros::delay(100);
  intake.move(0);
  /*pds(16, 60);
  pw();
  pts(0, 100);
  pw();
  intake.move(-127);
  pds(20, 100);
  pw();
  pts(-90, 80);
  pw();
  pds(40, 90);
  pw();*/
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

void red_four_ring() {
  mogo.set_value(true);

  pds(50, 127);
  pw();
  // doinker out
  intake.move(-127);
  pros::delay(800);
  intake.move(0);

  pds(-10, 127);
  pw();

  pts(-55, 127);
  pw();
  // doinker in

  pds(-20, 127);
  pw();

  mogo.set_value(false);
  intake.move(-127);

  pts(-75, 127);
  pw();

  pds(20, 127);
  pw();
  intake.move(0);

  pts(-180, 127);
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

  // doinker out
}

//! UNFINISHED
// TODO: FINISH
void auton_skills() {
  mogo.set_value(true);

  // score on alliance stake
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

  // grab first mogo
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

void solo_awp_red(){
  #define up true
  #define down false
  mogo.set_value(up);
  arm_motor.move(70);
  pros::delay(500);
  arm_motor.move(-10);
  pds(-10, 100);
  pw();
  pts(57, 110); // the (53) here is noted as X
  pw();
  pds(-45, 50);
  pw();
  pros::delay(200);
  //clamp
  mogo.set_value(down);
  pros::delay(200);
  pds(5, 80);
  pw();
  pts(147, 100); // change 140 to whatever the X is +90
  pw();
  intake.move(-127);
  pds(28, 110);
  pw();
  pts(237, 110);
  pw();
  pds(15, 90);
  pw();
  pds(-28, 100);
  pw();
  pts(327, 110);
  pw();
  pds(80, 100);
  pw();
  mogo.set_value(up);
  pds(15, 105);
  pw();
  pts(237, 90);
  pw();
  pds(15, 110);
  pw();
  pts(-5, 110);
  pw();
  pds(-40, 80);
  pw();
  mogo.set_value(down);
  pts(327, 100);
  pw();
  pds(25, 100);
  pw();
  pds(-60, 127);
  pw();
  arm_motor.move(90);
}

void fucking_ez_for_skills_kms(){
  arm_motor.move(70);
  pros::delay(500);
  arm_motor.move(-10);
  pds(-16, 80);
  pw();
  mogo.set_value(false);
  //pts()
}

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  // red_left();
  //red_solo_awp();
  //red_safe_wp();
  //red_right();
  //blue_safe_wp();
  //delay(5000);
  /*pds(30, 127);
  pw();
  pts(90, 127);
  pw();
  pts(0, 127);
  pw();
  pds(-30, 127);
  pw();*/
  //solo_awp_red();
  fucking_ez_for_skills_kms();
  //intake.move(-127);
  //red_left();
  //skills_v1();
  // ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

///
// Auton selector
///

void four_ring(){

}



void add_autons() {
  ez::as::auton_selector.autons_add({
      {"auton red left", red_left},
      {"auton red right", red_right},
      {"auton skills", auton_skills},
  });
}
