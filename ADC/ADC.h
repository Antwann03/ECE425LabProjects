/**
 * @file ADC.h
 *
 * @brief Header file for the ADC driver.
 *
 * This file contains the function definitions for the ADC driver.
 *
 * ADC Module 0 is used to sample the potentiometer and the analog
 * light sensor that are connected on the EduBase board. ADC Module 0
 * is configured to sample the potentiometer first and the light sensor after.
 *
 * After the light sensor is sampled, an interrupt signal is set to 
 * indicate that the sampling sequence has ended. After the conversion
 * results have been read from the corresponding FIFO, the interrupt is cleared.
 *
 * The following pins are used:
 *  - Potentiometer   <-->  Tiva LaunchPad Pin PE2 (Channel 1)
 *  - Light Sensor    <-->  Tiva LaunchPad Pin PE1 (Channel 2)
 *
 * @ Antonio Anzora Jr
 *
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

/**
 * @brief	Initializes ADC0 for analog-to-digital conversion.
 *
 * Configures ADC0 to operate. It enables the clock, sets up the necessary GPIO pins, 
 * and configures ADC0 to process analog inputs. The function ensures ADC0 is ready for
 * sampling analog signals.
 * 
 * @param None
 *
 * @return None
 */
void ADC_Init(void);

/**
 * @brief	Samples analog input values using ADC0 and stores the result in a buffer.
 *
 * This function perfomrs analog-to-digital conversion using the ADC0. The analog
 * input values are read from the configures ADC channels, converted to digital values,
 * and stored in the provided buffer. The size of the buffer determines how many samples
 * can be processed in a single function call.
 *
 * @param	analog_value_buffer[] An array to store the sampled digital values.
 *
 * @return None
*/
void ADC_Sample(double analog_value_buffer[]);
