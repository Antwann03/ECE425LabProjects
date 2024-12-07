

/**
 * @file Buzzer.c
 *
 * @brief Source code for the Buzzer driver.
 *
 * This file contains the function definitions for the Buzzer driver.
 * It interfaces with the following:
 *	- DMT-1206 Magnetic Buzzer
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Aaron Nanas
 */
 
 
 
#include "Buzzer.h"
#include "GPIO.h"
// Constant definitions for the buzzer
const uint8_t BUZZER_OFF 		= 0x00;
const uint8_t BUZZER_ON			= 0x10;

// Constant definitions for musical notes
/*
const double C4_NOTE = 261.6;
const double D4_NOTE = 293.7;
const double E4_NOTE = 329.6;
const double F4_NOTE = 349.2;
const double G4_NOTE = 392.0;
const double A4_NOTE = 440.0;
const double B4_NOTE = 493.0;
*/



//0th Octave
 const double A0_NOTE = 27.50;
 const double B0_NOTE = 30.87;
 const double C0_NOTE = 16.35;
 const double D0_NOTE = 18.35;
 const double E0_NOTE = 20.60;
 const double F0_NOTE = 21.83;
 const double G0_NOTE = 24.50;
 const double Bb0_NOTE = 29.14;
 const double Csharp0_NOTE = 17.32;
 const double Eb0_NOTE = 19.45;
 const double Fsharp0_NOTE = 23.12;
 const double Gsharp0_NOTE = 25.96;
 

//1st Octave
 const double A1_NOTE = 55.00;
 const double B1_NOTE = 61.74;
 const double C1_NOTE = 32.70;
 const double D1_NOTE = 36.71;
 const double E1_NOTE = 41.20;
 const double F1_NOTE = 43.65;
 const double G1_NOTE = 49.00;
 const double Bb1_NOTE = 58.27;
 const double Csharp1_NOTE = 34.65;
 const double Eb1_NOTE = 38.39;
 const double Fsharp1_NOTE = 46.25;
 const double Gsharp1_NOTE = 51.91;

//2nd Octave
 const double A2_NOTE = 110.00;
 const double B2_NOTE = 123.50;
 const double C2_NOTE = 65.41;
 const double D2_NOTE = 73.42;
 const double E2_NOTE = 82.41;
 const double F2_NOTE = 87.31;
 const double G2_NOTE = 98.00;
 const double Bb2_NOTE = 116.50;
 const double Csharp2_NOTE = 69.30;
 const double Eb2_NOTE = 77.78;
 const double Fsharp2_NOTE = 92.50;
 const double Gsharp2_NOTE = 103.8;

//3rd Octave
 const double A3_NOTE = 220.00;
 const double B3_NOTE = 246.90;
 const double C3_NOTE = 130.80;
 const double D3_NOTE = 146.80;
 const double E3_NOTE = 164.80;
 const double F3_NOTE = 174.60;
 const double G3_NOTE = 196.00;
 const double Bb3_NOTE = 233.10 ;
 const double Csharp3_NOTE = 138.60;
 const double Eb3_NOTE = 155.60;
 const double Fsharp3_NOTE = 185.00;
 const double Gsharp3_NOTE = 207.70;

//4th Octave
 const double A4_NOTE = 440.00;
 const double B4_NOTE = 493.90;
 const double C4_NOTE = 261.60;
 const double D4_NOTE = 293.70;
 const double E4_NOTE = 329.60;
 const double F4_NOTE = 349.20;
 const double G4_NOTE = 392.00;
 const double Bb4_NOTE = 466.20; //Asharp4 is equivalen to Bb4 in Hz
 const double Csharp4_NOTE = 277.20;
 const double Eb4_NOTE = 311.10;
 const double Fsharp4_NOTE = 370.00;
 const double Gsharp4_NOTE = 415.30;

