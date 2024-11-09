/**
 * @file Stepper_Motor.c
 *
 * @brief Source file for the Stepper_Motor driver.
 *
 * This file contains the function definitions for the Stepper_Motor driver. It uses
 * GPIO pins to provide output signals to the ULN2003 stepper motor driver.
 * 
 * The following components are used:
 *	-	28BYJ-48 5V Stepper Motor
 *  - ULN2003 Stepper Motor Driver
 *  - 3.3V / 5V Breadboard Power Supply Module (External Power Source)
 *
 * @author Aaron Nanas
 */

#include "Stepper_Motor.h"
#include "SysTick_Delay.h"
#include "Stepper_Motor.h"



void Stepper_Motor_Init()
{
	//Enable the clock to Port B by setting th e
	//R1 bit (Bit 1) in the RCGCGPIO register
	SYSCTL -> RCGCGPIO |= 0x02;
	
	//Configure the PB0, PB1, PB2, and PB3 pins as output
	//by setting Bits 3 to 0 in the DIR register
	GPIOB -> DIR |= 0x0F;
	
	//Configure teh PB0, PB1, PB2, and PB3 pins to the function as
	//GPIO pins by clearing Bits 3 to 0 in the AFSEL register
	GPIOB-> AFSEL &= ~(0x0F);
	
	//Enable the digital functionality for the PB0, PB1, PB2, and PB3 pins
	//by setting Bits 3 to 0 in the DEN register
	GPIOB-> DEN |= 0x0F;
	
	//Emable the clock to Port F by setting the 
	//R5 bit (Bit 5) in the RCGCGPIO register
	SYSCTL -> RCGCGPIO |= 0x20;
	
	//Configure the PF3 and PF2 pins as output
	//by setting Bits 3 to 0 in the DIR register
	GPIOF -> DIR |= 0x0C;
	
	//Configure the PF3 and PF2 pins to function as 
	//GPIO pins by clearing Bits 3 to 2 in the AFSEL register
	GPIOF -> AFSEL &= ~(0x0C);
	
	//Enable the digitial functionaloty for the PF3 and PF2 pins
	//by setting Bits 3 to 2 in the DEN register
	GPIOF -> DEN |= 0x0C;
	
	//Initialize the output of the PF3 and PF2 pins to high 
	//by setting Bits 3 to 2 in the DATA register
	GPIOF -> DATA |= 0x0C;
}
/** 
*	@brief
*
*	@param uint8_t  pmod_btn_status Indicates the status of the buttons on the PMOD BTN module.
*
*	@return None
*/
static uint8_t enable = 0;
static uint8_t direction_select = 0;
