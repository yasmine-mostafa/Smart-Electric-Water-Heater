/*
 * seven_seg.h
 *
 *  Created on: 20 Dec 2022
 *      Author: Shams
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"

#include <avr/io.h>
#include <util/delay.h>

// 1st Seven Segment  => C2 till C5
// 2nd Seven Segment => D4 till D7

void SevenSegInit(void);
void DisplayTemp(uint8);
void SevenSegBlink(uint8*, uint8);
void ClearSevenSeg(void);

#endif /* SEVEN_SEG_H_ */
