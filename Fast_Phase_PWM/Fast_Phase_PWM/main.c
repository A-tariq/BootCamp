/*
 * main.c
 *
 * Created: 2/20/2019 6:29:09 PM
 *  Author: AVE-LAP-016
 */ 
/*
 * Avelabs_Project.c
 *
 * Created: 2/13/2019 10:53:23 AM
 * Author : AVE-LAP-016
 */ 

#define F_CPU 16000000u

#include "includes/types.h"
#include "includes/bitwiseOperations.h"
#include "includes/DIO.h"
#include "includes/timer.h"
#include "includes/motor.h"
//#include <avr/interrupt.h>
uint8 motor_dir = CLOCKWISE ;

int main(void)
{
	timer0_init(CTC_MODE,256,SET_MODE);
	DIO_SetPinDirection(PINB5,OUTPUT);
	DIO_WritePin(PINB5,ON);
	init_DC_Motor_1(PHASE_PWM_MODE);
   //init_DC_Motor_1(FAST_PWM_MODE);
   //init_DC_Motor_2(PHASE_PWM_MODE);
   //init_DC_Motor_2(FAST_PWM_MODE);
	
    
	while (1)
	{
        DIO_WritePin(PINB5,OFF);
        stop_motor_1();
        timer0_delay_ms(3000);
        change_motor_1_dir();
		DIO_WritePin(PINB5,ON);
	    timer0_delay_ms(3000);

	}
	return 0 ;
}
