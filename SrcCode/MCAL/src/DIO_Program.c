/*
 * DIO_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: main
 */


#include "DIO_Interface.h"

void DIO_SetPortDir(uint8 PortID, uint8 Dir)
{
	if(Dir==PORT_OUTPUT)
	{
		switch(PortID)
		{
		case Group_A : DDRA=0xff; break;
		case Group_B : DDRB=0xff; break;
		case Group_C : DDRC=0xff; break;
		case Group_D : DDRD=0xff; break;
		}
	}
	else if(Dir==PORT_INPUT)
	{
		switch(PortID)
		{
		case Group_A : DDRA=0x00; break;
		case Group_B : DDRB=0x00; break;
		case Group_C : DDRC=0x00; break;
		case Group_D : DDRD=0x00; break;

		}
	}
	}

void SetPinDir(uint8 PortID,uint8 PinID,uint8 Dir)
{
	if(Dir==PIN_OUTPUT)
		{
			switch(PortID)
			{
			case Group_A : SET_BIT(DDRA,PinID); break;
			case Group_B : SET_BIT(DDRB,PinID); break;
			case Group_C : SET_BIT(DDRC,PinID); break;
			case Group_D : SET_BIT(DDRD,PinID); break;
			}
		}
		else if(Dir==PIN_INPUT)
		{
			switch(PortID)
			{
			case Group_A : CLR_BIT(DDRA,PinID); break;
			case Group_B : CLR_BIT(DDRB,PinID); break;
			case Group_C : CLR_BIT(DDRC,PinID); break;
			case Group_D : CLR_BIT(DDRD,PinID); break;

			}
		}
}

void SetPortVal(uint8 PortID,uint8 val)
{
	if(val==PORT_HIGH)
		{
			switch(PortID)
			{
			case Group_A : PORTA=0xff; break;
			case Group_B : PORTB=0xff; break;
			case Group_C : PORTC=0xff; break;
			case Group_D : PORTD=0xff; break;
			}
		}
		else if(val==PORT_LOW)
		{
			switch(PortID)
			{
			case Group_A : PORTA=0x00; break;
			case Group_B : PORTB=0x00; break;
			case Group_C : PORTC=0x00; break;
			case Group_D : PORTD=0x00; break;

			}
		}
}
void SetPinVal(uint8 PortID,uint8 PinID,uint8 val)
{
	if(val==PIN_HIGH)
		{
			switch(PortID)
			{
			case Group_A : SET_BIT(PORTA,PinID); break;
			case Group_B : SET_BIT(PORTB,PinID); break;
			case Group_C : SET_BIT(PORTC,PinID); break;
			case Group_D : SET_BIT(PORTD,PinID); break;
			}
		}
		else if(val==PIN_LOW)
		{
			switch(PortID)
			{
			case Group_A : CLR_BIT(PORTA,PinID); break;
			case Group_B : CLR_BIT(PORTB,PinID); break;
			case Group_C : CLR_BIT(PORTC,PinID); break;
			case Group_D : CLR_BIT(PORTD,PinID); break;

			}
		}
}
