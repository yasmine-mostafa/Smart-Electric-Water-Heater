/*
 * temp_elements.h
 *
 *  Created on: Dec 17, 2022
 *      Author: lenovo
 */
#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"
#include "heating_led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef TEMP_ELEMENTS_H_
#define TEMP_ELEMENTS_H_

void cooling_element_enable();
void cooling_element_disable();
void heating_element_enable();
void heating_element_disable();
void temp_regulation(int current_temp, int set_temp);

#endif /* TEMP_ELEMENTS_H_ */
