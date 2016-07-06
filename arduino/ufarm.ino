
/*
  Getting Started example sketch for nRF24L01+ radios
  This is a very basic example of how to send data from one node to another
  Updated: Dec 2014 by TMRh20
*/


#include <SPI.h>
#include "RF24.h"

#define arduino_number 1
#define valve1 12
#define valve2 11
#define valve3 10
#define valve4 9

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7, 8);
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};
unsigned long code, ard, valve, state;
// Used to control whether this node is sending or receiving
int error = 0;

void getValues(unsigned long msg) {
  state = msg % 10;
  msg = msg / 10;
  valve = msg % 10;
  msg = msg / 10;
  ard = msg % 10;
  msg = msg / 10;
  code = msg;
}

void sendResponse() {
  unsigned long resp;
  
  resp = (unsigned long)202 * (unsigned long)1000;
  resp = resp + ard * 100;
  resp = resp + valve * 10;
  resp = resp + state;

  radio.write(&resp, sizeof(resp));
  Serial.print("Response ");
  Serial.print(resp);
  Serial.println(" sent.");
}

void sendError(){
  unsigned long resp;

  resp = (unsigned long)300 * (unsigned long)1000;
  resp = resp + ard * 100;
  resp = resp + valve * 10;
  resp = resp + state;

  radio.write(&resp, sizeof(resp));
  Serial.print("Response ");
  Serial.print(resp);
  Serial.println(" sent.");
}

void setup() {
  
  Serial.begin(115200);
  delay(5000);
  Serial.println("radio on");
  radio.begin();
  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  pinMode(valve1, OUTPUT);
  pinMode(valve2, OUTPUT);
  pinMode(valve3, OUTPUT);
  pinMode(valve4, OUTPUT);
  // Open a writing and reading pipe on each radio, with opposite addresses
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  // Start the radio listening for data
}

void loop() {
  radio.startListening();
  if (radio.available()) {
    unsigned long receivedMessage;
    radio.read(&receivedMessage, sizeof(receivedMessage));
    Serial.print("Got message ");
    Serial.println(receivedMessage);
    getValues(receivedMessage);
    if ((ard == arduino_number) && (code == 111) && ((valve > 0) && (valve < 5)) && ((state == 1) || (state == 0))) {
      
      switch (valve) {
        case 1:
          digitalWrite(valve1, state);
          break;
        case 2:
          digitalWrite(valve2, state);
          break;
        case 3:
          digitalWrite(valve3, state);
          break;
        case 4:
          digitalWrite(valve4, state);
          break;
      }
      radio.stopListening();
      sendResponse();
    }else{
      radio.stopListening();
      sendError();
    }
  }
}
