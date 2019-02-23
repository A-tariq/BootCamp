/*
 * motors_config.h
 *
 * Created: 2/22/2019 10:54:56 PM
 *  Author: AVE-LAP-016
 */ 


#ifndef MOTORS_CONFIG_H_
#define MOTORS_CONFIG_H_

#define MOTOR_1_EN  _OC1B
#define MOTOR_2_EN  _OC1A
#define MOTOR_1_DIR_A  PIND_2
#define MOTOR_1_DIR_B  PIND_3
#define MOTOR_2_DIR_A  PIND_6
#define MOTOR_2_DIR_B  PIND_7
#define CLOCKWISE 0
#define ANTI_CLOCKWISE 1
#define OCR_MOTOR_1_H _OCR1BH
#define OCR_MOTOR_1_L _OCR1BL
#define OCR_MOTOR_2_H _OCR1AH
#define OCR_MOTOR_2_L _OCR1AL
#define MOTOR_1_FREQ 


#endif /* MOTORS_CONFIG_H_ */