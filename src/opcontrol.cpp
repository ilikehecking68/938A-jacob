#include "main.h"

bool doinker_status = false;
bool prev_doinker_status = false;
bool mogo_status = false;

void doinker_update(bool button_new_press){
  if (button_new_press && !mogo_status){ //runs if button is pressed(not held)
    doinker_status = !doinker_status; //toggle doinker status
  }
  if (mogo_status){
    doinker_status = false;
  }
  if (doinker_status != prev_doinker_status){
    doinker.set_value(doinker_status);
  }
  prev_doinker_status = doinker_status;
}

void mogo_update(bool button_new_press){
  if (button_new_press){ //runs if button is pressed(not held)
    mogo_status = !mogo_status; //toggle mog status
    mogo.set_value(mogo_status); //set mogo
  }
}

double arm_target = arm_noninterfere;
/*bool arm_is_scoring = false;
unsigned long long arm_scoring_time = 0;*/
void arm_update(bool up_button_new_press, bool load_button_new_press, bool noninterfere_button_new_press){
    if (up_button_new_press){
        arm_target = arm_scoring;
        arm_pid.target_set(arm_target);
    } else if (load_button_new_press){
        arm_target = arm_loading;
        arm_pid.target_set(arm_target);
    } else if (noninterfere_button_new_press){
        arm_target = arm_noninterfere;
        arm_pid.target_set(arm_target);
    }
    if (arm_pid.exit_condition() != SMALL_EXIT){
        arm_motor.move(arm_pid.compute(get_arm_sensor_degrees()));
    }
    if (arm_target == arm_scoring){
      intake.move(22);
    }
}

void intake_update(bool in_button_held, bool out_button_held){
  if (in_button_held){
    intake.move(127);
  } else if (out_button_held){
    intake.move(-127);
  } else {
    intake.move(0);
  }
}

void opcontrol() {
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);
  arm_pid.exit_condition_set(80, 2, 250, 8, 500, 500);
  arm_pid.target_set(arm_noninterfere);
  while (true) {
    
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!(pros::competition::is_connected())){
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)){
        autonomous();
      }
    }
    /*if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }*/

    //chassis.opcontrol_tank();  // Tank control
    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade
    intake_update(master.get_digital(DIGITAL_R2), master.get_digital(DIGITAL_R1));
    //arm_update(master.get_digital(DIGITAL_B), master.get_digital_new_press(DIGITAL_RIGHT), master.get_digital_new_press(DIGITAL_DOWN));
    mogo_update(master.get_digital_new_press(DIGITAL_A));
    doinker_update(master.get_digital_new_press(DIGITAL_UP));
    arm_update(master.get_digital(DIGITAL_B), master.get_digital_new_press(DIGITAL_RIGHT), master.get_digital_new_press(DIGITAL_DOWN));
    mogo_update(master.get_digital_new_press(DIGITAL_A));
    doinker_update(master.get_digital_new_press(DIGITAL_L1));
    pros::lcd::print(3, "%lf", (double)(arm_sensor.get_position() / 100));
    pros::lcd::print(4, "%lf", (double)(arm_target));
    // . . .
    // Put more user control code here!
    // . . .

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}