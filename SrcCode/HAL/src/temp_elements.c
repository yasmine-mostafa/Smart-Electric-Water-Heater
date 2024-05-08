/*
 * temp_elements.c
 *
 *  Created on: Dec 17, 2022
 *      Author: lenovo
 */

#include "temp_elements.h"
#include <util/delay.h>

void heating_element_disable()
{
	SetPinDir(Group_B,PIN0, PIN_OUTPUT);
    SetPinVal(Group_B,PIN0, PIN_LOW);
}

void heating_element_enable()
{
	SetPinDir(Group_B,PIN0, PIN_OUTPUT);
    SetPinVal(Group_B,PIN0, PIN_HIGH);
}
void cooling_element_enable()
{
	SetPinDir(Group_D,PIN0, PIN_OUTPUT);
	SetPinVal(Group_D,PIN0, PIN_HIGH);
}

void cooling_element_disable()
{
	SetPinDir(Group_D,PIN0, PIN_OUTPUT);
    SetPinVal(Group_D,PIN0, PIN_LOW);
}
void temp_regulation(int current_temp, int set_temp)
{
 if(current_temp < set_temp-4)
 {
	 heating_element_enable();
	 cooling_element_disable();
	 led_heatingON();
 }
 else if(current_temp>set_temp+4)
 {
	 cooling_element_enable();
	 heating_element_disable();
	 led_coolingON();
 }
 else
 {
	 heating_element_disable();
	 cooling_element_disable();
	 led_disable();
 }
}
