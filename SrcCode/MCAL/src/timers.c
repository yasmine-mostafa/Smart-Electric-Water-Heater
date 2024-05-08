/*
 * timers.c
 *
 *  Created on: 21 Dec 2022
 *      Author: Shams
 */

#include"timers.h"


void Timer0Init(void)
{
	TCNT0 = 0;
	//TCCR0 = 0b00000101;  // Normal Mode, OC0 Disconnected, Prescaler = 1024
	TCCR0 |= (1<<2)|(1<<0);  // Normal Mode, OC0 Disconnected, Prescaler = 1024
	//TIMSK &= 0b11111101; // Disable Output Compare Match Interrupts
	TIMSK |= 0b00000001; // Enable Timer0 Overflow Interrupt
	TIFR |= (1<<TOV0);
}

void Timer0Reset(void)
{
	TIFR |= (1<<TOV0);
}

void Timer0Disable(void)
{
	TCCR0 = 0x00;
}

void Timer2Init(void)
{
	TCNT2 = 0;
	TCCR2 = 0b00000101;  // Normal Mode, OC2 Disconnected, Prescaler = 1024
	TIMSK &= 0b01111111; // Disable Output Compare Match Interrupts
	//TIMSK |= 0b01000000; // Enable Timer2 Overflow Interrupt
	TIFR |= (1<<TOV2);
}

void Timer2Reset(void)
{
	TIFR |= (1<<TOV2);
}

void Timer2Disable(void)
{
	TCCR2 = 0x00;
}

void Timer1Init(void)
{
	TCCR1A = 0b00000000; // Normal Mode
	TCCR1B = 0b00000011; // Prescaler = 64
	TIMSK &= 0b11000111; // Disable Input Capture Interrupt & Output Compare Match Interrupt
}


