/*
 * temp_sensor.h
 *
 *  Created on: Dec 17, 2022
 *      Author: lenovo
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"

#include <avr/io.h>
#include <util/delay.h>

void sensor_Init();

uint8 sensor_Read();

sint32 temp_calc();


#endif /* TEMP_SENSOR_H_ */
