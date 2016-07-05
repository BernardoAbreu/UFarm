/*
 * reset.h
 */

#ifndef __RESET_H__
#define __RESET_H__

#include <iostream>
#include "time.h"


 class Reset{

    public:


        /**
         * Default Constructor
         *
         * Creates a new instance of object Reset.  It is initialized as not
         * available, so it doesn't reset at any time.
         */
        Reset();


        // constructor
        /**
         * Constructor
         *
         * Creates a new instance of object Reset using the values of Hour and
         * Minute of a Time object. It is set as available to set at the
         * initialized time.
         *
         * @param Time object with hour and minute values to be used
         */
        Reset(const Time&);


        /**
         * Constructor
         *
         * Creates a new instance of object Reset.
         *
         * @param int Hour to be reset
         * @param int Minute to be reset
         * @param book State to be resetted to.
         */
        Reset(int,int,bool);


        /**
         * Constructor
         *
         * Creates a new instance of object Reset.
         *
         * @param int Hour to be reset
         * @param int Minute to be reset
         */
        Reset(int,int);


        /**
         * Copy Constructor
         *
         * Creates a new instance of object Reset by copying from another one.
         */
        Reset(const Reset& t);


        // copy assignment
        /**
         * Copy Assignment
         *
         * Copies the values of instance of Reset to this one.
         */
        Reset& operator=(const Reset& v);


        /**
         * Get Method for minutes
         * @return Minutes of hour from 0 to 59}
         */
        int getMinute() const { return minute; }


        /**
         * Get Method for Hour
         * @return  Hours of day from 0 to 24
         */
  		int getHour() const { return  hour; }


  		/**
  		 * Get Method for State of Reset
  		 * @return False for closed, True for open
  		 */
  		bool getState() const { return state; }


  		/**
  		 * Get Method to check if reset is activated
  		 * @return True for Reset, False for not reset
  		 */
  		bool getAvailable() const { return available; }


  		/**
  		 * Set Method for minute
  		 * @param minutes of hour from 0 to 59
  		 */
        void setMinute(int m);


        /**
         * Set Method for hour
         * @param hours of day from 0 to 24
         */
  		void setHour(int h);


  		/**
  		 * Set Method for State
  		 * @param s True for Open, False for closed
  		 */
  		void setState(bool s) { state = s; }


  		/**
  		 * Set Method for availability of Reset
  		 * @param a True for available, False for not available.
  		 */
  		void setAvailable(bool a) { available = a; }


		/**
		 * Operator -
		 *
		 * Implements operator -.
		 * 
		 * @return double Difference in minutes
		 */
		friend double operator-(const Reset& r1, const Reset& r2);
		
		
		/**
		 * Put-to Operator
		 *
		 * Implements << operator
		 */
		friend ostream& operator<<(ostream& os, const Reset& r);
		

		/**
		 * Relational operators
		 *
		 * Compare hours and minutes.
		 */
		
		/**
		 * Implements < operator
		 */
		friend int operator<(const Reset& s1, const Reset& s2);


		/**
		 * Implements > Operator
		 */
		friend int operator>(const Reset& s1, const Reset& s2);


		/**
		 * Implements == operator
		 */
		friend int operator==(const Reset& s1, const Reset& s2);


		/**
		 * Implements != operator
		 */
		friend int operator!=(const Reset& r1, const Reset& r2) {
		    return !(r1 == r2);
		}


		/**
		 * Implements <= operator
		 */
		friend int operator<=(const Reset& r1, const Reset& r2) {
	    	return !(r1 > r2);
		}


		/**
		 * Implements >= operator
		 */
		friend int operator>=(const Reset& r1, const Reset& r2) {
		    return !(r1 < r2);
		}
    
    
    private:

		int hour;
		int minute;
		bool state;
		bool available;
};

#endif