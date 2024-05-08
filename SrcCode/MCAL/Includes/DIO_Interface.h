/*
 * DIO_Interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: main
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Register.h"

#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

///directions
#define PIN_OUTPUT 1
#define PIN_INPUT 0

#define PORT_OUTPUT 0xff
#define PORT_INPUT 0x00

///value
#define PIN_HIGH 1
#define PIN_LOW 0

#define PORT_HIGH 0xff
#define PORT_LOW 0x00

///functions
void DIO_SetPortDir(uint8 PortID,uint8 Dir);
void DIO_SetPinDir(uint8 PortID,uint8 PinID,uint8 Dir);
void DIO_SetPortVal(uint8 PortID,uint8 val);
void DIO_SetPinval(uint8 PortID,uint8 PinID,uint8 val);




#endif /* DIO_INTERFACE_H_ */
