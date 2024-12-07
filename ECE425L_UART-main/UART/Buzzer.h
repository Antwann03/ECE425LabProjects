/**
 * @file Buzzer.h
 *
 * @brief Header file for the Buzzer driver.
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
 
#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "GPIO.h"

// Constant definitions for the buzzer
extern const uint8_t BUZZER_OFF;
extern const uint8_t BUZZER_ON;

// Constant definitions for musical notes

//0th Octave
extern const double A0_NOTE;
extern const double B0_NOTE;
extern const double C0_NOTE;
extern const double D0_NOTE;
extern const double E0_NOTE;
extern const double F0_NOTE;
extern const double G0_NOTE;
extern const double Bb0_NOTE;
extern const double Csharp0_NOTE;
extern const double Eb0_NOTE;
extern const double Fsharp0_NOTE;
extern const double Gsharp0_NOTE;

//1st Octave
extern const double A1_NOTE;
extern const double B1_NOTE;
extern const double C1_NOTE;
extern const double D1_NOTE;
extern const double E1_NOTE;
extern const double F1_NOTE;
extern const double G1_NOTE;
extern const double Bb1_NOTE;
extern const double Csharp1_NOTE;
extern const double Eb1_NOTE;
extern const double Fsharp1_NOTE;
extern const double Gsharp1_NOTE;

//2nd Octave
extern const double A2_NOTE;
extern const double B2_NOTE;
extern const double C2_NOTE;
extern const double D2_NOTE;
extern const double E2_NOTE;
extern const double F2_NOTE;
extern const double G2_NOTE;
extern const double Bb2_NOTE;
extern const double Csharp2_NOTE;
extern const double Eb2_NOTE;
extern const double Fsharp2_NOTE;
extern const double Gsharp2_NOTE;

//3rd Octave
extern const double A3_NOTE;
extern const double B3_NOTE;
extern const double C3_NOTE;
extern const double D3_NOTE;
extern const double E3_NOTE;
extern const double F3_NOTE;
extern const double G3_NOTE;
extern const double Bb3_NOTE;
extern const double Csharp3_NOTE;
extern const double Eb3_NOTE;
extern const double Fsharp3_NOTE;
extern const double Gsharp3_NOTE;

//4th Octave
extern const double A4_NOTE;
extern const double B4_NOTE;
extern const double C4_NOTE;
extern const double D4_NOTE;
extern const double E4_NOTE;
extern const double F4_NOTE;
extern const double G4_NOTE;
extern const double Bb4_NOTE;
extern const double Csharp4_NOTE;
extern const double Eb4_NOTE;
extern const double Fsharp4_NOTE;
extern const double Gsharp4_NOTE;

//5th Octave
extern const double A5_NOTE;
extern const double B5_NOTE;
extern const double C5_NOTE;
extern const double D5_NOTE;
extern const double E5_NOTE;
extern const double F5_NOTE;
extern const double G5_NOTE;
extern const double Bb5_NOTE;
extern const double Csharp5_NOTE;
extern const double Eb5_NOTE;
extern const double Fsharp5_NOTE;
extern const double Gsharp5_NOTE;

//6th Octave
extern const double A6_NOTE;
extern const double B6_NOTE;
extern const double C6_NOTE;
extern const double D6_NOTE;
extern const double E6_NOTE;
extern const double F6_NOTE;
extern const double G6_NOTE;
extern const double Bb6_NOTE;
extern const double Csharp6_NOTE;
extern const double Eb6_NOTE;
extern const double Fsharp6_NOTE;
extern const double Gsharp6_NOTE;

//7th Octave
extern const double A7_NOTE;
extern const double B7_NOTE;
extern const double C7_NOTE;
extern const double D7_NOTE;
extern const double E7_NOTE;
extern const double F7_NOTE;
extern const double G7_NOTE;
extern const double Bb7_NOTE;
extern const double Csharp7_NOTE;
extern const double Eb7_NOTE;
extern const double Fsharp7_NOTE;
extern const double Gsharp7_NOTE;

//8th Octave
extern const double A8_NOTE;
extern const double B8_NOTE;
extern const double C8_NOTE;
extern const double D8_NOTE;
extern const double E8_NOTE;
extern const double F8_NOTE;
extern const double G8_NOTE;
extern const double Bb8_NOTE;
extern const double Csharp8_NOTE;
extern const double Eb8_NOTE;
extern const double Fsharp8_NOTE;
extern const double Gsharp8_NOTE;
extern const double Asharp8_NOTE;

/**
 * @brief Initializes the DMT-1206 Magnetic Buzzer on the EduBase board.
 *
 * This function configures the PC4 pin used by the DMT-1206 Magnetic Buzzer.
 * It enables the clock to Port C, sets PC4 as an output GPIO pin, configures PC4 to function as a GPIO pin,
 * and enables digital functionality for PC4.
 *
 * @param None
 *
 * @return None
 */
void Buzzer_Init(void);

/**
 * @brief Sets the output of the DMT-1206 Magnetic Buzzer.
 *
 * This function sets the output of the buzzer based on the value of the input, buzzer_value.
 * A bitwise AND operation (& 0xEF) is performed to mask Bit 4 of the GPIOC's DATA register
 * to preserve the state of other pins connected to Port C while keeping the buzzer pin unaffected.
 * Then, a bitwise OR operation is performed with buzzer_value to set the buzzer pin to the desired state
 * specified by buzzer_value.
 *
 * @param buzzer_value An 8-bit unsigned integer that determines the output of the buzzer. To turn off
 *                      the buzzer, set buzzer_value to 0. To turn on the buzzer, set buzzer_value to 0x10.
 *
 * @return None
 */
void Buzzer_Output(uint8_t buzzer_value);

/**
 * @brief Plays a note with the DMT-1206 Magnetic Buzzer.
 *
 * This function generates a square wave with the DMT-1206 Magnetic Buzzer to produce a note of the specified frequency and duration.
 * It calculates the period of the note in microseconds, divides it by two to get half period, and then toggles the
 * buzzer output at the half period interval for the specified duration.
 *
 * @param note The frequency of the note to play in Hz.
 *
 * @param duration The duration of the note in microseconds.
 *
 * @return None
 */
void Play_Note(double note, unsigned int duration);
void Note_Controller(uint8_t button_status);

void Play_Super_Mario_Theme();