#include "valve.h"


// default constructor
Valve::Valve(){
	number = 0;
    state = false;
	code = 100;
    valveState = false;
}

// constructor
Valve::Valve(int num){
	number = num;
    state = false;
	code = 100 + num;
    valveState = false;
}

// destructor
//˜Valve();

// copy constructor
Valve::Valve(const Valve& v){
	number = v.number;
    state = v.state;
	code = v.code;
    valveState = v.valveState;
}

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



int Valve::sendState(bool st) {
	unsigned long cd = code*10 + st;
	int error = sendcode(cd);

	if (!error){
		this->setState(bool st);
		return 0;
	}
	else{
		return 1;
	}
	
};

//TODO
bool Valve::readState() {
	unsigned long new_code;

	new_code = readcode();

	//TODO
	/***********************/
	//Error check
	/**********************/

	valveState = new_code%10;

	return this->getValveState();
}

bool Valve::checkState() {
	this->readState();
	return (this->getValveState() == this->getState());
}
		