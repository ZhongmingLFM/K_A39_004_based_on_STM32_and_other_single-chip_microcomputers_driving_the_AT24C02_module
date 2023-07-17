#ifndef __AT24C0X_IIC_H
#define __AT24C0X_IIC_H
										  	  
#include <reg52.h>
#include "main.h"


sbit AT24C0X_SCL=P1^3;
sbit AT24C0X_SDA=P1^2;

void I2cStart();
void I2cStop();
uint8_t I2cSendByte(uint8_t dat);
uint8_t I2cReadByte();
void At24c02Write(uint8_t addr,uint8_t dat);
void At24c02Read( uint8_t *pReadBuf,uint8_t addr,uint8_t usSize);
void Ack_I2c(bit a);

#endif






































