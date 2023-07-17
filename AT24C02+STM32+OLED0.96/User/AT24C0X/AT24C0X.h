#ifndef __AT24C0X_H
#define __AT24C0X_H
										  	  
#include "stm32f10x.h"
#include "AT24C0X_IIC.h"


/* 
 * AT24C02 2kb = 2048bit = 2048/8 B = 256 B
 * 32 pages of 8 bytes each
 *
 * Device Address
 * 1 0 1 0 A2 A1 A0 R/W
 * 1 0 1 0 0  0  0  0 = 0XA0
 * 1 0 1 0 0  0  0  1 = 0XA1 
 */

/* AT24C01/02ÿҳ��8���ֽ� 
 * AT24C04/08A/16Aÿҳ��16���ֽ� 
 */
	

#define EEPROM_DEV_ADDR			0xA0		/* 24xx08���豸��ַ */
#define EEPROM_PAGE_SIZE		  8			  /* 24xx08��ҳ���С */
#define EEPROM_SIZE				  256			  /* 24xx08������ */

extern uint8_t Write_Dat[10];
extern uint8_t Read_Dat[10];


uint8_t ee_CheckOk(void);
uint8_t ee_ReadBytes(uint8_t *_pReadBuf, uint16_t _usAddress, uint16_t _usSize);
uint8_t ee_WriteBytes(uint8_t *_pWriteBuf, uint16_t _usAddress, uint16_t _usSize);
void ee_Erase(void);
uint8_t ee_Test(void);

void Write_data(void);
void Read_data(void);
#endif






































