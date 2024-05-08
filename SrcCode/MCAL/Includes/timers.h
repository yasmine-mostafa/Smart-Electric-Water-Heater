/*
 * timers.h
 *
 *  Created on: 21 Dec 2022
 *      Author: Shams
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void Timer0Init(void);
void Timer0Reset(void);
void Timer0Disable(void);
void Timer2Init(void);
void Timer2Reset(void);
void Timer2Disable(void);
void Timer1Init(void);

#endif /* TIMERS_H_ */
