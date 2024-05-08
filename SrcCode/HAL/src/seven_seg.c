/*
 * seven_seg.c
 *
 *  Created on: 20 Dec 2022
 *      Author: Shams
 */

#include "seven_seg.h"

// 1st Seven Segment  => C2 till C5
// 2nd Seven Segment => D4 till D7
// Seven Segment GND => C6

void SevenSegInit(void)
{
	DDRC |= 0b01111100; // Set Direction of C2 to C6 to be output
	DDRD |= 0b11110000; // Set Direction of D4 to D7 to be output
	PORTC &= ~(0b01111100); // Set PORTC Values of Seven Segment to ZERO (INCLUDING GND)
	PORTD &= ~(0b11110000); // Set PORTD Values of Seven Segment to ZERO
}

void DisplayTemp(uint8 Temp)
{
	const uint8 TempDecoy = Temp;                // Create a constant so that it doesn't  change during the calculations
	const uint8 TempUnitsDigit = TempDecoy%10;   // Get the Units Digit
	const uint8 TempTensDigit = ((Temp/10)%10);  // Get the Tens Digit

	uint8 Temp2 = ((TempTensDigit<<2)&0x003C);   // Shifting the digits to be put in C2 to C5
	uint8 Temp1 = ((TempUnitsDigit<<4)&0x00F0);  // Shifting the digits to be put in D4 to D7

	//ClearSevenSeg();
	PORTC &= ~(0b01111100);
	PORTC |= Temp2;
	PORTD &= ~(0b11110000);
	PORTD |= Temp1;
}

void ClearSevenSeg(void)
{
	PORTC &= ~(0b01111100); // Set PORTC Values of Seven Segment to ZERO (INCLUDING GND)
	PORTD &= ~(0b11110000); // Set PORTD Values of Seven Segment to ZERO
}

void SevenSegBlink(uint8* count, uint8 status)
{
	if (status == 1)
	{
		*count = *count + 1;
		if (*count == 61)
		{
			PORTC |= (1<<6);
			_delay_ms(500);
			PORTC &= (~(1<<6));
			_delay_ms(500);
		}
	}
}

