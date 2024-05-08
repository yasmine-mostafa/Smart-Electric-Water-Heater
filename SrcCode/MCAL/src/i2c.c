/*
 * i2c.c
 *
 *  Created on: Sep 18, 2019
 *      Author: Joseph Hanna
 */


#include "i2c.h"

/*void TWI_Init(void)
{
    /* Bit Rate:  kbps using zero pre-scaler TWPS=00 and F_CPU=16Mhz */
 //   TWBR = 12;
//	TWSR = 0x00;

    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
  ///  TWAR = 0b00000010; // my address = 0x01 :)

    ///TWCR = (1<<TWEN); /* enable TWI */
//}

void TWI_Master_Init(void)
{
    SetPinDir(Group_C , PIN0 , PIN_OUTPUT);
	SetPinDir(Group_C, PIN1 , PIN_OUTPUT);
	/*SCL Freq = 400K when the oscilator = 16M */
	TWBR = 12;
	TWSR = 0x00;

	TWCR = (1<<TWEN)|(1<<TWEA); /* enable TWI */
}

void TWI_Slave_Init(void)
{
	/*Address of Slave*/
	TWAR = (0x01<<1);
	/*Enable I2C*/
	TWCR = (1<<TWEN)|(1<<TWEA);
}

void TWI_Start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));

}

void TWI_Stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
void TWI_SendSlaveAddress_Write(uint8 addr)
{
	TWDR = (addr << 1);

	CLR_BIT(TWDR,0); //write request
	CLR_BIT(TWCR,TWSTA);

	SET_BIT(TWCR,TWINT);

	while(GET_BIT(TWCR,TWINT) == 0); //wait until operation finishes

	while((TWSR & 0XF8) != TW_MT_SLA_W_ACK);

}

void TWI_SendSlaveAddress_Read(uint8 addr)
{
	TWDR = (addr << 1);

	SET_BIT(TWDR,0); //set read request
	CLR_BIT(TWCR,TWSTA);

	SET_BIT(TWCR,TWINT);

	while(GET_BIT(TWCR,TWINT) == 0); //wait until operation finishers

	while((TWSR & 0XF8) != TW_MT_SLA_R_ACK);
}

void TWI_Write(unsigned char data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

unsigned char TWI_Read_With_ACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

unsigned char TWI_Read_With_NACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

unsigned char TWI_Get_Status(void)
{
	unsigned char status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
