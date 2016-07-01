/*
 * reset.h
 */

#ifndef __RESET_H__
#define __RESET_H__

#include <iostream>
#include "time.h"

 class Reset{

    public:

        // default constructor
        Reset();

        // constructor
        Reset(const Time&);

        Reset(int,int,int);

        Reset(int,int);

        // destructor
        //˜Reset();

        // copy constructor
        Reset(const Reset& t);

        // copy assignment
        Reset& operator=(const Reset& v);
        

        int getMinute() const { return minute; }    // minutes of hour from 0 to 59}
  
  		int getHour() const { return  hour; }    // hours of day from 0 to 24
  
  		bool getState() const { return state; }


        void setMinute(int m) { minute = m; }    // minutes of hour from 0 to 59}
  
  		void setHour(int h) { hour = h; }    // hours of day from 0 to 24
  
  		void setState(bool s) { state = s; }


		// operator-
		friend double operator-(const Reset& r1, const Reset& r2);
		
		// put-to operator
		friend ostream& operator<<(ostream& os, const Reset& r);
		

		// relational operators
		friend int operator<(const Reset& s1, const Reset& s2);
		friend int operator>(const Reset& s1, const Reset& s2);
		friend int operator==(const Reset& s1, const Reset& s2);
	
		friend int operator!=(const Reset& r1, const Reset& r2) {
		    return !(r1 == r2);
		}
	
		friend int operator<=(const Reset& r1, const Reset& r2) {
	    	return !(r1 > r2);
		}
	
		friend int operator>=(const Reset& r1, const Reset& r2) {
		    return !(r1 < r2);
		}
    
    private:

		int hour;
		int minute;
		bool state;
};

#endif