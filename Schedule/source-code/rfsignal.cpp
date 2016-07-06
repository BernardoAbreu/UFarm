#include "rfsignal.h"


/******************************************************************************/
void setup(RF24& radio, const uint8_t *pipe0, const uint8_t *pipe1){

  	// Setup and configure rf radio
  	radio.begin();

	// optionally, increase the delay between retries & # of retries
  	radio.setRetries(15,15);
  	// Dump the configuration of the rf unit for debugging
  	radio.printDetails();

	/***********************************/
  	// This simple sketch opens two pipes for these two nodes to communicate
  	// back and forth.

	radio.openWritingPipe(pipe1);
	radio.openReadingPipe(1,pipe0);

	radio.startListening();
}
/******************************************************************************/


/******************************************************************************/
int sendcode(RF24& radio, unsigned long code){
	int error = 0;

	// First, stop listening so we can talk.
	radio.stopListening();

	// Take the time, and send it.  This will block until complete

	printf("Now sending...\n");
	//unsigned long time = millis();

	bool ok = radio.write( &code, sizeof(unsigned long) );

	if (!ok){
		printf("failed.\n");
	}
	// Now, continue listening
	radio.startListening();

	// Wait here until we get a response, or timeout (250ms)
	unsigned long started_waiting_at = millis();
	bool timeout = false;
	while ( ! radio.available() && ! timeout ) {
		if (millis() - started_waiting_at > 200 )
			timeout = true;
	}


	// Describe the results
	if ( timeout )
	{
		printf("Failed, response timed out.\n");
		error = 1;
	}
	else
	{
		// Grab the response, compare, and send to debugging spew
		unsigned long got_code;
		radio.read( &got_code, sizeof(unsigned long) );

		// Spew it
		printf("Got response %lu, round-trip delay: %lu\n",
			got_code,millis()-got_code);

		if(got_code != ((code)%1000 + 202000)){
			error = 1;
		}
	}
	return error;
	//sleep(1);
}
/******************************************************************************/


/******************************************************************************/
unsigned long readcode(RF24& radio){
	unsigned long got_code;

	// if there is data ready
	if ( radio.available() ) {

		// Fetch the payload, and see if this was the last one.
		while(radio.available()){
			radio.read( &got_code, sizeof(unsigned long) );
		}
		radio.stopListening();
		
		radio.write( &got_code, sizeof(unsigned long) );

		// Now, resume listening so we catch the next packets.
		radio.startListening();

		// Spew it
		printf("Got payload(%d) %lu...\n",sizeof(unsigned long), got_code);
		
		//delay(925); //Delay after payload responded to, minimize RPi CPU time
	}
	return got_code;
}
/******************************************************************************/