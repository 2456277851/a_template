#include "my_define.h"  
#include "main.h"
#include "oled.h"
#include "bmp.h"
#include "display.h"
#define	ChargingTimerUsThreshold 133 //75us*100=10ms 
#define	ChargingTimerMsThreshold 50 //100ms*100=1s 
#define	AreaRefreshDynamicTimerUsThreshold 133 //75us*100=10ms 
#define	AreaRefreshDynamicTimerMsThreshold 50 //100ms*100=1s 
xdata u8 ChargingTimerUs;
xdata u8 ChargingTimerMs;
xdata u8 BatteryDisplayState;
xdata u8 AreaRefreshDynamicTimerUs;
xdata u8 AreaRefreshDynamicTimerMs;
xdata u8 AreaRefreshDynamicCounter;
void Display_Init(void)
{
   ChargingTimerUs=0;
   ChargingTimerMs=0;
   BatteryDisplayState=0;
   AreaRefreshDynamicTimerUs=0;
   AreaRefreshDynamicTimerMs=0;
   AreaRefreshDynamicCounter=0;	
}
void Battery_Voltage_Display(unsigned char BMP[])
{
   OLED_DrawBMP(0,0,39,8,BMP);
}
void Working_Mode_Display(unsigned char BMP[])
{
   OLED_DrawBMP(58,0,103,8,BMP);
}
void Warning_Display(unsigned char BMP[])
{
   OLED_DrawBMP(39,0,128,8,BMP);
}
void Area1Refresh_Display(unsigned char BMP[])
{	
    OLED_DrawBMP(103,4,128,8,BMP);  
}
void Area2Refresh_Display(unsigned char BMP[])
{
	OLED_DrawBMP(103,0,128,4,BMP);
}
void Area3Refresh_Display(unsigned char BMP[])
{
   OLED_DrawBMP(39,0,58,4,BMP);
}
void Area4Refresh_Display(unsigned char BMP[])
{
   OLED_DrawBMP(39,4,58,8,BMP);
}
void Charging_Display(void)   //充电时显示的画面
{
	if(ChargeState!=Charging||OverTemperatureProtectionFlag==1)//BatteryFullLockFlag==1||
	return;
//	BatteryFullLockFlag=0;
	if(BatteryFullLockFlag==0)
	{
		if(ChargingTimerUs++>=ChargingTimerUsThreshold)
		{
			if(ChargingTimerMs++>=ChargingTimerMsThreshold)
			{
				if(BatteryLevel<=1)
				{
					BatteryLevel=1;
				}
				if(BatteryLevel>=4)
				{
					BatteryLevel=4;
				}
				if(BatteryDisplayState++>=BatteryLevel)//BatteryLevel
				{
					BatteryDisplayState=0;
				}
				BatteryPageRefreshFlag=1;
				ChargingTimerMs=0;
				ChargingTimerUs=0;
				//P32=!P32;
			}
			ChargingTimerUs=0;
		}
		switch (BatteryDisplayState)
		{
			case 0 :
				BatteryBmp_p=BmpBatteryEmpty;
				break;
			case 1 :
				BatteryBmp_p=BmpBattery1Grid;
				break;
			case 2 :
				BatteryBmp_p=BmpBattery2Grid;
				break;
			case 3 :
				BatteryBmp_p=BmpBattery3Grid;
				break;	
			case 4 :
				BatteryBmp_p=BmpBattery4Grid;
				break;		
			default:
			break;
		}
	}
	else
	{
		BatteryBmp_p=BmpBattery4Grid;
		BatteryPageRefreshFlag=1;
	}
}
void AreaRefresh(void)  //刷牙分区显示
{
	if(OverTemperatureDisplayFlag==1||ChargeState==Charging||OverPressureHappenFlag==1) return;
	if(AreaRefreshFlag==1||AreaRefreshQuickRefreshFlag==1)
	{
		if(AreaRefreshDynamicCounter%2==1||AreaRefreshQuickRefreshFlag==1)
		{
		    if(CurrentArea==0)
			{
				Area1Refresh_Display(Area1);
				Area2Refresh_Display(Area2);
				Area3Refresh_Display(Area3);
				Area4Refresh_Display(Area4);
			}
			else if(CurrentArea==1)
			{
				Area1Refresh_Display(Area1OrArea2Claean);
				Area2Refresh_Display(Area2);
				Area3Refresh_Display(Area3);
				Area4Refresh_Display(Area4);		
			}
			else if(CurrentArea==2)
			{
				Area1Refresh_Display(Area1OrArea2Claean);
				Area2Refresh_Display(Area1OrArea2Claean);
				Area3Refresh_Display(Area3);
				Area4Refresh_Display(Area4);		
			}
			else if(CurrentArea==3)
			{
				Area1Refresh_Display(Area1OrArea2Claean);
				Area2Refresh_Display(Area1OrArea2Claean);
				Area3Refresh_Display(Area3OrArea4Claean);
				Area4Refresh_Display(Area4);		
			}
			else if(CurrentArea==4)
			{
				Area1Refresh_Display(Area1OrArea2Claean);
				Area2Refresh_Display(Area1OrArea2Claean);
				Area3Refresh_Display(Area3OrArea4Claean);
				Area4Refresh_Display(Area3OrArea4Claean);		
			}			
			AreaRefreshQuickRefreshFlag=0;
		}
		else
		{
		    if(CurrentArea==0)
			{
				Area1Refresh_Display(Area1OrArea2Claean);
//				Area2Refresh_Display(Area2);
//				Area3Refresh_Display(Area3);
//				Area4Refresh_Display(Area4);
			}
			else if(CurrentArea==1)
			{
				Area2Refresh_Display(Area1OrArea2Claean);
//				Area2Refresh_Display(Area2);
//				Area3Refresh_Display(Area3);
//				Area4Refresh_Display(Area4);		
			}
			else if(CurrentArea==2)
			{
				Area3Refresh_Display(Area3OrArea4Claean);
//				Area2Refresh_Display(Area1OrArea2Claean);
//				Area3Refresh_Display(Area3OrArea4Claean);
//				Area4Refresh_Display(Area4);		
			}
			else if(CurrentArea==3)
			{
				Area4Refresh_Display(Area3OrArea4Claean);
//				Area2Refresh_Display(Area1OrArea2Claean);
//				Area3Refresh_Display(Area3OrArea4Claean);
//				Area4Refresh_Display(Area3OrArea4Claean);		
			}		
		}
	}
	AreaRefreshFlag=0;	
}
void AreaRefresh_Dynamic_Handle(void)
{
	if(OverTemperatureDisplayFlag==1||ChargeState==Charging||OverPressureHappenFlag==1||VoltageLower3V0WarningFlag==1
		||Voltage3V0To3v3TurnOffFlag==1) return;
	if(AreaRefreshControlFlag==1)
	{
		if(AreaRefreshDynamicTimerUs++>=AreaRefreshDynamicTimerUsThreshold)
		{
			AreaRefreshDynamicTimerUs=0;
			if(AreaRefreshDynamicTimerMs++>=AreaRefreshDynamicTimerMsThreshold)
			{
				AreaRefreshDynamicCounter++;
				AreaRefreshFlag=1;
				AreaRefreshDynamicTimerUs=0;
				AreaRefreshDynamicTimerMs=0;
			}
		}
	}
//	else
//	{
//		AreaRefreshDynamicCounter=0;
//	}
}
void ModePageRefresh(void)  //档位转换刷新画面
{
//	if(ChargeState==Charging) return;
//	if(ChargeState==NoCharge)
//	{
		if(ModePageRefreshFlag==1)
		{
			Working_Mode_Display(ModeBmp_p);
			ModePageRefreshFlag=0;
		}
		else if(WaringPageRefreshFlag==1)
		{
			Warning_Display(ModeBmp_p);
			WaringPageRefreshFlag=0;
		}
//	}
//	else 
//	{
//		if(ModePageRefreshFlag==1)//&&ChargOnceRefreshFlag==0
//		{
//			Working_Mode_Display(ModeBmp_p);
//			ModePageRefreshFlag=0;
//		//	ChargOnceRefreshFlag=1;
//		}	
//	}
}
void WaringPage_Refresh(void)
{
	if(WaringPageRefreshFlag==1)
	{
		Warning_Display(ModeBmp_p);
		WaringPageRefreshFlag=0;
	}
}
void BatteryPageRefresh(void)   //电池电量变化时刷新画面
{
	if(BatteryPageRefreshFlag==1)
	{
		Battery_Voltage_Display(BatteryBmp_p);
		BatteryPageRefreshFlag=0;
	}
}
void Nunber_Show(u16 nunber)
{

}