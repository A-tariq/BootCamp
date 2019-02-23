/*
 * motor.c
 *
 * Created: 2/21/2019 11:34:29 AM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/motor.h"
void init_DC_Motor_1(uint8 pwm_mode)
{
	_ICR1H = 0xEF ;
	_ICR1L = 0xEF ;
	OCR_MOTOR_1_H = 0x7F ;
	OCR_MOTOR_1_L = 0x7F ;
	
	timer1_init(pwm_mode,NO_PRESCALER,SET_MODE,COMPARE_B);
		
	DIO_SetPinDirection(MOTOR_1_EN,OUTPUT);
	DIO_SetPinDirection(MOTOR_1_DIR_A,OUTPUT);
	DIO_SetPinDirection(MOTOR_1_DIR_B,OUTPUT);
	DIO_WritePin(MOTOR_1_DIR_A,OFF);
	DIO_WritePin(MOTOR_1_DIR_B,ON);
	DIO_WritePin(MOTOR_1_EN,OFF);

}
void init_DC_Motor_2(uint8 pwm_mode)
{
	_ICR1H = 0xEF ;
	_ICR1L = 0xEF ;
	OCR_MOTOR_2_H = 0x7F ;
	OCR_MOTOR_2_L = 0x7F ;
	
	timer1_init(pwm_mode,NO_PRESCALER,SET_MODE,COMPARE_A);
	
	DIO_SetPinDirection(MOTOR_2_EN,OUTPUT);
	DIO_SetPinDirection(MOTOR_2_DIR_A,OUTPUT);
	DIO_SetPinDirection(MOTOR_2_DIR_B,OUTPUT);
	DIO_WritePin(MOTOR_2_DIR_A,OFF);
	DIO_WritePin(MOTOR_2_DIR_B,ON);
	DIO_WritePin(MOTOR_2_EN,OFF);

}
void change_motor_1_dir(void)
{
	DIO_TogglePin(MOTOR_1_DIR_A);
	DIO_TogglePin(MOTOR_1_DIR_B);
}
void stop_motor_1(void)
{
	DIO_WritePin(MOTOR_1_DIR_A,ON);
	DIO_WritePin(MOTOR_1_DIR_B,ON);
}
void enable_motor_1(void)
{
	DIO_WritePin(MOTOR_1_DIR_A,ON);
	DIO_WritePin(MOTOR_1_DIR_B,OFF);
	DIO_WritePin(MOTOR_1_EN,ON);
}
void change_motor_2_dir(void)
{
	DIO_TogglePin(MOTOR_2_DIR_A);
	DIO_TogglePin(MOTOR_2_DIR_B);
}
void stop_motor_2(void)
{
	DIO_WritePin(MOTOR_2_DIR_A,ON);
	DIO_WritePin(MOTOR_2_DIR_B,ON);
}
void enable_motor_2(void)
{
	DIO_WritePin(MOTOR_2_DIR_A,ON);
	DIO_WritePin(MOTOR_2_DIR_B,OFF);
	DIO_WritePin(MOTOR_2_EN,ON);
}
