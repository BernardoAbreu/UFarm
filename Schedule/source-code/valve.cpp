#include "valve.h"


/******************************************************************************/
// default constructor
Valve::Valve(){
	number = 0;
    state = false;
	code = 11100;
    valveState = false;
}
/******************************************************************************/


/******************************************************************************/
// constructor
Valve::Valve(int num){
	number = num;
    state = false;
	code = 11100 + ((num-1)%4 + 1)*10 + num;
    valveState = false;
}
/******************************************************************************/


/******************************************************************************/
// constructor
Valve::Valve(int cluster, int num){
	number = 4*(cluster-1) + num;
    state = false;
	code = 11100 + cluster*10 + num;
    valveState = false;
}
/******************************************************************************/


/******************************************************************************/
// copy constructor
Valve::Valve(const Valve& v){
	number = v.number;
    state = v.state;
	code = v.code;
    valveState = v.valveState;
}
/******************************************************************************/


/******************************************************************************/
// copy assignment
Valve& Valve::operator=(const Valve& v){
	if (this == &v) {
		return *this;
	}

	number = v.number;
    state = v.state;
	code = v.code;
    valveState = v.valveState;
	
	return *this;
}
/******************************************************************************/


/******************************************************************************/
//TODO
int Valve::sendState(RF24& radio, bool st) {
	unsigned long cd = code*10 + st;
	
	int error = sendcode(radio, cd);

	if (error){
		this->setState(st);
		return 0;
	}
	else{
		return 1;
	}
	
}
/******************************************************************************/


/******************************************************************************/
//TODO
bool Valve::readState(RF24& radio) {
	unsigned long new_code;
	unsigned long cd = (code-100)*10;

	new_code = sendcode(radio, cd);

	//TODO
	/***********************/
	//Error check
	if ((new_code/1000) == 300){
		cerr << "Error on valve " << number << endl;
	}

	/**********************/

	valveState = new_code%10;

	return this->getValveState();
}
/******************************************************************************/


/******************************************************************************/
bool Valve::checkState(RF24& radio) {
	this->readState(radio);
	return (this->getValveState() == this->getState());
}
/******************************************************************************/