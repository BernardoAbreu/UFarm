/*
 * time.h
 */

#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include <ctime>

using namespace std;

class Time{

    public:

      // default constructor
      Time();

      // constructor
      Time(const time_t time);

      Time(struct tm * time);

      // destructor
      //˜Time();

      // copy constructor
      Time(const Time& t);

      // copy assignment
      Time& operator=(const Time& v);

      Time& getCurrentTime();

      int getSecond() const { return ttme->tm_sec; }    // seconds of minutes from 0 to 61

      int getMinute() const { return ttme->tm_min; }    // minutes of hour from 0 to 59}
  
  		int getHour() const { return  ttme->tm_hour; }    // hours of day from 0 to 24
  
  		int getDay() const { return ttme->tm_mday; }      // day of month from 1 to 31

  		int getMonth() const { return ttme->tm_mon + 1; }     // month of year from 0 to 11

  		int getYear() const { return ttme->tm_year + 1900; }     // year since 1900

  		int getWeekDay() const { return ttme->tm_wday; }  // days since sunday

  		int getYearDay() const { return ttme->tm_yday; }  // days since January 1st

  		int getHourDST() const { return ttme->tm_isdst; } // hours of daylight savings time


		// operator-
		friend double operator-(const Time& s1, const Time& s2);
		
		// put-to operator
		friend ostream& operator<<(ostream& os, const Time& s);
		

		// relational operators
		friend int operator<(const Time& s1, const Time& s2);
		friend int operator>(const Time& s1, const Time& s2);
		friend int operator==(const Time& s1, const Time& s2);
	
		friend int operator!=(const Time& s1, const Time& s2) {
		    return !(s1 == s2);
		}
	
		friend int operator<=(const Time& s1, const Time& s2) {
	    	return !(s1 > s2);
		}
	
		friend int operator>=(const Time& s1, const Time& s2) {
		    return !(s1 < s2);
		}
    
    private:

        time_t now;
        tm *ttme;
};

#endif