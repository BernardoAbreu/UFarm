/*
 * valve_info.h
 */

#ifndef __VINFO_H__
#define __VINFO_H__

#include <iostream>
#include "valve.h"
#include "time.h"
#include "reset.h"

using namespace std;

class Valve_info{

  public:


    /**
     * Default Constructor
     *
     * Creates a new intance of Valve_info.
     */
    Valve_info();


    /**
     * Constructor
     *
     * Constructs a new instance of Valve_info from a Valve instance, 
     * an open time and a closed time interval
     *
     * @param Valve Valve instance
     * @param int Time interval open
     * @param int Time interval closed
     */
    Valve_info(Valve, int, int);


    /**
     * Constructor
     *
     * Constructs a new instance of Valve_info from a Valve instance, 
     * an open time, a closed time and Reset information
     *
     * @param Valve Valve instance
     * @param int Time interval open
     * @param int Time interval closed
     * @param Reset Reset instance
     */
    Valve_info(Valve, int, int , Reset);


    /**
     * Constructor
     *
     * Constructs a new instance of Valve_info from a Valve instance, 
     * an open time, a closed time, Reset information a time interval
     * between checks
     *
     * @param Valve Valve instance
     * @param int Time interval open
     * @param int Time interval closed
     * @param Reset Reset instance
     * @param int Time between checks
     */
    Valve_info(Valve, int, int , Reset, int);


    /**
     * Copy Constructor
     *
     * Creates a new instance of Valve_info by copying another one
     *
     * @param Object to be copied
     */
    Valve_info(const Valve_info& v);


    /**
     * Copy Assignment
     *
     * Copies the content of a Valve_info instance to this one
     *
     * @param Object to be copied
     */
    Valve_info& operator=(const Valve_info& v);
    

    /**
     * Get Method for valve
     * @return Valve object
     */
    Valve& getValve() { return valve; }


    /**
     * Get Method for time valve spend open
     * @return Time interval valve spends open
     */
    int getOpen() const { return open; }


    /**
     * Get Method for time valve spend closed
     * @return Time interval valve spends closed
     */
    int getClosed() const { return closed; }


    /**
     * Get Method for last time valve was checked
     * @return Time Object of last time valve was checked
     */
    Time& getLastTime() { return last_time; }


    /**
     * Get Method for reset
     * @return Reset object of the valve
     */
    Reset& getReset() { return reset; }


    /**
     * Get Method for check time
     * @return Minutes between checks
     */
    int getCheckTime() const { return check_time; }


    /**
     * Get Method for last Check
     * @return Time object
     */
    Time& getLastCheck() { return last_check; }


    /**
     * Set Method for valve
     * @param v Valve object
     */
    void setValve(Valve v) { valve = v; }


    /**
     * Set method for time interval valve spends open
     * @param o Minutes valve spends open
     */
    void setOpen(int o) { open = o; }


    /**
     * Set method for time interval valve spends closed
     * @param c Minutes valve spends closed
     */
    void setClosed(int c) { closed = c; }


    /**
     * Set method for last time valve was checked
     * @param t Time object
     */
    void setLastTime(Time t) { last_time = t; }


    /**
     * Set method for the valve Reset
     * @param r Reset object
     */
    void setReset(Reset r) { reset = r; }


    /**
     * Set Method for check Time. Time interval between checks
     * @param t Integer corresponding to minutes between each check
     */
    void setCheckTime(int t) { check_time = t; }


    /**
     * Set Method for last time the valve was checked
     * @param t Time object referring to last check
     */
    void setLastCheck(Time t) { last_check = t;}


    /**
     * Put-to Operator
     *
     * Implements << operator
     */
    friend ostream& operator<<(ostream& os, const Valve_info& v);


    /**
     * Relational Operators
     */
    
    friend int operator<(const Valve_info& v1, const Valve_info& v2){
      return (v1.valve.getNumber() < v2.valve.getNumber());
    }

    friend int operator>(const Valve_info& v1, const Valve_info& v2){
      return (v1.valve.getNumber() > v2.valve.getNumber());
    }
    friend int operator==(const Valve_info& v1, const Valve_info& v2){
      return (v1.valve.getNumber() == v2.valve.getNumber());
    }
  
    friend int operator!=(const Valve_info& v1, const Valve_info& v2) {
        return !(v1 == v2);
    }
  
    friend int operator<=(const Valve_info& v1, const Valve_info& v2) {
        return !(v1 > v2);
    }
  
    friend int operator>=(const Valve_info& v1, const Valve_info& v2) {
        return !(v1 < v2);
    }
    
  
  private:

    //Valve instance
    Valve valve;

    //Minutes that the valve spend open
    int open;

    //Minutes that the valve spend closed
    int closed;

    //Las time the valve was checked
    Time last_time;

    //Reset of the valve
    Reset reset;

    //Time interval between checks in minutes
    int check_time;

    //Time of last check
    Time last_check;
};

#endif