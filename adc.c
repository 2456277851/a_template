#include "adc.h"
#include "delay.h"
#include "over_temp_protection.h"
u16 Adc_Get_Value(u8 channel)
{
//	u16 temp=0;
//	ADCON0|=0xdc;
//	ADCON1|=0x4f;
//	ADCMPC=0x00;
//	ADCLDO=0xa0;
//	ADCON2=0x00;
//	ADCON1|=0x80;
//	ADCON0|=0x02;
//	while(ADCON0&0x02);
//	Delay_Us(2);
//	temp=ADRESH;
//	return (temp<<8)|ADRESL;
	
//	u16 temp=0;
//	ADCON0|=0x40;
//	ADCON1|=0x42;
//	ADCMPC=0x00;
//	ADCLDO=0xa0;
//	ADCON2=0x00;
//	ADCON1|=0x80;
//	ADCON0|=0x02;
//	//while(ADC_ADCON0_ADGO_Msk);
//	while(ADCON0&0x02);
//	Delay_Us(2);
//	temp=ADRESH;
//	return (temp<<8)|ADRESL;
//	u16 temp=0;
//	if(channel/16==1)
//	{
//		ADCON0=0xc0;
//	}
//	else
//	{
//		ADCON0=0x40;
//	}
//	ADCON1=(0xc0|(channel&0x0f));
//	if(channel==31)
//	{
//		ADCLDO=0x00;
//	}
//	else
//	{
//		ADCLDO=0xa0;
//	}
//	ADCMPC=0x00;
//	ADCON1|=0x80;
//	ADCON0|=0x02;
//	while(ADCON0&ADC_ADCON0_ADGO_Msk);
//	Delay_Us(2);
//	temp=ADRESH;
//	return (temp<<8)|ADRESL;	
	
	u16 temp=0;
	if(channel/16==1)
	{
		ADCON0=0xd8;//0xdc
	}
	else
	{
		ADCON0=0x58;
	}
	if(channel==31)
	ADCON1=(0xc0|(0x0f));
	else
	ADCON1=(0xc0|(channel&0x0f));
	if(channel==BoardTempertureChannel)
	{
		ADCLDO=0x00; //参考电压内部
	}
	else
	{
		ADCLDO=0xC0; //内部LDO2.4V参考
	}
	ADCMPC=0x00;
	ADCON1|=0x80;
	ADCON0|=0x02;
	while(ADCON0&ADC_ADCON0_ADGO_Msk);
	Delay_Us(8);
	temp=ADRESH;
	return (temp<<8)|ADRESL;
}
u16 Adc_Get_Channel_Val_Average(u8 channel,u8 times)
{
	u32 temp_val=0;
	u8 t=0;
	for(t=0;t<times;t++)
	{
		temp_val+=Adc_Get_Value(channel); 
		Delay_Us(8);
	}
	return (u16)(temp_val/times);
}