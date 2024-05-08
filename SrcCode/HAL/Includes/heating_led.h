/*
 * heating_led.h
 *
 *  Created on: Dec 19, 2022
 *      Author: main
 */

#ifndef HEATING_LED_H_
#define HEATING_LED_H_

#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void led_init();
void led_heatingBlink(uint8*);
void led_heatingON();
void led_coolingON();
void led_disable();


#endif /* HEATING_LED_H_ */
