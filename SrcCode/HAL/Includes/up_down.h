/*
 * up_down.h
 *
 *  Created on: Dec 19, 2022
 *      Author: main
 */

#ifndef UP_DOWN_H_
#define UP_DOWN_H_
#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void button_init();
void button_up(uint16 *, uint8 *, uint8*);
void button_down(uint16 *, uint8 *, uint8*);
//void entertempset_mode(uint8 *);
void exittempset_mode(uint8 *, uint8 *);
void change_status(int*);
void button_disable(void);

#endif /* UP_DOWN_H_ */
