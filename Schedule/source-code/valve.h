#ifndef __VALVE_H__
#define __VALVE_H__

using namespace std;

class Valve{

	public:

		// default constructor
		Valve();

		// constructor
		Valve(int);

		// destructor
		//˜Valve();

		// copy constructor
		Valve(const Valve& v);

		// copy assignment
		Valve& operator=(const Valve& v);
		

		int getNumber() const { return number; }
        
        void setState(bool st) { state = st; }
        
    
    	bool getState() const { return state; }
        
        
    	void setValveState(bool st) { valveState = st; }
        
        
    	bool getValveState() const { return valveState; }
        

    	int sendState(bool);
    	
    	bool readState();
		
		bool checkState();
		
	
	private:

		int number;
        bool state;
        int code;
        bool valveState;
};

#endif