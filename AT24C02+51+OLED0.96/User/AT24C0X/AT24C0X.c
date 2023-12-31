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
//  测试条件   : STC89C52RC   晶振11.0592
接线
AT24C02 -------------------------------STC89C52RC
VCC------------------------------------5V
GND------------------------------------GND
SCL------------------------------------P1.3 //
SDA------------------------------------P1.2 //	

OLED0.96(IIC) -------------------------STC89C52RC
VCC------------------------------------5V
GND------------------------------------GND
SCL------------------------------------P1^1
SDA------------------------------------P1^0
*************************************************************************************/

#include "AT24C0X.h"
#include "delay.h"
#include "Uart.h"
uint8_t xdata Write_Dat[10]={"12345"};
uint8_t xdata Read_Dat[10]={0};


/*******************************************************************************
写8字节数据进AT24C02
*******************************************************************************/
void Write_data(void)
{
	uint8_t i=0;
	for(i=0;i<8;i++)
	{
			At24c02Write(i,Write_Dat[i]);
			DelayMs(3);
	}
}

/*******************************************************************************
从AT24C02读8字节数据
*******************************************************************************/

void Read_data(void)
{
		At24c02Read( Read_Dat,0,7);
		//UartSendStr(Read_Dat);	
}






























