
 /*
250 ms-delay   with a frequency of 8000 Hz and a prescaler of 1024
is reached at a count of 250/(256/8000000)   =   8    // accuracy might be improved here
Timer counter set to 247 (255 - 8 = 247) to reload
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "IOFunc.h"

 
const unsigned char sounddata_data[3][9536];	// 2 dimensional array storing 3 sounds (9536 bytes)		

unsigned int ptr_to_sound_array = 0;

uint8_t PlayStatus = 0;							// 1 for playing, 0 for not playing


// Interrupt service routine to avoid delays - ISR is started (audio is played)
// every time timer 0 overflows 

	ISR(TIMER0_OVF_vect)
	{
		TCNT0 = 247;						// Timer counter 0 set to 247
		if (PlayStatus == 1)
		{
			// These if statements decide about which audio will be played when 
			// different buttons are pressed
			
			if (getBUT(2)) {				// If button 1 is pressed, audio 1 (meow) is played 
				// Put out on PORTD (outputs to speaker) whatever you read in the array on position 1
				PORTD = (pgm_read_byte(&sounddata_data[0][ptr_to_sound_array]));
				// Runs through the whole thing and when reaches 3753, restarts (set PlayStatus to 0)
				ptr_to_sound_array++;
				if (ptr_to_sound_array >= 3753)
				{
					PlayStatus = 0;
					_delay_ms(1000);
				}
			}
			
			if (getBUT(3)) {				// If button 2 is pressed, audio 2 (dog) is played
				// Put out on PORTD (outputs to speaker) whatever you read in the array on position 2
				PORTD = (pgm_read_byte(&sounddata_data[1][ptr_to_sound_array]));
				// Runs through the whole thing and when reaches 2939, restarts (set PlayStatus to 0)
				ptr_to_sound_array++;
				if (ptr_to_sound_array >= 2939)
				{
					PlayStatus = 0;
					_delay_ms(1000);
					
				}
			}
			
			if (getBUT(4)) {				// If button 3 is pressed, audio 3 (frog) is played
				// Put out on PORTD (outputs to speaker) whatever you read in the array on position 3
				PORTD = (pgm_read_byte(&sounddata_data[2][ptr_to_sound_array]));
				// Runs through the whole thing and when reaches 2841, restarts (set PlayStatus to 0)
				ptr_to_sound_array++;
				if (ptr_to_sound_array >= 2841)
				{
					PlayStatus = 0;
					_delay_ms(1000);
					
				}
			}
		}
	}



void SoundSetup(void)
{
	DDRD = 0b11111111;						// Set DDRD as an output for R2R
	DDRB |= (1<<PORTB1);					
	TCCR1A |= (1<<COM1A1) | (1<<WGM10);		// Set up timer with prescaler = 256
	TCCR1B |= (1<<CS10) | (1<<WGM12);		// Set up timer with prescaler = 256
	TCCR0B |= (1 << CS02);					// Set up timer with prescaler = 256
	TCNT0 = 247;							// Initialize counter
	// Enable overflow interrupt
	TIMSK0 |= (1 << TOIE0);					// Error in original code TIMSK was chosen
	sei();									// Enable global interrupts
}

// Function to play audio 
void PlayNonBlocked(void)
{
	if (PlayStatus == 0)
	{
		PlayStatus = 1;
		ptr_to_sound_array = 0;
	}
}

// Function to stop audio 
void StopPlay(void)
{
	PlayStatus = 0;
}
