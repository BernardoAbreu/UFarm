
#ifndef __RFSIGNAL_H__
#define __RFSIGNAL_H__

#include <iostream>
#include <unistd.h>
#include <RF24/RF24.h>


void setup(const uint8_t*, const uint8_t*);

void sendcode(unsigned long);

unsigned long readcode();

#endif