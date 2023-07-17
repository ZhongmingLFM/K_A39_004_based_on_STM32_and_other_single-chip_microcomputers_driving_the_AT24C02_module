/************************************************************************************
//（店名“众明工作室”）淘宝链接: https://shop149406681.taobao.com/?spm=a1z10.1-c.0.0.64cb457fKzgKea 
//淘宝店内搜索关键词：K_A39_004
//  版 本 号   : v1.0
//  作    者   : 众明工作室
//  交流群 :			 1041406448（其它更多资料请关注公告）
//    CSDN  （基本参数，资源更新列表，所有接线说明）   :单片机代码搬运工(搜索关键词：K_A39_004)
//    BILIBILI（演示视频） :众明工作室(搜索关键词：K_A39_004)
//  生成日期   : 2021-6-21
//  最近修改   : 2021-11-21
//  功能描述   : AT24C02模块测试程序
//  测试条件   : STM32F103C8T6   晶振8M  系统时钟72M
接线
AT24C02模块----------------------------STM32F103C8T6
VCC------------------------------------3.3/5V
GND------------------------------------GND
SCL------------------------------------PB8 //
SDA------------------------------------PB9 //	


OLED0.96(IIC) -------------------------STM32F103C8T6
VCC------------------------------------3.3V
GND------------------------------------GND
SCL------------------------------------PB6
SDA------------------------------------PB7
*************************************************************************************/

#include "oled.h"
#include "delay.h"
#include "AT24C0X.h"
#include "bsp_usart.h"


uint8_t DIS_Dat[10]={0};
/*******************************************************************************
* 函数名         :DigDisplay()
* 函数功能		 :OLED0.96显示函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void DigDisplay()
{
	u8 j=0;
	OLED_ShowString(0, 0,"write:",16);
	for(j=0;j<8;j++) 
	{
			DIS_Dat[j]=		Write_Dat[j];
	}
	DIS_Dat[8]=	'\0';
	OLED_ShowString(48, 0,DIS_Dat,16);
	Usart_SendString(DEBUG_USARTx,"write:");	
	Usart_SendString( DEBUG_USARTx,DIS_Dat);		
	
	
	OLED_ShowString(0, 2,"Read:",16);
	for(j=0;j<8;j++)
	{
			DIS_Dat[j]=		Read_Dat[j];
	}
	DIS_Dat[8]=	'\0';
	OLED_ShowString(48, 2,DIS_Dat,16);
	Usart_SendString( DEBUG_USARTx,"Read:");	
	Usart_SendString( DEBUG_USARTx,DIS_Dat);	
}


int main(void)
{

		DelayInit();
		OLED_Init();
		OLED_Clear();
		USART_Config();
		i2c_CfgGpio();
		while(1)
		{
			Write_data();
			Read_data();
			DigDisplay();
			DelayMs(300);
		}
}

















