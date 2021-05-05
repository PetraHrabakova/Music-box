#include <avr/io.h>
#include <stdbool.h>

//Function definitions
void setupLEDonPORTB(unsigned char n)  // Sets PORTB.n to be an output
{
	DDRB |= (1<<n);
}

void setupBUTonPORTB(unsigned char n)  // Sets PORTB.n to be an input Button connected to ground
{
	DDRB &= ~(1<<n);
	PORTB |= (1<<n);
}

unsigned char getBUT(unsigned char n)  // Gets the immediate status of Button n (true for being pressed)
{
	if (0 == (PINB & (1<<n)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


