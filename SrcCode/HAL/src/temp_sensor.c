/*
 * temp_sensor.c
 *
 *  Created on: Dec 17, 2022
 *      Author: lenovo
 */


#include "temp_sensor.h"

void sensor_Init()
{
	SetPinDir(Group_A,PIN2, PIN_INPUT);
    ADMUX=0XE2;                           // 0b11100010 => Internal Vref, ADC2 (PIN A2)
    ADCSRA = (1<<7) | (1<<1) | (1<<0);    // ADC Enable, Prescaler Value = 8
}

uint8 sensor_Read()
{
	ADMUX &= 0XE2;
	SET_BIT(ADCSRA,6); // Start Conversion

	while((ADCSRA&(1<<ADIF))==0){} // Wait till conversion is done

	SET_BIT(ADCSRA,ADIF); // Clear ADIF

	return ADCH; // Return the reading value
}

sint32 temp_calc()
{
	int temp_avg;
	int num=10;
	int temp_sum=0;
	uint8 reading;

	for(int i=0;i<num;i++)
	{
		reading=sensor_Read();
		temp_sum=temp_sum+reading;
		_delay_ms(100);
	}

	temp_avg=(temp_sum/num);
	temp_sum=0;
	return temp_avg;
}
