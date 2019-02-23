/*
 * timer.h
 *
 * Created: 2/14/2019 9:29:02 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../includes/types.h"
#include "../includes/bitwiseOperations.h"
#include "../includes/DIO.h"
#include "../includes/timer_config.h"



void timer0_init(uint8 mode,uint16 prescaler,uint8 compare_mode);
void timer1_init(uint8 mode,uint16 prescaler,uint8 compare_mode,uint8 compare_pin);
void timer0_delay_ms(uint32 n);

#endif /* TIMER_H_ */