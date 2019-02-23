/*
 * timer_config.h
 *
 * Created: 2/22/2019 9:55:28 PM
 *  Author: AVE-LAP-016
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define NORMAL_MODE 0
#define CTC_MODE 1
#define FAST_PWM_MODE 2
#define PHASE_PWM_MODE 3
#define NO_PRESCALER 0
/////////////////////////
/*COMPARE MODES */
#define TOGGLE_MODE 1
#define SET_MODE 2
#define CLEAR_MODE 3



#define _TCCR0 *((volatile uint8*) (0x53))
#define _OCF0 1
#define _CS00 0
#define _CS01 1
#define _CS02 2
#define _WGM01 3
#define _WGM00 0
#define _COM00 4
#define _COM01 5

#define _TCNT0 *((volatile uint8*) (0x52))
#define _OCR0  *((volatile uint8*) (0x5C))
#define _TIFR  *((volatile uint8*) (0x58))

#define ONE_SECOND 1000 // 1000 milliseconds
#define _TIMSK *((volatile uint8*) (0x59))
#define _SREG *((volatile uint8*) (0x5F))
#define _IBIT 7
#define _OCIE0 1
#define _GIFR *((volatile uint8*) (0x5A))
#define _GICR *((volatile uint8*) (0x5B))
#define _MCUCSR *((volatile uint8*) (0x54))
#define _INTF2 5
#define _INT2 5
#define _ISC2 6

#define COMPARE_A 0
#define COMPARE_B 1
#define _TCNT1  *((volatile uint8*) (0x2C))
#define _TCCR1A *((volatile uint8*) (0x4F))
#define _WGM10 0
#define _WGM11 1
#define _FOC1B 2
#define _FOC1A 3
#define _COM1B0 4
#define _COM1B1 5
#define _COM1A0 6
#define _COM1A1 7

#define _TCCR1B *((volatile uint8*) (0x4E))
#define _CS10 0
#define _CS11 1
#define _CS12 2
#define _WGM12 3
#define _WGM13 4


#define _ICR1H  *((volatile uint8*) (0x47))
#define _ICR1L  *((volatile uint8*) (0x46))
#define _OCR1AH *((volatile uint8*) (0x4B))
#define _OCR1AL *((volatile uint8*) (0x4A))
#define _OCR1BH *((volatile uint8*) (0x49))
#define _OCR1BL *((volatile uint8*) (0x48))
#define _OCIE1A 4
#define _OCIE1B 3
#define _OCF1A 4
#define _OCF1B 3
#define _OC1A PIND_5
#define _OC1B PIND_4






#endif /* TIMER_CONFIG_H_ */