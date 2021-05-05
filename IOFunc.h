/*
 * IOFunc.h
 *
 * Created: 26/04/2021 09.10.25
 *  Author: Petra
 */ 


#ifndef IOFUNC_H_
#define IOFUNC_H_

//Function declarations.
void setupLEDonPORTB(unsigned char n);  //sets PORTB.n to be an output
void setupBUTonPORTB(unsigned char n);  //sets PORTB.n to be an input Button connected to ground
unsigned char getBUT(unsigned char n);  //  gets the immediate status of Button n....true for being pressed
void setLED(unsigned char n, unsigned char flag);  // sets the output value on pin PORTB.n. High if flag is true



#endif /* IOFUNC_H_ */