
#ifndef __RFSIGNAL_H__
#define __RFSIGNAL_H__

#include <iostream>
#include <unistd.h>
#include <RF24/RF24.h>


/**
 * Setup function for radio
 *
 * @param radio Radio instance to transmit
 * @oaram uint8_t* First pipe to communicate
 * @param uint8_t* Second pipe to communicate
 */
void setup(RF24& radio, const uint8_t*, const uint8_t*);


/**
 * Sends a code through a rf signal using the radio.
 * @param  radio Radio instance to transmit the code
 * @param  long  Code to be transmitted
 * @return       0 if no error occurs, 1 if an error occurs
 */
int sendcode(RF24& radio, unsigned long);


/**
 * Read a code send by the radio
 * @param  radio Radio being used to communicate
 * @return       The code read
 */
unsigned long readcode(RF24& radio);

#endif