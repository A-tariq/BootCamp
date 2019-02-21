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

#define F_CPU 8000000u

#include "includes/types.h"
#include "includes/bitwiseOperations.h"
#include "includes/DIO.h"
#include "includes/timer.h"
#include <avr/interrupt.h>
#define GO 0
#define STOP 1
#define GET_READY 2
uint16 counter = 0 ;
uint8 ledState = 0 ;
ISR(TIMER0_COMP_vect)
{
	counter++ ;
	if (counter == 1000)
	{
		ledState++ ;
		counter = 0 ;
	}
}
ISR(INT2_vect)
{
	ledState = STOP ;
	counter = 0 ;
}
void enableExtInt2();
int main(void)
{
	DIO_SetPinDirection(13,OUTPUT);
	DIO_SetPinDirection(14,OUTPUT);
	DIO_SetPinDirection(15,OUTPUT);
	DIO_WritePin(13,OFF);
	DIO_WritePin(14,OFF);
	DIO_WritePin(15,OFF);
	
	// enable Global Interrupt
	Set_Bit(SREG,IBIT);
		
	timer_init();
	enableExtInt2();

	while (1)
	{
		switch (ledState%3)
		{
			case GO :
			   DIO_WritePin(13,ON);
			   DIO_WritePin(15,OFF);
			   DIO_WritePin(14,OFF);
			   break;
			case STOP :
			   DIO_WritePin(13,OFF);
			   DIO_WritePin(15,ON);
			   DIO_WritePin(14,OFF);
			   break;
			case GET_READY :
			   DIO_WritePin(13,OFF);
			   DIO_WritePin(15,OFF);
			   DIO_WritePin(14,ON);
			   break;
			
		}
		
	}
	return 0 ;
}
void enableExtInt2()
{
	Set_Bit(GICR,INT2);
	Set_Bit(MCUCSR,ISC2);
	DIO_SetPinDirection(BUTTON_1,INPUT);
}