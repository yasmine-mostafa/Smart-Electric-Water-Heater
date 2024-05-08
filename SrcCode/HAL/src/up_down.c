/*
 * up_down.c
 *
 *  Created on: Dec 19, 2022
 *      Author: main
 */


#include "up_down.h"

void button_init()
{
	SetPinDir(Group_D,PIN2, PIN_INPUT); //up button
	SetPinDir(Group_D,PIN3, PIN_INPUT); //down button
	SetPinDir(Group_B,PIN2, PIN_INPUT); //on/off
	SREG |=(1<<7); //global interrupt
	GICR|=(1<<6)|(1<<7);
	//|(1<<5); //INT0/INT1/INT2
	MCUCR |=(1<<1)|(1<<0)|(1<<2)|(1<<3); //rising edge
	MCUCSR|=(1<<6);
	//GIFR|=(1<<6)|(1<<7)|(1<<5);

	//MCUCR |=(0<<1)|(1<<0)|(1<<2)|(0<<3); //any logical change
}

void button_up(uint16 *set_temp, uint8 *counter, uint8 *status)
{
	if((PIND>>2)&0x01)
		{
			_delay_ms(100);
			if((PIND>>2)&0x01)
			{

				*counter = *counter + 1;

				if( *counter >= 2 ) // Check to apply the temperature increase logic
				{
					if(*set_temp<=70) // Max temperature 75
					{
						*set_temp=(*set_temp)+5; // Increment by 5
						DisplayTemp(*set_temp);
					}
				}
				else // Enter Temperature Settings Mode
				{
					*status = 1;
				}
			}
		}
}
void button_down(uint16 *set_temp, uint8 *counter, uint8 *status)
{
	if((PIND>>3)&0x01)
	{
		_delay_ms(100);
		if((PIND>>3)&0x01)
		{
			*counter = *counter + 1; //Incrementing the counter

			if( *counter >= 2 ) // Check to apply the temperature increase logic
			{
				if(*set_temp>=40) // Max temperature 35
				{
					*set_temp=(*set_temp)-5;
					DisplayTemp(*set_temp);
				}
			}
			else // Enter Temperature Settings Mode
			{
				*status = 1;
			}
		}
	}
}

void exittempset_mode(uint8 *status, uint8 *counter)
{
	*counter = 0; // Reset Counter
	*status = 0;  // Return to Normal Mode
}
void button_disable(void)
{
	SetPinDir(Group_D,PIN2, PIN_OUTPUT); //up button
	SetPinDir(Group_D,PIN3, PIN_OUTPUT); //down button
}

void change_status(int* c) //on/off status
{
	if((PINB>>2)&0x01)
					{
					_delay_ms(100);
						if((PINB>>2)&0x01)
						{
							(*c)=!(*c);
						}
					}
}
