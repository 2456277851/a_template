#include "cms8s6990.h"
#include "working_handle.h"
#include "display.h"
#include "power_handle.h"
#include "over_temp_protection.h"
#include "main.h"
#include "key_scan.h"
#include "motor_buzzer_handle.h"
/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void INT0_IRQHandler(void)  interrupt INT0_VECTOR
{
}
/******************************************************************************
 ** \brief	 Timer 0 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer0_IRQHandler(void)  interrupt TMR0_VECTOR 
{
	TF0 = 0;
	TH0=Timer0IntervalHight;//(unsigned char)(temp>>8);   //设置定时初始值 (temp>>8)
	TL0=Timer0IntervalLow;
	Key_Delay_Turn_Off();	
//	Temp_Show_Flush_Timer();
//	Charge_Signal_Clean();
	Working_Handle();
	Over_Temp_Protection_Handle();
	Lower_Voltage_Warning_Handle();
	Charging_Display();
	AreaRefresh_Dynamic_Handle();
	Long_Press_AgingMode_OnOff();
	Motor_Buzzer_Handle();
	Long_Press_OverPressure_OnOff();
	Motor_Buzzer_Pitch_Handle();
}
/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void INT1_IRQHandler(void)  interrupt INT1_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	 Timer 1 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer1_IRQHandler(void)  interrupt TMR1_VECTOR 
{

}
/******************************************************************************
 ** \brief	 UART 0 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void UART0_IRQHandler(void)  interrupt UART0_VECTOR 
{

}
/******************************************************************************
 ** \brief	 Timer 2 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer2_IRQHandler(void)  interrupt TMR2_VECTOR 
{
	
}
/******************************************************************************
 ** \brief	 UART 1 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void UART1_IRQHandler(void)  interrupt UART1_VECTOR 
{
	;
}
/******************************************************************************
 ** \brief	 GPIO 0 interrupt service function
 **	
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P0EI_IRQHandler(void)  interrupt P0EI_VECTOR 
{
		;
}
/******************************************************************************
 ** \brief	 GPIO 1 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P1EI_IRQHandler(void)  interrupt P1EI_VECTOR 
{
	P1EXTIF=0x00;
	Charge_Signal_Handle();
}
/******************************************************************************
 ** \brief	 GPIO 2 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P2EI_IRQHandler(void)  interrupt P2EI_VECTOR 
{

}
/******************************************************************************
 ** \brief	 GPIO 3 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P3EI_IRQHandler(void)  interrupt P3EI_VECTOR 
{
	P3EXTIF=0x00;
//	P3EXTIE=0x00;
}

/******************************************************************************
 ** \brief	 LVD interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void LVD_IRQHandler(void)  interrupt LVD_VECTOR 
{

}
/******************************************************************************
 ** \brief	 LSE interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void LSE_IRQHandler(void)  interrupt LSE_VECTOR 
{

}

/********************************************************************************
 ** \brief	 ACMP interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void ACMP_IRQHandler(void)  interrupt ACMP_VECTOR 
{
	
}
/******************************************************************************
 ** \brief	 Timer 3 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer3_IRQHandler(void)  interrupt TMR3_VECTOR 
{

}
/******************************************************************************
 ** \brief	 Timer 4 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer4_IRQHandler(void)  interrupt TMR4_VECTOR 
{

}
/******************************************************************************
 ** \brief	 EPWM interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void EPWM_IRQHandler(void)  interrupt EPWM_VECTOR
{

}
/******************************************************************************
 ** \brief	 ADC interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void ADC_IRQHandler(void)  interrupt ADC_VECTOR 
{

}
/******************************************************************************
 ** \brief	 WDT interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void WDT_IRQHandler(void)  interrupt WDT_VECTOR 
{

}
/******************************************************************************
 ** \brief	I2C interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void I2C_IRQHandler(void)  interrupt I2C_VECTOR 
{
	;
}
/******************************************************************************
 ** \brief	SPI interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void SPI_IRQHandler(void)  interrupt SPI_VECTOR 
{
	;
}















