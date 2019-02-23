/*
 * motor.h
 *
 * Created: 2/21/2019 11:35:13 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../includes/timer.h"
#include "../includes/motors_config.h"



void init_DC_Motor_1(uint8 pwm_mode);
void init_DC_Motor_2(uint8 pwm_mode);
void change_motor_1_dir(void);
void stop_motor_1(void);
void enable_motor_1(void);
void change_motor_2_dir(void);
void stop_motor_2(void);
void enable_motor_2(void);



#endif /* MOTOR_H_ */