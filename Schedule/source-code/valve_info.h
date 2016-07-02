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
    // constructor
    //Valve(Valve);
    Valve_info();

    Valve_info(Valve, int, int);

    Valve_info(Valve, int, int , Reset);

    Valve_info(Valve, int, int , Reset, int);
    
    // destructor
    //~Valve_info();

    // copy constructor
    Valve_info(const Valve_info& v);

    // copy assignment
    Valve_info& operator=(const Valve_info& v);
    

    Valve& getValve() { return valve; }
        
    int getOpen() const { return open; }

    int getClosed() const { return closed; }

    Time& getLastTime() { return last_time; }
    
    Reset& getReset() { return reset; }

    int getCheckTime() const { return check_time; }

    Time& getLastCheck() { return last_check; }


    void setValve(Valve v) { valve = v; }
        
    void setOpen(int o) { open = o; }

    void setClosed(int c) { closed = c; }

    void setLastTime(Time t) { last_time = t; }
    
    void setReset(Reset r) { reset = r; }

    void setCheckTime(int t) { check_time = t; }

    void setLastCheck(Time t) { last_check = t;}

    // put-to operator
    friend ostream& operator<<(ostream& os, const Valve_info& v);

        // relational operators
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

    Valve valve;
    int open;
    int closed;
    Time last_time;
    Reset reset;
    int check_time;
    Time last_check;
};

#endif