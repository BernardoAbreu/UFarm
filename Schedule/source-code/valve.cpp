#include "valve.h"


/******************************************************************************/
// default constructor
Valve::Valve(){
	number = 0;
    state = false;
	code = 1111;
    valveState = false;
}
/******************************************************************************/


/******************************************************************************/
// constructor
Valve::Valve(int num){
	number = num;
    state = false;
	code = 11110 + num;
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
int Valve::sendState(bool st) {
//int Valve::sendState(RF24& radio, bool st) {
	unsigned long cd = code*10 + st;
	cout<< "\ncd: " << cd << endl;
	int error = sendcode(radio, cd);
	//int error = 0;
	cd << "error: " << error << endl;

	if (!error){
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
//bool Valve::readState() {
bool Valve::readState(RF24& radio) {
	unsigned long new_code;

	new_code = readcode(radio);
	//new_code = 100110;

	//TODO
	/***********************/
	//Error check
	/**********************/

	valveState = new_code%10;

	return this->getValveState();
}
/******************************************************************************/


/******************************************************************************/
//bool Valve::checkState() {
bool Valve::checkState(RF24& radio) {
	//this->readState();
	this->readState(radio);
	return (this->getValveState() == this->getState());
}
/******************************************************************************/