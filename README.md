# K_A39_004_based_on_STM32_and_other_single-chip_microcomputers_driving_the_AT24C02_module

K_A39_004_based_on_STM32_and_other_single-chip_microcomputers_driving_the_AT24C02_module_serial_port+OLED0.96_display

这里有中英文说明 前部分为中文说明 后半部分为英文说明 请悉知

Here are Chinese and English description The previous part of the Chinese description is the English description in English, please know how to know

注：文档手册在工程文件的DOC文件夹内

Note: The document manual is in the DOC folder of the engineering file

如果发现程序有BUG 或者有可以改进的地方 欢迎联系我们

If you find that the program has bugs or can be improved, please contact us

@[TOC](K_A39_004 基于STM32等单片机驱动AT24C02模块  串口+OLED0.96显示)

@[TOC](K_A39_004 based on STM32 and other single -chip microcomputers driving the AT24C02 module serial port+OLED0.96 display)


- [所有资源导航](#所有资源导航)
- [资源说明](#资源说明)
- [基本参数](#基本参数)
  * [参数](#参数)
  * [引脚说明](#引脚说明)
- [驱动说明](#驱动说明)
  * [时序](#时序)
  * [对应程序](#对应程序)
- [部分代码说明](#部分代码说明)
  * [接线引脚定义](#接线引脚定义)
    + [STC89C52RC+AT24C02模块](#STC89C52RC+AT24C02模块)
    + [STM32F103C8T6+AT24C02模块](#STM32F103C8T6+AT24C02模块)
- [基础知识学习与相关资料下载](#基础知识学习与相关资料下载)
- [视频效果展示与程序资料获取](#视频效果展示与程序资料获取)
- [注意事项](#注意事项)
- [接线说明](#接线说明)
  * [STC89C52RC](#stc89c52rc)
  * [STM32F103C8T6](#stm32f103c8t6)
- [All resource navigation](#all-resource-navigation)
- [Resource description](#resource-description)
- [basic parameters](#basic-parameters)
  * [parameter](#parameter)
  * [pin explanation](#pin-explanation)
- [Drive Instructions](#drive-instructions)
  * [timing](#timing)
  * [corresponding program](#corresponding-program)
- [Partial code description](#partial-code-description)
  * [Wiring pin definition](#wiring-pin-definition)
    + [STC89C52RC+AT24C02 module](#stc89c52rc-at24c02-module)
    + [STM32F103C8T6+AT24C02 module](#stm32f103c8t6-at24c02-module)
- [Basic knowledge learning and related information download](#basic-knowledge-learning-and-related-information-download)
- [Video effect display and program data acquisition](#video-effect-display-and-program-data-acquisition)
- [Notice](#notice)
- [Wiring description](#wiring-description)
  * [STC89C52RC](#stc89c52rc-1)
  * [STM32F103C8T6](#stm32f103c8t6-1)


![请添加图片描述](https://img-blog.csdnimg.cn/f591b27d1115445e9597d616481f492b.jpeg)


#  所有资源导航
[**其他资料目录**](https://blog.csdn.net/lfmnlxx79691557/article/details/128323460?spm=1001.2014.3001.5501)     	直戳跳转
# 资源说明
| 单片机型号 | 测试条件|模块名称 |代码功能 |
|:--------:| -------------:| -------------:|-------------:|
| STC89C52RC | 晶振11.0592M	 |AT24C02模块|STC89C52RC驱动AT24C02模块  串口与OLED0.96双显示 |
| STM32F103C8T6 | 晶振8M/系统时钟72M |AT24C02模块 |STM32F103C8T6驱动AT24C02模块 串口与OLED0.96双显示 |


# 基本参数
## 参数
![请添加图片描述](https://img-blog.csdnimg.cn/0c44adef20674f1e9a5280683e85d7f3.png)

## 引脚说明

AT24C02模块| 	引脚说明
-------- | -----
VIN	| 正极 3.3/5V供电
GND	| GND 电源负极
SCL	| IIC时钟线 
SDA	| IIC数据线


# 驱动说明

## 时序

![请添加图片描述](https://img-blog.csdnimg.cn/3714ff40f308482b8ce8bd29a09bf78d.png)
![请添加图片描述](https://img-blog.csdnimg.cn/7388a945328941509a48a23b3bc062ca.png)
![请添加图片描述](https://img-blog.csdnimg.cn/5c50b576eec944c0a5eb89281bde06a5.png)

## 对应程序
以51为例
```javascript
/*******************************************************************************
* 函数名         : Delay10us()
* 函数功能		   : 延时10us
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void Delay10us()
{
	uint8_t a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
/*******************************************************************************
* 函数名         : I2cStart()
* 函数功能		 : 起始信号：在AT24C0X_SCL时钟信号在高电平期间AT24C0X_SDA信号产生一个下降沿
* 输入           : 无
* 输出         	 : 无
* 备注           : 起始之后AT24C0X_SDA和AT24C0X_SCL都为0
*******************************************************************************/

void I2cStart()
{
	AT24C0X_SDA=1;
	AT24C0X_SCL=1;
	Delay10us();//建立时间是AT24C0X_SDA保持时间>4.7us
	AT24C0X_SDA=0;
	Delay10us();//保持时间是>4us
	AT24C0X_SCL=0;			
	Delay10us();		
}
/*******************************************************************************
* 函数名         : I2cStop()
* 函数功能		 : 终止信号：在AT24C0X_SCL时钟信号高电平期间AT24C0X_SDA信号产生一个上升沿
* 输入           : 无
* 输出         	 : 无
* 备注           : 结束之后保持AT24C0X_SDA和AT24C0X_SCL都为1；表示总线空闲
*******************************************************************************/

void I2cStop()
{
	AT24C0X_SDA=0;
	AT24C0X_SCL=1;
	Delay10us();//建立时间大于4.7us
	AT24C0X_SDA=1;
	Delay10us();	
	
}
/*******************************************************************************
* 函数名         : I2cSendByte(uint8_t dat)
* 函数功能		 : 通过I2C发送一个字节。在AT24C0X_SCL时钟信号高电平期间，保持发送信号AT24C0X_SDA保持稳定
* 输入           : num
* 输出         	 : 0或1。发送成功返回1，发送失败返回0
* 备注           : 发送完一个字节AT24C0X_SCL=0,AT24C0X_SDA=1
*******************************************************************************/

uint8_t I2cSendByte(uint8_t dat)
{
	uint8_t a=0,b=0;//最大255，一个机器周期为1us，最大延时255us。		
	for(a=0;a<8;a++)//要发送8位，从最高位开始
	{
		AT24C0X_SDA=dat>>7;	 //起始信号之后AT24C0X_SCL=0，所以可以直接改变AT24C0X_SDA信号
		dat=dat<<1;
		Delay10us();
		AT24C0X_SCL=1;
		Delay10us();//建立时间>4.7us
		AT24C0X_SCL=0;
		Delay10us();//时间大于4us		
	}
	AT24C0X_SDA=1;
	Delay10us();
	AT24C0X_SCL=1;
	Delay10us();
	while(AT24C0X_SDA)//等待应答，也就是等待从设备把AT24C0X_SDA拉低
	{
		b++;
		if(b>200)	 //如果超过2000us没有应答发送失败，或者为非应答，表示接收结束
		{
			//AT24C0X_SCL=0;
			Delay10us();
			return 0;
		}
	}
	AT24C0X_SCL=0;
	Delay10us();
 	return 1;		
}
/*******************************************************************************
* 函数名         : I2cReadByte()
* 函数功能		   : 使用I2c读取一个字节
* 输入           : 无
* 输出         	 : dat
* 备注           : 接收完一个字节AT24C0X_SCL=0,AT24C0X_SDA=1.
*******************************************************************************/

uint8_t I2cReadByte()
{
	uint8_t a=0,dat=0;
	AT24C0X_SDA=1;			//起始和发送一个字节之后AT24C0X_SCL都是0
	Delay10us();
	for(a=0;a<8;a++)//接收8个字节
	{
		AT24C0X_SCL=0;
		Delay10us();
		AT24C0X_SCL=1;
		Delay10us();
		dat<<=1;
		dat|=AT24C0X_SDA;
		Delay10us();
		AT24C0X_SCL=0;
		Delay10us();
	}
	return dat;		
}


/*******************************************************************************
* 函数名         : void At24c02Write(uint8_t addr,uint8_t dat)
* 函数功能		   : 往24c02的一个地址写入一个数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void At24c02Write(uint8_t addr,uint8_t dat)
{
	I2cStart();
	I2cSendByte(0xa0);//发送写器件地址
	I2cSendByte(addr);//发送要写入内存地址
	I2cSendByte(dat);	//发送数据
	I2cStop();
}
/*******************************************************************************
* 函数名         : uint8_t At24c02Read(uint8_t addr)
* 函数功能		   : 读取24c02的一个地址的一个数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void At24c02Read( uint8_t *pReadBuf,uint8_t addr,uint8_t usSize)
{
	uint8_t i;
	I2cStart();
	I2cSendByte(0xa0); //发送写器件地址
	I2cSendByte(addr); //发送要读取的地址
	I2cStart();
	I2cSendByte(0xa1); //发送读器件地址
	for (i = 0; i < usSize-1; i++)
	{
		pReadBuf[i]=I2cReadByte(); //读取数据
		 Ack_I2c(0);
	}
	pReadBuf[i]=I2cReadByte(); //读取数据
	Ack_I2c(1);
	I2cStop();
	
}
/********************************************************************
                     应答子函数
函数原型:  void Ack_I2c(bit a);
功能:      主控器进行应答信号(可以是应答或非应答信号，由位参数a决定)
********************************************************************/
void Ack_I2c(bit a)
{
  
  if(a==0)AT24C0X_SDA=0;              /*在此发出应答或非应答信号 */
  else AT24C0X_SDA=1;
  Delay10us();     
  AT24C0X_SCL=1;
  Delay10us(); 
  AT24C0X_SCL=0;                     /*清时钟线，钳住I2C总线以便继续接收*/
  Delay10us();   
}
```
# 部分代码说明
## 接线引脚定义

需要自定义引脚可在此处更改，STM32要自定义引脚的话也要注意引脚时钟使能的更改

### STC89C52RC+AT24C02模块
```javascript
//AT24C02模块引脚定义
sbit AT24C0X_SCL=P1^3;
sbit AT24C0X_SDA=P1^2;


//OLED0.96模块引脚定义
sbit SCL=P1^1; //串行时钟
sbit SDA=P1^0; //串行数据
```
### STM32F103C8T6+AT24C02模块
```javascript
//AT24C02模块引脚定义

#define EEPROM_GPIO_PORT_I2C	GPIOB			/* GPIO端口 */
#define EEPROM_RCC_I2C_PORT 	RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define EEPROM_I2C_SCL_PIN		GPIO_Pin_8			/* 连接到SCL时钟线的GPIO */
#define EEPROM_I2C_SDA_PIN		GPIO_Pin_9			/* 连接到SDA数据线的GPIO */
//OLED0.96模块引脚定义					
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_8)//SCL
#define OLED_SCLK_Set() GPIO_SetBits(GPIOB,GPIO_Pin_8)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_9)//SDA
#define OLED_SDIN_Set() GPIO_SetBits(GPIOB,GPIO_Pin_9)
```

# 基础知识学习与相关资料下载

1、[STC89C52RC程序下载](https://blog.csdn.net/lfmnlxx79691557/article/details/127114912?spm=1001.2014.3001.5501)			直戳跳转

2、STM32F103C8T6程序下载		

(1)[串口下载](https://blog.csdn.net/lfmnlxx79691557/article/details/122862183?spm=1001.2014.3001.5501)                直戳跳转 

(2)[ST-LINK下载](https://blog.csdn.net/lfmnlxx79691557/article/details/127140554?spm=1001.2014.3001.5501)             直戳跳转

(3)[J-LINK下载](https://blog.csdn.net/lfmnlxx79691557/article/details/127140823?spm=1001.2014.3001.5501)              直戳跳转

(4)[DAP-LINK下载](https://blog.csdn.net/lfmnlxx79691557/article/details/127141244?spm=1001.2014.3001.5501)            直戳跳转


3、[OLED0.96程序说明](https://blog.csdn.net/lfmnlxx79691557/article/details/127208887?spm=1001.2014.3001.5501)			直戳跳转


4、串口助手下载与使用

(1)[安信可调试助手使用](https://blog.csdn.net/lfmnlxx79691557/article/details/128335660?spm=1001.2014.3001.5502) 						直戳跳转

(2) [sscom33串口调试助手使用](https://blog.csdn.net/lfmnlxx79691557/article/details/128335808?spm=1001.2014.3001.5502)			直戳跳转

(3)[STC-ISP串口调试助手使用](https://blog.csdn.net/lfmnlxx79691557/article/details/128335896?spm=1001.2014.3001.5502)			    直戳跳转

# 视频效果展示与程序资料获取

[视频连接](https://www.bilibili.com/video/BV1ks4y137cp/?vd_source=7933b82b52c9cbf1c7966eb9f0dbd29f)  	直戳跳转

资料获取 （可直接下载仓库）

# 注意事项

1、VCC GND请勿接反，接反易烧

2、OLED显示异常时，排除接线接触不良

# 接线说明
## STC89C52RC   
```javascript

/************************************************************************************
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
```
## STM32F103C8T6 
```javascript
  
/************************************************************************************
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
```


![Please add picture description](https://img-blog.csdnimg.cn/f591b27d1115445e9597d616481f492b.jpeg)

# All resource navigation

[ Other data catalog ](https://blog.csdn.net/lfmnlxx79691557/article/details/128323460?spm=1001.2014.3001.5501)   Direct link to jump

# Resource description
| Single -chip Machine Model | Test Conditions | Module Name | Code Function |
|:--------:| -------------:| -------------:|-------------:|
| STC89C52RC | Crystal Vibration 11.0592M | AT24C02 module | STC89C52RC driver AT24C02 module serial port and OLED0.96 dual display |
| STM32F103C8T6 | Crystal 8M/System Clock 72M | AT24C02 Module | STM32F103C8T6 Drive AT24C02 module serial port and OLED0.96 dual display |


# basic parameters
## parameter

![Please add picture description](https://img-blog.csdnimg.cn/0c44adef20674f1e9a5280683e85d7f3.png)

## pin explanation

AT24C02 module | pin explanation
-------- | -------
Vin | Positive 3.3/5V Power Supply
GND | GND power supply negative electrode
SCL | IIC clock line
SDA | IIC data cable


# Drive Instructions

## timing

![Please add picture description](https://img-blog.csdnimg.cn/3714ff40f308482b8ce8bd29a09bf78d.png)
![Please add picture description](https://img-blog.csdnimg.cn/7388a945328941509a48a23b3bc062ca.png)
![Please add picture description](https://img-blog.csdnimg.cn/5c50b576eec944c0a5eb89281bde06a5.png)

## corresponding program
Take 51 as an example
```javascript
/*************************************************** *************************************
* Function name: delay10us (void)
* Function function: delay 10US
* Enter: None
* Output: None
********************************************************************************************/

void Delay10us()
{
	uint8_t a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
/*************************************************** *************************************
* Function name: I2CSTART (void)
* Function function: Start signal: At the AT24C0X_SCL clock signal during the high level, the AT24C0X_SDA signal generates a decrease edge
* Enter: None
* Output: None
* Remarks: After the beginning, AT24C0X_SDA and AT24C0X_SCL are both 0
************************************************* *******************************************/

void I2cStart (void)
{
	AT24C0X_SDA=1;
	AT24C0X_SCL=1;
	Delay10us(); // The establishment time is AT24C0X_SDA maintenance time> 4.7us
	AT24C0X_SDA=0;
	Delay10us();// Keep the time is> 4us
	AT24C0X_SCL=0;	
	Delay10us ();
}

/*************************************************** *************************************
* Function name: I2CSTOP (void)
* Function function: Termination signal: During the AT24C0X_SCL clock signal high level, AT24C0X_SDA signal generates a rising edge
* Enter: None
* Output: None
* Remarks: After the end, keep AT24C0X_SDA and AT24C0X_SCL as 1; indicate that the bus is idle
************************************************* *******************************************/

void I2cStop (void)
{
	AT24C0X_SDA=0;
	AT24C0X_SCL=1;
	Delay10us(); // The establishment time is greater than 4.7us
	AT24C0X_SDA=1;
	Delay10us();
}

/*************************************************** *************************************
* Function name: i2csendbyte (UINT8_T DAT)
* Function function: Send a byte through I2C. During the high level of the AT24C0X_SCL clock signal, keep the sending signal AT24C0X_SDA maintained stable
* Input: num
* Output: 0 or 1. Back to 1 successfully, the sending failure returns 0
* Remarks: After sending a byte of byte AT24C0X_SCL = 0, AT24C0X_SDA = 1
************************************************* *******************************************/

UINT8_T I2CSENDBYTE (UINT8_T DAT)
{
	uint8_t a=0,b=0; // maximum 255, a machine cycle of 1us, maximum delay 255US.
	for(a=0;a<8;a++) // To send 8 bits, start from the highest bit
	{
		AT24C0X_SDA=dat>>7;	 // After the start signal, AT24C0X_SCL = 0, so you can directly change the AT24C0X_SDA signal
		dat=dat<<1;
		Delay10us();
		AT24C0X_SCL=1;
		Delay10us(); // Create time> 4.7us
		AT24C0X_SCL=0;
		Delay10us(); // time greater than 4us
	}
	AT24C0X_SDA=1;
	Delay10us();
	AT24C0X_SCL=1;
	Delay10us();
	while(AT24C0X_SDA) // Waiting for the answer, that is, waiting for the device to lower the AT24C0X_SDA
	{
		b++;
		if(b>200) // If it fails to answer more than 2000us, or it is a non -answer, it means that the reception is over
		{
			// at24c0x_scl = 0;
			Delay10us();
			return 0;
		}
	}
	AT24C0X_SCL=0;
	Delay10us();
 	return 1;	
}

	
/*************************************************** *************************************
* Function name: i2creadbyte ()
* Function function: Read a byte using I2C
* Enter: None
* Output: DAT
* Remarks: After receiving a byte of byte AT24C0X_SCL = 0, AT24C0X_SDA = 1. 1.
************************************************* *******************************************/

UINT8_T I2cReadByte ()
{
	uint8_t a = 0, dat = 0;
	AT24C0X_SDA = 1; // After the beginning and sending a byte, AT24C0X_SCL is 0
	Delay10us ();
	for(a=0;a<8;a++) // Receive 8 bytes
	{
		AT24C0X_SCL=0;
		Delay10us();
		AT24C0X_SCL=1;
		Delay10us();
		dat<<=1;
		dat|=AT24C0X_SDA;
		Delay10us();
		AT24C0X_SCL=0;
		Delay10us();
	}
	return dat;	
}

/*************************************************** *************************************
* Function name: void at24c02write (UINT8_T addr, UINT8_T DAT)
* Function function: Write a data to a address of 24C02
* Enter: None
* Output: None
************************************************* *******************************************/

void At24c02Write(uint8_t addr,uint8_t dat)
{
	I2cStart();
	I2cSendByte(0xa0); // Send the written device address
	I2cSendByte(addr); // Send to write to the memory address
	I2cSendByte(dat); // Send data
	I2cStop();
}

/*************************************************** *************************************
* Function name: UINT8_T AT24C02Read (UINT8_T ADDR)
* Function function: Read a data of a address of 24C02
* Enter: None
* Output: None
************************************************* *******************************************/

void At24c02Read( uint8_t *pReadBuf,uint8_t addr,uint8_t usSize)
{
	uint8_t i;
	I2cStart();
	I2cSendByte(0xa0); // Send the written device address
	I2cSendByte(addr); // Send the address to be read
	I2cStart();
	I2cSendByte(0xa1); // Send the read device address
	for (i = 0; i < usSize-1; i++)
	{
		pReadBuf[i]=I2cReadByte(); // Read the data
		 Ack_I2c(0);
	}
	pReadBuf[i]=I2cReadByte(); // Read the data
	Ack_I2c(1);
	I2cStop();

}

/*************************************************** ************************
Answer sub -function
Function prototype: void acK_i2c (bit a);
Function:
The main controller conducts the answer signal (it can be answered or non -response signal, which is determined by position parameter A)
************************************************* ********************/
void Ack_I2c(bit a)
{
  
	if(a==0)AT24C0X_SDA=0; /*Send an response or non -response signal */
	else AT24C0X_SDA=1;
	Delay10us();     
	AT24C0X_SCL=1;
	Delay10us(); 
	AT24C0X_SCL=0;/*Clear Clock Line, clamp the I2C bus in order to continue to receive*/
	Delay10us();   
}



```
# Partial code description
##  Wiring pin definition

You need to customize the pin can be changed here. If STM32 needs to customize the pin, you should also pay attention
### STC89C52RC+AT24C02 module
```javascript
// AT24C02 module pin definition
sbit at24c0x_scl = P1^3;
sbit at24c0x_sda = P1^2;

//OLED0.96 module pin definition
sbit SCL = P1^1; // Serial clock
sbit SDA = P1^0; // Serial data
```
### STM32F103C8T6+AT24C02 module
```javascript
// AT24C02 module pin definition

#Define Eeprom_GPIO_PORT_I2C GPIOB / * GPIO port * /
#Define Eeprom_rcc_i2C_PORT RCC_APB2PERIPH_GPIOB / * GPIO port clock * /
#Define Eeprom_i2C_SCL_PIN GPIO_PIN_8 / * connected to the gpio * /connected to the SCL clock line
#Define Eeprom_i2C_SDA_PIN GPIO_PIN_9 / * connected to the GPIO * /connected to the SDA data cable
//OLED0.96 module pin definition
#Define OLED_SCLK_CLR () GPIO_RESETBITS (GPIOB, GPIO_PIN_8) // SCL
#Define OLED_SCLK_SET () GPIO_SETBITS (GPIOB, GPIO_PIN_8)

#Define OLED_SDIN_CLR () GPIO_RESETBITS (GPIOB, GPIO_PIN_9) // SDA
#Define OLED_SDIN_SET () GPIO_SETBITS (GPIOB, GPIO_PIN_9)
```

# Basic knowledge learning and related information download

1. [STC89C52RC program download](https://blog.csdn.net/lfmnlxx79691557/article/details/127114912?spm=1001.2014.3001.5501)    Direct link to jump

2. STM32F103C8T6 program download

	(1) [serial port download](https://blog.csdn.net/lfmnlxx79691557/article/details/122862183?spm=1001.2014.3001.5501)      Direct link to jump

	(2) [ST-LINK Download](https://blog.csdn.net/lfmnlxx79691557/article/details/127140554?spm=1001.2014.3001.550)     Direct link to jump

	(3) [j-link download](https://blog.csdn.net/lfmnlxx79691557/article/details/127140823?spm=1001.2014.3001.5501)    Direct link to jump


	(4) [dap-link download](https://blog.csdn.net/lfmnlxx79691557/article/details/127141244?spm=1001.2014.3001.5501)    Direct link to jump


3. [OLED0.96 Program Instructions](https://blog.csdn.net/lfmnlxx79691557/article/details/127208887?spm=1001.2014.3001.5501)    Direct link to jump


4. Download and use serial assistant

	(1) [Anxin's debugging assistant use](https://blog.csdn.net/lfmnlxx79691557/article/details/128335660?spm=1001.2014.3001.5502)    Direct link to jump

	(2) [SSCOM33 serial debug assistant use](https://blog.csdn.net/lfmnlxx79691557/article/details/128335808?spm=1001.2014.3001.5502)    Direct link to jump

	(3) [STC -ISP serial debugging assistant use](https://blog.csdn.net/lfmnlxx79691557/article/details/128335896?spm=1001.2014.3001.5502) 
   Direct link to jump


# Video effect display and program data acquisition

[Video Connection](https://www.bilibili.com/video/BV1ks4y137cp/?vd_source=7933b82b52c9cbf1c7966eb9f0dbd29f) Stranding jumping

Data acquisition (can download the warehouse directly)

# Notice

1. Please do not recalculate VCC GND.

2. When the OLED display is abnormal, exclude poor wiring contact

# Wiring description
## STC89C52RC
```javascript

/********************************************************************************************
// Function description: AT24C02 module test program
// Test conditions: STC89C52RC Crystal Epicer 11.0592
wiring

AT24C02 Module-------------------------STC89C52RC
VCC------------------------------------5V
GND------------------------------------GND
SCL------------------------------------P1.3 //
SDA------------------------------------P1.2 //	

OLED0.96(IIC) -------------------------STC89C52RC
VCC------------------------------------5V
GND------------------------------------GND
SCL------------------------------------P1^1
SDA------------------------------------P1^0
*************************************************************************************************
```
## STM32F103C8T6
```javascript
  
/********************************************************************************************
// Function description: AT24C02 module test program
// Test conditions: STM32F103C8T6 Crystal 8M System Clock 72M
wiring

AT24C02 Module-------------------------STM32F103C8T6
VCC------------------------------------3.3/5V
GND------------------------------------GND
SCL------------------------------------PB8 //
SDA------------------------------------PB9 //	


OLED0.96(IIC) -------------------------STM32F103C8T6
VCC------------------------------------3.3V
GND------------------------------------GND
SCL------------------------------------PB6
SDA------------------------------------PB7

*************************************************************************************************
```
