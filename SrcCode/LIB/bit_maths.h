/*
 * bit_maths.h
 *
 *  Created on: Oct 1, 2022
 *      Author: main
 */

#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(REG,BIT) REG=REG|(1<<BIT)
#define CLR_BIT(REG,BIT) REG=REG&(~(1<<BIT))
#define TOG_BIT(REG,BIT) REG=REG^(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&0x01)


#endif /* BIT_MATHS_H_ */