//5th Octave
 const double A5_NOTE = 880.00;
 const double B5_NOTE = 987.80;
 const double C5_NOTE = 523.30;
 const double D5_NOTE = 587.30;
 const double E5_NOTE = 659.30;
 const double F5_NOTE = 698.50;
 const double G5_NOTE = 784.00;
 const double Bb5_NOTE = 932.80;
 const double Csharp5_NOTE = 554.40;
 const double Eb5_NOTE = 622.30;
 const double Fsharp5_NOTE = 740.00;
 const double Gsharp5_NOTE = 830.60;

//6th Octave
 const double A6_NOTE = 1760.00;
 const double B6_NOTE = 1976.00;
 const double C6_NOTE = 1047.00;
 const double D6_NOTE = 1175.00;
 const double E6_NOTE = 1319.00;
 const double F6_NOTE = 1397.00;
 const double G6_NOTE = 1568.00;
 const double Bb6_NOTE = 1865.00;
 const double Csharp6_NOTE = 1109.00;
 const double Eb6_NOTE = 1245.00;
 const double Fsharp6_NOTE = 1480.00;
 const double Gsharp6_NOTE = 1661.00;

//7th Octave
 const double A7_NOTE = 3520.00;
 const double B7_NOTE = 3951.00;
 const double C7_NOTE = 2093.00;
 const double D7_NOTE = 2349.00;
 const double E7_NOTE = 2637.00;
 const double F7_NOTE = 2794.00;
 const double G7_NOTE = 3136.00;
 const double Bb7_NOTE = 3729.00;
 const double Csharp7_NOTE = 2217.00;
 const double Eb7_NOTE = 2489.00;
 const double Fsharp7_NOTE = 2960.00;
 const double Gsharp7_NOTE = 3322.00;

//8th Octave
 const double A8_NOTE = 7040.00;
 const double B8_NOTE = 7902.00;
 const double C8_NOTE = 4186.00;
 const double D8_NOTE = 4699.00;
 const double E8_NOTE = 5274.00;
 const double F8_NOTE = 5588.00;
 const double G8_NOTE = 6272.00;
 const double Bb8_NOTE = 7459.00;
 const double Csharp8_NOTE = 4435.00;
 const double Eb8_NOTE = 4978.00;
 const double Fsharp8_NOTE = 5920.00;
 const double Gsharp8_NOTE = 6645.00;


void Buzzer_Init(void)
{
	//Emable the clock to Port C
	SYSCTL -> RCGCGPIO |= 0X04;
	
	// Set PC4 as an ouput GPIO pin
	GPIOC -> DIR |= 0x10;
	
	//Configure PC4 to functuon as a GPIO pin
	GPIOC -> AFSEL &= ~0x10;
	
	//Enable digital functionality for PC4
	GPIOC -> DEN |= 0x10;
}
 
void Buzzer_Output(uint8_t buzzer_value)
{
	//Set the ouput of the buzzer
	GPIOC -> DATA = (GPIOC -> DATA & 0xEF) | buzzer_value;
}

