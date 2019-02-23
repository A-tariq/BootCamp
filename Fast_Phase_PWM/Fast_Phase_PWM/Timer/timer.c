/*
 * timer.c
 *
 * Created: 2/14/2019 9:28:36 AM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/timer.h"

void timer0_init(uint8 mode,uint16 prescaler,uint8 compare_mode)
{
	switch(prescaler)
	{
	  case NO_PRESCALER :
	         Set_Bit(_TCCR0,_CS00);
		     Clear_Bit(_TCCR0,_CS01);
			 Clear_Bit(_TCCR0,_CS02);
			 break;
	  case 8 :
	         Clear_Bit(_TCCR0,_CS00);
		     Set_Bit(_TCCR0,_CS01);
			 Clear_Bit(_TCCR0,_CS02);
	         break;
	  case 64 :
	         Set_Bit(_TCCR0,_CS00);
	         Set_Bit(_TCCR0,_CS01);
	         Clear_Bit(_TCCR0,_CS02);
	         break;
	  case 256 :
	         Clear_Bit(_TCCR0,_CS00);
	         Clear_Bit(_TCCR0,_CS01);
	         Set_Bit(_TCCR0,_CS02);
	         break;
	  case 1024 :
	         Set_Bit(_TCCR0,_CS00);
	         Clear_Bit(_TCCR0,_CS01);
	         Set_Bit(_TCCR0,_CS02);
	         break;
	  default:
	         Set_Bit(_TCCR0,_CS00);
	         Clear_Bit(_TCCR0,_CS01);
	         Clear_Bit(_TCCR0,_CS02);
	         break;     
    }
	switch(mode)
	{
	  case NORMAL_MODE :
	              _TCNT0 = 0 ;
				  Clear_Bit(_TCCR0,_WGM01);
				  Clear_Bit(_TCCR0,_WGM00);
	              break;
				  
      case PHASE_PWM_MODE :
				  _TCNT0 = 0 ;
				  _OCR0 = 0xFF ;
				  Set_Bit(_TCCR0,_WGM00);
				  Clear_Bit(_TCCR0,_WGM01);
				  Set_Bit(_TIFR,_OCF0);
				  break;
				  
      case CTC_MODE :
	              _TCNT0 = 0 ;
				 // _OCR0 = 0xFF ;
				  Clear_Bit(_TCCR0,_WGM00);
				  Set_Bit(_TCCR0,_WGM01);
				  Set_Bit(_TIFR,_OCF0);
                  break;
	  
	  case FAST_PWM_MODE :
	              _TCNT0 = 0 ;
				  _OCR0 = 0xFF ;
				  Set_Bit(_TCCR0,_WGM00);
				  Set_Bit(_TCCR0,_WGM01);
				  Set_Bit(_TIFR,_OCF0);
	              break;
	}
	
	switch(compare_mode)
	{
		case NORMAL_MODE :
		        _TCCR0 &= ~((1<<_COM00)|(1<<_COM01));
				break;
	    case TOGGLE_MODE :
	            _TCCR0 |=  (1<<_COM00);
				_TCCR0 &= ~(1<<_COM01);
	            break;
	    case CLEAR_MODE :
                _TCCR0 &= ~(1<<_COM00);
                _TCCR0 |=  (1<<_COM01);
	            break;
		case SET_MODE :
	            _TCCR0 |= ((1<<_COM00)|(1<<_COM01));
	            break;
	}
	Set_Bit(_TIMSK,_OCIE0);
}
void timer1_init(uint8 mode,uint16 prescaler,uint8 compare_mode,uint8 compare_pin)
{
	if ( compare_pin == COMPARE_A)
	{
		switch(compare_mode)
		{
			case NORMAL_MODE :
			Set_Bit(_TCCR1A,_COM1A0);
			Set_Bit(_TCCR1A,_COM1A1);
			break;
			case TOGGLE_MODE :
			Set_Bit(_TCCR1A,_COM1A0);
			Clear_Bit(_TCCR1A,_COM1A1);
			break;
			case CLEAR_MODE :
			Clear_Bit(_TCCR1A,_COM1A0);
			Set_Bit(_TCCR1A,_COM1A1);
			break;
			case SET_MODE :
			Set_Bit(_TCCR1A,_COM1A0);
			Set_Bit(_TCCR1A,_COM1A1);
			break;
		}
	}
	else if (compare_pin == COMPARE_B)
	{
		switch(compare_mode)
		{
		 case NORMAL_MODE :
			Set_Bit(_TCCR1A,_COM1B0);
			Set_Bit(_TCCR1A,_COM1B1);
			break;
		 case TOGGLE_MODE :
			Set_Bit(_TCCR1A,_COM1B0);
			Clear_Bit(_TCCR1A,_COM1B1);
			break;
		 case CLEAR_MODE :
			Clear_Bit(_TCCR1A,_COM1B0);
			Set_Bit(_TCCR1A,_COM1B1);
			break;
		 case SET_MODE :
			Set_Bit(_TCCR1A,_COM1B0);
			Set_Bit(_TCCR1A,_COM1B1);
			break;
		}
	}
	
	switch(prescaler)
	{
	 case NO_PRESCALER :
		Set_Bit(_TCCR1B,_CS10);
		Clear_Bit(_TCCR1B,_CS11);
		Clear_Bit(_TCCR1B,_CS12);
		break;
	 case 8 :
		Clear_Bit(_TCCR1B,_CS10);
		Set_Bit(_TCCR1B,_CS11);
		Clear_Bit(_TCCR1B,_CS12);
		break;
	 case 64 :
		Set_Bit(_TCCR1B,_CS10);
		Set_Bit(_TCCR1B,_CS11);
		Clear_Bit(_TCCR1B,_CS12);
		break;
	 case 256 :
		Clear_Bit(_TCCR1B,_CS10);
		Clear_Bit(_TCCR1B,_CS11);
		Set_Bit(_TCCR1B,_CS12);
		break;
	 case 1024 :
		Set_Bit(_TCCR1B,_CS10);
		Clear_Bit(_TCCR1B,_CS11);
		Set_Bit(_TCCR1B,_CS12);
		break;
	 default:
		Set_Bit(_TCCR1B,_CS10);
		Clear_Bit(_TCCR1B,_CS11);
		Clear_Bit(_TCCR1B,_CS12);
		break;
		
	}
	switch(mode)
	{
	 case NORMAL_MODE :
		_TCNT1 = 0 ;
		Clear_Bit(_TCCR1A,_WGM10);
		Clear_Bit(_TCCR1A,_WGM11);
		Clear_Bit(_TCCR1B,_WGM12);
		Clear_Bit(_TCCR1B,_WGM13);
		break;
		
	 case PHASE_PWM_MODE :
		_ICR1H = 0xFF ;
		_ICR1L = 0xFF ;
		Clear_Bit(_TCCR1A,_WGM10);
		Set_Bit(_TCCR1A,_WGM11);
		Clear_Bit(_TCCR1B,_WGM12);
		Set_Bit(_TCCR1B,_WGM13);
		
		break;
		
	 case CTC_MODE :
		_ICR1H = 0xFF ;
		_ICR1L = 0xFF ;
		Clear_Bit(_TCCR1A,_WGM10);
		Clear_Bit(_TCCR1A,_WGM11);
		Set_Bit(_TCCR1B,_WGM12);
		Set_Bit(_TCCR1B,_WGM13);
		Set_Bit(_TIFR,_OCF1A);
		_OCR1AH = 0xFF ;
		_OCR1AL = 0xFF ;
		break;
		
	 case FAST_PWM_MODE :
		_ICR1H = 0xFF ;
		_ICR1L = 0xFF ;
		Clear_Bit(_TCCR1A,_WGM10);
		Set_Bit(_TCCR1A,_WGM11);
		Set_Bit(_TCCR1B,_WGM12);
		Set_Bit(_TCCR1B,_WGM13);
		break;
	}
	
	Set_Bit(_TIMSK,_OCIE1A);
	Set_Bit(_TIMSK,_OCIE1B);
}

void timer0_delay_ms(uint32 n)
{
	_TCNT0 = 0 ;
	_OCR0 = 62 ;
	for (uint16 i = 0 ; i < n ; i++)
	{
	  // count one millisecond
      while(Get_Bit(_TIFR,_OCF0) == 0 );
      // clear the OC flag to be ready for another millisecond
	  Set_Bit(_TIFR,_OCF0);
	}
}

