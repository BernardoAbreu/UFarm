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

      /**
       * Default Constructor
       *
       * Creates a new instance of object time initialized with time at
       * the moment of creation.
       */
      Time();


      /**
       * Constructor
       *
       * Constructs a time object using time_t from ctime.
       */
      Time(const time_t time);


      /**
       * Constructor
       *
       * Constructs a time object using a struct tm from ctime.
       */
      Time(struct tm * time);


      /**
       * Copy Constructor
       *
       * Constructs a new Time object that is a copy of another one.
       */
      Time(const Time& t);


      /**
       * Copy Assignment
       *
       * Implements the = operator. Copies the information of a time object to
       * this one.
       *
       * @return The new object time.
       */
      Time& operator=(const Time& v);


      /**
       * Updates the time, getting the current one.
       * 
       * @return The time object updated
       */
      Time& getCurrentTime();


      /**
       * Get Method for second
       * @return Integer from 0 to 61 corresponding to seconds of minutes
       */
      int getSecond() const { return ttme->tm_sec; }


      /**
       * Get Method for minute
       * @return Integer from 0 to 59 corresponding to minutes of hour
       */
      int getMinute() const { return ttme->tm_min; }


      /**
       * Get Method for hour
       * @return Integer from 0 to 24 corresponding to hours of day
       */
  		int getHour() const { return  ttme->tm_hour; }


      /**
       * Get Method for day
       * @return Integer from 1 to 31 corresponding to day of month
       */
  		int getDay() const { return ttme->tm_mday; }


      /**
       * Get Method for the month
       * @return Integer from 0 to 11 corresponding to month of year
       */
  		int getMonth() const { return ttme->tm_mon + 1; }


      /**
       * Get Method for the year
       * @return Integer corresponding to year since 1900
       */
  		int getYear() const { return ttme->tm_year + 1900; }


      /**
       * Get Method for the day of the week
       * @return Integer corresponding to number days since sunday
       */
  		int getWeekDay() const { return ttme->tm_wday; }


      /**
       * Get method for days since January 1st
       * @return Integer corresponding to the days since January 1st
       */
  		int getYearDay() const { return ttme->tm_yday; }


      /**
       * Get method for hours of daylight savings time
       * @return Integer with the hours of daylight savings time
       */
  		int getHourDST() const { return ttme->tm_isdst; }


    /**
     * Operator -
     *
     * Implements - operator. Returns the difference between the two Time
     * objects in seconds.
     */
		friend double operator-(const Time& s1, const Time& s2);


    /**
     * Put-to Operator
     *
     * Implements << operator.
     */
		friend ostream& operator<<(ostream& os, const Time& s);


    //Relational operators
    /**
     * Operator <
     *
     * Implements < operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator<(const Time& t1, const Time& t2) {
        return (t1-t2) < 0;
    }


    /**
     * Operator >
     *
     * Implements > operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator>(const Time& t1, const Time& t2){
        return (t1-t2) > 0;
    }


    /**
     * Operator ==
     *
     * Implements == operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator==(const Time& t1, const Time& t2){
        return (t1-t2) == 0;
    }


    /**
     * Operator !=
     *
     * Implements != operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator!=(const Time& t1, const Time& t2) {
		    return !(t1 == t2);
		}


    /**
     * Operator <=
     *
     * Implements <= operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator<=(const Time& t1, const Time& t2) {
	    	return !(t1 > t2);
		}


    /**
     * Operator >=
     *
     * Implements >= operator. Return 1 if comparison is true
     * and 0 if it is not.
     */
		friend int operator>=(const Time& t1, const Time& t2) {
		    return !(t1 < t2);
		}
    

    private:

        time_t now;
        tm *ttme;
};

#endif