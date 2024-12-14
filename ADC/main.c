/*
 * @file main.c
 *
 * @brief Main source code for the ADC program.
 *
 * This file contains the main entry point and function definitions for the ADC program.
 *
 * It interfaces with the following:
 *  - EduBase Board Potentiometer (PE2)
 *  - EduBase Board Analog Light Sensor (PE1)
 *
 * @author
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "EduBase_LCD.h"
#include "ADC.h"

static double adc_buffer[8];

int main(void)
{
	//Initialize the SysTick timer used to provide blockign delay functions
	SysTick_Delay_Init();
	
	//Initialize the 16x2 LCD on the EduBase Board
	EduBase_LCD_Init();
	
	//Initialize the ADC0 module to sample the potentiometer (PE2)
	ADC_Init();
	
	EduBase_LCD_Enable_Display();
	EduBase_LCD_Clear_Display();
	
	EduBase_LCD_Set_Cursor(0, 0);
	EduBase_LCD_Display_String("Light Sensor");
	

	while(1)
	{	
/*		
		ADC_Sample(adc_buffer);
		EduBase_LCD_Set_Cursor(0, 1);
		EduBase_LCD_Display_Double(adc_buffer[0]);
		SysTick_Delay1ms(1000);
		*/
		ADC_Sample(adc_buffer);
		EduBase_LCD_Set_Cursor(0, 1);
		EduBase_LCD_Display_Double(adc_buffer[0]);
		SysTick_Delay1ms(1000);
	}
}
