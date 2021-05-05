/*
 * Sound_module.c
 *
 * Created: 26/04/2021 09.06.23
 * Author : Petra
 */ 

#define F_CPU 8000000
#include "Soundmodule.h"
#include "IOfunc.h"
#include "Audio.h"
#include <util/delay.h>
#include <avr/pgmspace.h>

int main(void)
{
	SoundSetup();								// Initialize timer and setup ports
	setupBUTonPORTB(2);							// Setup button 1 on PB2
	setupBUTonPORTB(3);							// Setup button 2 on PB3
	setupBUTonPORTB(4);							// Setup button 3 on PB4
	
	while (1)
	{
		if (getBUT(2)) PlayNonBlocked();		// If button 1 is pressed, play audio 
		if (getBUT(3)) PlayNonBlocked();		// If button 2 is pressed, play audio 
		if (getBUT(4)) PlayNonBlocked();		// If button 3 is pressed, play audio 
												// It is decided in the ISR routine which audio to play
	}
}


