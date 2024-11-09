/**
 * @file Stepper_Motor.h
 *
 * @brief Header file for the Stepper_Motor driver.
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

#include "TM4C123GH6PM.h"

/**
 * @brief	The Stepper_Motor_Init function initializes the GPIO pins to provide
 *	output signals to the ULN2003 stepper motor driver.
 *	
 *	This function initializes ther stepper motor by configuring GPIO pins on
 *	Port B and Port F of the TM4C123GH6PM microcontroller. The function enables 
 *	clock for ports we used, sets up the pins as outputs, configures them to work
 *	as GPIO pins, and enables their digital functionality. 
 *
 * @param None
 *
 * @return None
 */
void Stepper_Motor_Init();
