/*
 * keypad.c
 *
 * Created: 2/18/2019 2:51:13 PM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/keypad.h"
void keypad_init(void)
{
	DIO_SetPinDirection(ROW1,INPUT);
	DIO_SetPinDirection(ROW2,INPUT);
	DIO_SetPinDirection(ROW3,INPUT);
	/* Activate internal pull up */
	DIO_WritePin(ROW1,ON);
	DIO_WritePin(ROW2,ON);
	DIO_WritePin(ROW3,ON);
	
    DIO_SetPinDirection(COL1,OUTPUT);
    DIO_SetPinDirection(COL2,OUTPUT);
    DIO_SetPinDirection(COL3,OUTPUT);
	/* reset the 3 most significant bits */
	DIO_WritePin(COL1,ON);
	DIO_WritePin(COL2,ON);
	DIO_WritePin(COL3,ON);
}
uint8 keypad_getPressedKey(void)
{ 
	 uint8 col,row ;
	 static uint8 num ;
     for (  col = COL1 ; col <= COL3 ; col++)
		 {
			 /* set the 3 most significant bits*/
			 DIO_WritePin(COL1,ON);
			 DIO_WritePin(COL2,ON);
			 DIO_WritePin(COL3,ON);
			 /* reset the column */
			 DIO_WritePin(col,OFF);
			 for (  row = ROW1 ; row <= ROW3 ; row++)
			 {
				 if (DIO_ReadPin(row) == 0)
					 {
						 num = (3*(row-18))+(col-21)+1 ;
					 } 
			 }
		 }
	return num ;
}