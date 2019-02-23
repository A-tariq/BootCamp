/*
 * sevenSeg.c
 *
 * Created: 2/18/2019 12:52:36 PM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/sevenSeg.h"
void SevSegments_init(void)
{
	DIO_SetPinDirection(SEGA,OUTPUT);
	DIO_SetPinDirection(SEGB,OUTPUT);
	DIO_SetPinDirection(SEGC,OUTPUT);
	DIO_SetPinDirection(SEGD,OUTPUT);
	
	DIO_SetPinDirection(SEG1_EN,OUTPUT);
	DIO_SetPinDirection(SEG2_EN,OUTPUT);
	DIO_SetPinDirection(SEG3_EN,OUTPUT);
	DIO_SetPinDirection(SEG4_EN,OUTPUT);

}
void BCDSevSegments_enable(uint8 sevSeg_NO)
{
	DIO_WritePin(sevSeg_NO,ON);
	
}
void BCDSevSegments_disable(uint8 sevSeg_NO)
{
	DIO_WritePin(sevSeg_NO,OFF);
}
void BCDSevsegments_displayNo(uint16 num)
{
	
	if(num <= 9999 )
	{
	// seg 1 display
		//SEV_SEG_PORT = (SEV_SEG_PORT & 0xF0 ) | (num%10) ; // cast for only the least significant bits
		DIO_WritePin(SEGA,( (((num%10) & 0x0F) & (1<<0)) >> 0));
		DIO_WritePin(SEGB,( (((num%10) & 0x0F) & (1<<1)) >> 1));
		DIO_WritePin(SEGC,( (((num%10) & 0x0F) & (1<<2)) >> 2));
		DIO_WritePin(SEGD,( (((num%10) & 0x0F) & (1<<3)) >> 3));
		// Enable only segment 1
		BCDSevSegments_enable(SEG1_EN);
		BCDSevSegments_disable(SEG2_EN);
		BCDSevSegments_disable(SEG3_EN);
		BCDSevSegments_disable(SEG4_EN);
		timer0_delay_ms(SEV_SEG_DELAY);
	// seg 2 display
	    num = num / 10 ; // 432
       //SEV_SEG_PORT = (SEV_SEG_PORT & 0xF0 ) | (num%10) ; // cast for only the least significant bits
        DIO_WritePin(SEGA,( (((num%10) & 0x0F) & (1<<0)) >> 0));
        DIO_WritePin(SEGB,( (((num%10) & 0x0F) & (1<<1)) >> 1));
        DIO_WritePin(SEGC,( (((num%10) & 0x0F) & (1<<2)) >> 2));
        DIO_WritePin(SEGD,( (((num%10) & 0x0F) & (1<<3)) >> 3));		
	   // Enable only segment 2
		BCDSevSegments_enable(SEG2_EN);
		BCDSevSegments_disable(SEG1_EN);
		BCDSevSegments_disable(SEG3_EN);
		BCDSevSegments_disable(SEG4_EN);
		timer0_delay_ms(SEV_SEG_DELAY);
	// seg 3 display
	    num = num / 10 ; // 43
        //SEV_SEG_PORT = (SEV_SEG_PORT & 0xF0 ) | (num%10) ; // cast for only the least significant bits
        DIO_WritePin(SEGA,( (((num%10) & 0x0F) & (1<<0)) >> 0));
        DIO_WritePin(SEGB,( (((num%10) & 0x0F) & (1<<1)) >> 1));
        DIO_WritePin(SEGC,( (((num%10) & 0x0F) & (1<<2)) >> 2));
        DIO_WritePin(SEGD,( (((num%10) & 0x0F) & (1<<3)) >> 3));
		// Enable only segment 3
 		BCDSevSegments_enable(SEG3_EN);
		BCDSevSegments_disable(SEG2_EN);
		BCDSevSegments_disable(SEG1_EN);
		BCDSevSegments_disable(SEG4_EN);
		timer0_delay_ms(SEV_SEG_DELAY);
	// seg 4 display
	    num = num / 10 ; // 4
        //SEV_SEG_PORT = (SEV_SEG_PORT & 0xF0 ) | (num%10) ; // cast for only the least significant bits
        DIO_WritePin(SEGA,( (((num%10) & 0x0F) & (1<<0)) >> 0));
        DIO_WritePin(SEGB,( (((num%10) & 0x0F) & (1<<1)) >> 1));
        DIO_WritePin(SEGC,( (((num%10) & 0x0F) & (1<<2)) >> 2));
        DIO_WritePin(SEGD,( (((num%10) & 0x0F) & (1<<3)) >> 3));
        // Enable only segment 4
		BCDSevSegments_enable(SEG4_EN);
		BCDSevSegments_disable(SEG1_EN);
		BCDSevSegments_disable(SEG2_EN);
		BCDSevSegments_disable(SEG3_EN);
		timer0_delay_ms(SEV_SEG_DELAY);
	}
	else
	{
		BCDSevSegments_enable(SEG1_EN);
		BCDSevSegments_enable(SEG2_EN);
		BCDSevSegments_enable(SEG3_EN);
		BCDSevSegments_enable(SEG4_EN);
        SEV_SEG_PORT &= 0xF0   ; 
	}
	

}

	
