
#ifndef __RFSIGNAL_H__
#define __RFSIGNAL_H__

#include <iostream>
#include <unistd.h>
#include <RF24/RF24.h>


void setup(RF24& radio, const uint8_t*, const uint8_t*);

void sendcode(RF24& radio, unsigned long);

unsigned long readcode(RF24& radio);

#endif