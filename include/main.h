/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2021, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"
#include "EZ-Template/api.hpp"

// More includes here...
#include "autons.hpp"
#include "subsystems.hpp"


/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;
// using namespace ez;
using namespace okapi::literals;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
using namespace pros;
using namespace ez;
#endif

#endif  // _PROS_MAIN_H_
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

void auton_skills() {
  mogo.set_value(false);

  //score on alliance stake
  intake.move(127);
  pros::delay(500);

  chassis.pid_turn_set(-120, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(-10, 120);
  chassis.pid_wait();

  //grab first mogo
  mogo.set_value(true);
  pros::delay(100);
  
  chassis.pid_turn_set(120, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(10, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(30, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(30, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(135, 120);
  chassis.pid_wait();

  arm_pid.target_set(arm_loading);

  chassis.pid_drive_set(13, 120);
  chassis.pid_wait();
  
  chassis.pid_turn_set(45, 120);
  chassis.pid_wait();

  // score on wall stake
  arm_pid.target_set(arm_scoring);
  pros::delay(100);
  arm_pid.target_set(arm_noninterfere);

  chassis.pid_turn_set(-30, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(15, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(-15, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(20, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(-135, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(10, 120);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(-15, 120);
  chassis.pid_wait();

  // drop first mogo
  mogo.set_value(false);
}


void red_solo_awp(){
  
  mogo.set_value(true);
  chassis.pid_drive_set(-35_in, 127);
  chassis.pid_wait();
  mogo.set_value(false);
  intake.move(-127);
  //intake.move(-127);
  pros::delay(500);
  mogo.set_value(true);
  chassis.pid_turn_set(120,127);
  //chassis.pid_turn_set(90_deg, 110);
  //chassis.pid_wait();
  //chassis.pid_drive_set(20_in, 127);
  //chassis.pid_wait();
}

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  //red_left();
  red_solo_awp();
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
