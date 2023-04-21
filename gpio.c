#include "gpio.h"
void Gpio_Init(void)
{
	P0TRIS=0x1b;
	P1TRIS=0xd0;	//1输出 0输入 
	P2TRIS=0x60;
	P3TRIS=0x0d;  //
	P0OD=0X00;		//1 开漏输出 0正常状态
	P1OD=0X00;		//1 开漏输出 0正常状态
	P2OD=0X00;		//1 开漏输出 0正常状态
	P3OD=0X00;		//1 开漏输出 0正常状态
	P0UP=0X00;		//1 开上拉   0关上拉
	P1UP=0X00;
	P2UP=0X00;
	P3UP=0X40;
	P0OD=0X00;		//1 开漏输出 0正常状态
	P1OD=0X00;	
	P2OD=0X00;	
	P3OD=0X00;	
	P0RD=0X00;		//1 开下拉   0关下拉
	P1RD=0X00;
	P2RD=0X00;
	P3RD=0X00;
	P0DR=0X00;        //1 强驱动   0若驱动
	P1DR=0X00; 
	P2DR=0X00; 
	P3DR=0X00; 
	P0SR=0X00;		//1 慢斜率    0快斜率
	P1SR=0X00;
	P2SR=0X00;
	P3SR=0X00;
	
	P15EICFG=0x03;	// P15EICFG=0x03;
	P15CFG=0x00;
//	P00CFG=0X00;	//复用功能控制
	P1EXTIE=0x20;
	P16=1;
	P17=1;
}