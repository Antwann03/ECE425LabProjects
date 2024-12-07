/*
 * @file main.c
 *
 * @brief Main source code for the UART program.
 *
 * This file contains the main entry point and function definitions for the UART program.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @Antonio Anzora Jr
 */
 //For Fun:
#include "TM4C123GH6PM.h"

#include "SysTick_Delay.h"
#include "UART0.h"

#include "GPIO.h"

#include <string.h>
#include <stdio.h>

#include "UART1.h"

int main(void)
{
	SysTick_Delay_Init();
	
//	UART0_Init();
	
//	RGB_LED_Init();
	//Task 3 (MAIN)
	UART1_Init();
	while(1)
	{
		/*
		UART0_Output_String("Hello World");
		UART0_Output_Newline();
		SysTick_Delay1ms(500);
		*/
/*
		MINI TASK 1: COMPLETE (DONE)
	//GOOD CODE
		char str_buffer[64];
		UART0_Output_String("Enter Your Name(s) : ");
		UART0_Input_String(str_buffer, 64);
		UART0_Output_Newline();
		UART0_Output_String("Name(s) Received: ");
		UART0_Output_String(str_buffer);
		UART0_Output_Newline();
		SysTick_Delay1ms(500);
		
	// GOOD CODE
		char data[64];
		UART0_Output_String("Enter a character: ");
		UART0_Input_String(data, 64);
		UART0_Output_Newline();
		UART0_Output_String("Character Received: ");
		UART0_Output_String(data);
		UART0_Output_Newline();
		SysTick_Delay1ms(500);
		
	//GOOD CODE	
		UART0_Output_String("Enter Decimal Number: ");
		uint32_t input_decimal = UART0_Input_Unsigned_Decimal();
		UART0_Output_Newline();
		UART0_Output_String("Decimal Received: ");
		UART0_Output_Unsigned_Decimal(input_decimal);
		UART0_Output_Newline();
		SysTick_Delay1ms(500);
	//GOOD CODE
		UART0_Output_String("Enter a hexadecimal value: ");
		uint32_t input_hexadecimal = UART0_Input_Unsigned_Hexadecimal();
		UART0_Output_Newline();
		UART0_Output_String("Hexadecimal Received: ");
		UART0_Output_Unsigned_Hexadecimal(input_hexadecimal);
		UART0_Output_Newline();
		SysTick_Delay1ms(500);
*/	

	//	MAIN TASK 1: COMPLETE (DONE)
//		MAIN TASK 2: COMPLETE(DONE) 
/*	
		char Invalid_CMD[64] = "Invalid Command. Try Again";
		char RGB_LED_RED_CMD[] = "RGB LED RED";
		char RGB_LED_GREEN_CMD[] = "RGB LED GREEN";
		char RGB_LED_BLUE_CMD[] = "RGB LED BLUE";
		char RGB_LED_CYCLE_CMD[] = "RGB LED CYCLE";
		
		UART0_Output_String("Enter Command: ");
		UART0_Input_String(Invalid_CMD, 64);	
		if(strcmp(Invalid_CMD, RGB_LED_RED_CMD) == 0)
		{
		RGB_LED_Output(RGB_LED_RED);
		SysTick_Delay1ms(1000);
		UART0_Output_Newline();
		}
		else if
			(strcmp(Invalid_CMD, RGB_LED_GREEN_CMD) == 0)
		{
		RGB_LED_Output(RGB_LED_GREEN);
		SysTick_Delay1ms(1000);
		UART0_Output_Newline();
		}
		else if
			(strcmp(Invalid_CMD, RGB_LED_BLUE_CMD) == 0)
		{
		RGB_LED_Output(RGB_LED_BLUE);
		SysTick_Delay1ms(1000);
		UART0_Output_Newline();
		}
		else if(strcmp(Invalid_CMD, RGB_LED_CYCLE_CMD) == 0)
		{
		RGB_LED_Output(RGB_LED_RED);
		SysTick_Delay1ms(1000);
		RGB_LED_Output(RGB_LED_GREEN);
		SysTick_Delay1ms(1000);
		RGB_LED_Output(RGB_LED_BLUE);
		SysTick_Delay1ms(1000);
		RGB_LED_Output(RGB_LED_OFF);
		SysTick_Delay1ms(1000);
		UART0_Output_Newline();

		}
		else
		{
		UART0_Output_Newline();
		UART0_Output_String("Invalid Command. Try Again");
		RGB_LED_Output(RGB_LED_OFF);
		SysTick_Delay1ms(1000);		
		UART0_Output_Newline();

		}
	}
	return 0;
}

*/

//Main Task 3:

		UART1_Output_Character(0xAA);
		SysTick_Delay1ms(500);
	}
}
