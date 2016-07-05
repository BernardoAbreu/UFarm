#ifndef __VALVE_H__
#define __VALVE_H__

#include rfsignal.h

using namespace std;

class Valve{

	public:


		/**
		 * Default Constructor
		 *
		 * Creates a new generic instance of the Valve.
		 * Initializes the number of valve as zero, both the state and 
		 * valveState as false and the code as 100.
		 */
		Valve();

		
		/**
		 * Constructor
		 *
		 * Creates a new instance of the valve.
		 * Initializes the number of valve with the parameter received, both
		 * the state and valveState as false and the code as 100.
		 *
		 * @param int The number of the valve to be created
		 */
		Valve(int);

		
		/**
		 * Copy Constructor
		 *
		 * Creates a new instance of Valve that is a copy of another one.
		 *
		 * @param const Valve& v The valve to be copied to the new one.
		 */
		Valve(const Valve& v);


		/**
		 * Copy Assignment
		 *
		 * Implements the operator "=".
		 * Copies the information of a different instance of Valve to this one.
		 * 
		 * @param const Valve& v Valve to be copied
		 * @return Reference to this valve.
		 */
		Valve& operator=(const Valve& v);
		

		/**
		 * Get method for returning valve number
		 * 
		 * @return Valve number
		 */
		int getNumber() const { return number; }
        

        /**
         * Set Method for defining the expetec state
         * @param st The state to be set
         */
        void setState(bool st) { state = st; }
        

    	/**
    	 * Get method for returning expected state
		 * 
		 * @return The expected Valve state
    	 */
    	bool getState() const { return state; }
        
        
        /**
         * Sets the actual state of the Valve. Uses sendState() function to
         * send the new State by radio.
         * 
         * @param bool The state to be set.
         */
    	void setValveState(bool st) { valveState = st; }
        

        /**
         * Get method for obtaining the actual state of the valve. Uses
         * readState() function to update the state inside the object.
         * 
         * @return The actual state of the Valve.
         */
    	bool getValveState() const { return valveState; }
        

    	/**
    	 * Sends the new state to the valve by radio.
    	 *
    	 * @param  bool The state to be sent
    	 * @return      An integer number. 0 if there is no error and different
    	 *              than 0 if there is.
    	 */
    	int sendState(bool);
    	

    	/**
    	 * Reads the actual state on the Valve by radio.
    	 * 
    	 * @return The actual state of the valve
    	 */
    	bool readState();
		

		/**
		 * Checks if the actual state of the is the same as the expected state
		 * 
		 * @return 1 if the state is correct, 0 if not.
		 */
		bool checkState();
		
	
	private:
		//Number to identify Valve
		int number;

		//Expected state of the Valve. true for open, false for closed
        bool state;

        //Code of the valve for radio communication
        int code;

        //Actual current state of the valve. true - open, false - closed
        bool valveState;
};

#endif