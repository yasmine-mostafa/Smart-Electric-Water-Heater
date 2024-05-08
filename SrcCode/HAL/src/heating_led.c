/*
 * heating_led.c
 *
 *  Created on: Dec 19, 2022
 *      Author: main
 */


#include "heating_led.h"
#include <util/delay.h>


void led_init()
{
	SetPinDir(Group_D,PIN1, PIN_OUTPUT);
	SetPinVal(Group_D,PIN1, PIN_LOW);
}

void led_heatingBlink(uint8*count)
{
	/**count=*count+1;
	if(*count==245)
	{

		TCNT0=220;
		*count=0;
	PORTD^=(1<<1);
	}*/
	/*SetPinVal(Group_D,PIN1, PIN_HIGH);
	delay_ms_(500);
	SetPinVal(Group_D,PIN1, PIN_LOW);
	delay_ms_(500);*/

	*count = *count+1;
	if (*count == 61)
	{
		*count = 0;
		SetPinVal(Group_D,PIN1, PIN_HIGH);
		_delay_ms(500);
		SetPinVal(Group_D,PIN1, PIN_LOW);
		_delay_ms(500);
	}

}
void led_heatingON()
{
	/*SREG|=(1<<7);
	TCCR0 &=~(1<<0);//256 prescalar
	TCCR0 &=~(1<<1);
	TCCR0|=(1<<2);
	TIMSK|=(1<<0); //enable
	TCNT0=220;
	sei();
	*/

	/*SetPinVal(Group_D,PIN1, PIN_HIGH);
	_delay_ms(500);
	SetPinVal(Group_D,PIN1, PIN_LOW);
	_delay_ms(500);
	*/

	TIMSK|=(1<<0); //enable
}
void led_coolingON()
{
	SetPinVal(Group_D,PIN1, PIN_HIGH);
	//TIMSK&=~(1<<0); //disable
}
void led_disable()
{
	SetPinVal(Group_D,PIN1, PIN_LOW);
	//TIMSK&=~(1<<0);
}
