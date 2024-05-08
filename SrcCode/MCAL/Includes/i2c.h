/*
 * i2c.h
 *
 *  Created on: Sep 18, 2019
 *      Author: Joseph Hanna
 */

#ifndef I2C_H_
#define I2C_H_

#include<avr/io.h>
#include "std_types.h"
#include "bit_maths.h"
#include "DIO_Interface.h"

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )


/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave


void TWI_Init(void);
void TWI_Slave_Init(void);
void TWI_Master_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_SendSlaveAddress_Write(uint8 addr);
void TWI_SendSlaveAddress_Read(uint8 addr);
void TWI_Write(unsigned char data);
unsigned char TWI_Read_With_ACK(void); //read with send Ack
unsigned char TWI_Read_With_NACK(void); //read without send Ack
unsigned char TWI_Get_Status(void);

#endif /* I2C_H_ */
