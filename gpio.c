#include "gpio.h"
void Gpio_Init(void)
{
	P0TRIS=0x1b;
	P1TRIS=0xd0;	//1��� 0���� 
	P2TRIS=0x60;
	P3TRIS=0x0d;  //
	P0OD=0X00;		//1 ��©��� 0����״̬
	P1OD=0X00;		//1 ��©��� 0����״̬
	P2OD=0X00;		//1 ��©��� 0����״̬
	P3OD=0X00;		//1 ��©��� 0����״̬
	P0UP=0X00;		//1 ������   0������
	P1UP=0X00;
	P2UP=0X00;
	P3UP=0X40;
	P0OD=0X00;		//1 ��©��� 0����״̬
	P1OD=0X00;	
	P2OD=0X00;	
	P3OD=0X00;	
	P0RD=0X00;		//1 ������   0������
	P1RD=0X00;
	P2RD=0X00;
	P3RD=0X00;
	P0DR=0X00;        //1 ǿ����   0������
	P1DR=0X00; 
	P2DR=0X00; 
	P3DR=0X00; 
	P0SR=0X00;		//1 ��б��    0��б��
	P1SR=0X00;
	P2SR=0X00;
	P3SR=0X00;
	
	P15EICFG=0x03;	// P15EICFG=0x03;
	P15CFG=0x00;
//	P00CFG=0X00;	//���ù��ܿ���
	P1EXTIE=0x20;
	P16=1;
	P17=1;
}