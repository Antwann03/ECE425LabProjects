/**
 * @file ADC.c
 *
 * @brief Source code for the ADC driver.
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

#include "ADC.h"


void ADC_Init(void)
{
	// Enable the clock to ADC Module 0 by setting the R0 bit (Bit 0) in the RCGCADC register
	// and provide a short delay of 1 ms after enabling the clock.
	SYSCTL -> RCGCADC |= 0x01;
	SysTick_Delay1ms(1);
	
	// Enable the clock to Port E by setting the R4 bit (Bit 4) in the RCGCGPIO register
	SYSCTL-> RCGCGPIO |= 0x10;
	
	// Configure the PE2 pin as an input by clearing Bit 2 in the DIR register.
	GPIOE -> DIR &= ~(0x04);
	
	// Disable the digital functionality for the PE2 pin by clearing Bit 2 in the DEN register
	GPIOE -> DEN &= ~(0x04);
	
	// Enable the analog functionality for the PE2 pin by setting Bit 2 in the AMSEL register
	GPIOE -> AMSEL |= 0x04;
	
	// Select the alternate function for the PE2 pin by setting Bit 2 in the AFSEL register.
	// This pin will be configured as an input analog source
	GPIOE -> AFSEL |= 0x04;
	
	// Before configuration, disable the Sample Sequencer 0 module by clearing the ASEN0
	// bit (Bit 0) in the ADC Active Sample Sequencer (ACTSS) register.
	ADC0 -> ACTSS &= ~0x1;
	
	// Select the event that initiates sampling for Sample Sequencer 0 module by clearing all of the 
	// bits in the EM0 field (Bits 3 to 0). This enables the Sample Sequencer 0 module to sample whenever
	// the SSn bit in the ADC Processro Sample Sequence Initiate (ADCPSSI) register is set.
	ADC0 -> EMUX &= ~0x000F;
	
	// Clear all of the bits (Bit 31 to 0) in the ADC Sample Sequence Input Multiplexer Select 0
	// ADCSMUX0) register before configuration.
	ADC0 -> SSMUX0 &= ~0xFFFFFFFF;

	// Choose Channel 1 (PE2, potentiometer) for the first sample by writing a value of 0x01 in the MUX0
	// field (Bits 3 to 0) in the ADC Sample Sequence Input Multiplexer Select Input Multiplexer Select 0
	// (ADCSSMUX0) register.
	ADC0 -> SSMUX0 |= 0x00000001;
	
	// Assign Channel 1 to be the end of the sampling sequence by setting the END0 bit (Bit 1) in the ADC 
	// Sample Sequence Control 0 (ADCSSCTL0) register.
	ADC0 -> SSCTL0 |= 00000002;
	
	// Enable the raw interrupt signal (INR0) for the samepl by setting the IE0 (Bit 2) in the ADC 
	// Sample Sequence Control 0 (ADCSSCTL0) register. The INR0 interrupt signal will be triggered at
	// the end of the first sample's conversion.
	ADC0 -> SSCTL0 |= 00000004;
	
	// Enable the Sample Sequencer 0 module by setting the ASEN0 bit (bit 0) in the ADC Active Sample 
	// Sequencer (ACTSS) register.
	ADC0 -> ACTSS |= 0x1;
	
	
	//Task 1 Code:
/*	 --DOES NOT WORK --
		SYSCTL -> RCGCADC |= 0x01;
		SysTick_Delay1ms(1);
		SYSCTL-> RCGCGPIO |= 0x10;
		GPIOE-> DIR &= 0x02;
		GPIOE->DEN &=~0x02;
		GPIOE ->AMSEL |= 0x02;
		GPIOE ->AFSEL |= 0x02;
		ADC0 -> ACTSS &= ~0x4;
		ADC0 -> EMUX &= ~0x0F00;
		ADC0 -> SSMUX1 &= ~0xFFFFFFFF;
		ADC0 -> SSMUX1 |= 0x00000010;
		ADC0 -> SSCTL1 |= 0x00000020;
		ADC0 -> SSCTL1 |= 0x00000040;
		ADC0 -> ACTSS |= 0x4;
*/
}

void ADC_Sample(double analog_value_buffer[])
{
	
	// Initiate the sampling process on the Sample Sequencer 0 module by setting the SS0
	// bit (Bit 0) in the ADC Processor Sample Sequence Initiate (ADCPSSI) register. Note
	// that the SS0 bit is a write-only bit, so it will be automatically cleared after setting it.
	ADC0 -> PSSI |= 0x01;
	
	// Wait until an interrupt has occured by checking the SS0 raw interrupt status bit
	// (INR0, Bit 0) in the ADC Raw Interrupt Status (ADCRIS) register. If the INR0 bit is set
	// to 1, then that indicates the end of the sampling sequence.
	while ((ADC0-> RIS & 0x01) == 0);
	
	// Read the conversion result for the sample collected by the Sample Sequencer 0 module
	// by reading the ADC Sample Sequence Result FIF0 (SSFIFO0) register.
	uint32_t potentiometer_sample_result = ADC0 -> SSFIFO0;
	
	// Clear the Interrupt signal by setting the IN0 bit (Bit 0) in the ADC Interrupt Status
	// and Clear (ADCISC) register.
	ADC0 -> ISC |= 0x01;
	
	// Calculate the measured analog voltage and store the result in a double array.
	analog_value_buffer[0] = (potentiometer_sample_result * 3.3 ) / 4096;
	
	
	/*	Task 1 Code:
	-- DOES NOT WORK --
	ADC0-> PSSI |= 0x04;
	while ((ADC0 ->RIS & 0x04) == 0);
	uint32_t light_sensor_sample_result = ADC0->SSFIFO2;
	ADC0-> ISC |=0x04;
	analog_value_buffer[0] = (light_sensor_sample_result * 3.3) / 4096;
*/	
}