void Play_Note(double note, unsigned int duration)
{
	//Calculate the period of the note in microseconds
	int period_us = (int)(((double)1/note) * ((double)1000000));
	
	//Calculate the half period of the noe in microseconds
	int half_period_us = period_us / 2;
	
	//Genertate a sqaure wave for the specified duration
	for (unsigned int i = 0; i < duration; i++)
	{
		Buzzer_Output(BUZZER_ON);
		SysTick_Delay1us(half_period_us);
		Buzzer_Output(BUZZER_OFF);
		SysTick_Delay1us(half_period_us);
	}
}
void Play_Super_Mario_Theme()
{
//Verse 0 
		Play_Note(E5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(100);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(C5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);	

		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(E4_NOTE, 100);

		Play_Note(A4_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		Play_Note(Bb4_NOTE, 100); //Asharp4=Bb4 in Hz terms
		Play_Note(A4_NOTE, 100);
		
		Play_Note(G4_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		
		SysTick_Delay1ms(50);
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(B4_NOTE, 100);

		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(E4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		Play_Note(Bb4_NOTE, 100); //Asharp4=Bb4 in Hz terms
		Play_Note(A4_NOTE, 100);

		Play_Note(G4_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(G5_NOTE, 100);

		SysTick_Delay1ms(50);
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		
//Verse 1		
		SysTick_Delay1ms(50);
		Play_Note(G5_NOTE, 100);
		Play_Note(Fsharp5_NOTE, 100); 
		Play_Note(F5_NOTE, 100);
		Play_Note(Eb5_NOTE, 100); //Dsharp = Eb5 in terms of Hz
		
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(C4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(A4_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		SysTick_Delay1ms(50);
		Play_Note(Eb5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);

//Verse 2 -- same as Verse 1
		SysTick_Delay1ms(50);
		Play_Note(G5_NOTE, 100);
		Play_Note(Fsharp5_NOTE, 100); 
		Play_Note(F5_NOTE, 100);
		Play_Note(Eb5_NOTE, 100); //Dsharp = Eb5 in terms of Hz
		
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(C4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(A4_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		SysTick_Delay1ms(50);
		Play_Note(Eb5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);	
		
//Verse 3 
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);
//Verse 4
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		
		SysTick_Delay1ms(50);
		
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		
		Play_Note(E5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(C5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
				
		Play_Note(G5_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);	

		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);	
		Play_Note(E4_NOTE, 100);

//Verse5
		Play_Note(A4_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		Play_Note(Bb4_NOTE, 100); //Asharp4=Bb4 in Hz terms
		Play_Note(A4_NOTE, 100);

		Play_Note(G4_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(G5_NOTE, 100);

		SysTick_Delay1ms(50);
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(B4_NOTE, 100);

//Verse 6:
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(E4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		Play_Note(Bb4_NOTE, 100); //Asharp4=Bb4 in Hz terms
		Play_Note(A4_NOTE, 100);

		Play_Note(G4_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(G5_NOTE, 100);

		SysTick_Delay1ms(50);
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(B4_NOTE, 100);

//Verse7
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		
		Play_Note(D5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(F5_NOTE, 100);

//Verse 8
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);

		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		
		Play_Note(B4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(C5_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(C4_NOTE, 100);
		
		//Verse 9:
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		
		Play_Note(D5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		
		//Verse10:
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);

		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(Gsharp4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		
		Play_Note(B4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(C5_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(C4_NOTE, 100);

		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(50);

//Verse 11:
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(C5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);

		Play_Note(E5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(E5_NOTE, 100);
		SysTick_Delay1ms(100);
		Play_Note(C5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		
		Play_Note(G5_NOTE, 100);
		SysTick_Delay1ms(50);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(50);

		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(100);
		Play_Note(Gsharp4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);

		
		Play_Note(D5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(A5_NOTE, 100);
		Play_Note(G5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		//Verse 12:
		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(G4_NOTE, 100);

		Play_Note(E5_NOTE, 100);
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		SysTick_Delay1ms(100);
		Play_Note(Gsharp4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(A4_NOTE, 100);

		Play_Note(B4_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(F5_NOTE, 100);
		Play_Note(E5_NOTE, 100);
		Play_Note(D5_NOTE, 100);
		
		Play_Note(C5_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		Play_Note(C4_NOTE, 100);
		//Verse13: THE END GAME OVER: 
		Play_Note(C5_NOTE, 100);
		Play_Note(G4_NOTE, 100);
		Play_Note(E4_NOTE, 100);
		
		Play_Note(A4_NOTE, 100);
		Play_Note(B4_NOTE, 100);
		Play_Note(A4_NOTE, 100);
		Play_Note(Gsharp0_NOTE, 100);
		Play_Note(Bb4_NOTE, 100); //Asharp 4 = Bb4 in terms of Hz
		
		Play_Note(G4_NOTE, 100);
		Play_Note(D4_NOTE, 100);
		Play_Note(E4_NOTE, 100);
	}
