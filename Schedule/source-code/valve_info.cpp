#include "valve_info.h"

/******************************************************************************/
//Default Constructor
Valve_info::Valve_info(){
    open = 0;
    closed = 0;
    check_time = 0;
}
/******************************************************************************/


/******************************************************************************/
//Constructor
Valve_info::Valve_info(Valve v, int o, int c){
    valve = v;
    open = o;
    closed = c;
    check_time = 60;
}
/******************************************************************************/


/******************************************************************************/
//Constructor
Valve_info::Valve_info(Valve v, int o, int c, Reset r){
    valve = v;
    open = o;
    closed = c;
    reset = r;
    check_time = 60;
}
/******************************************************************************/


/******************************************************************************/
//Constructor
Valve_info::Valve_info(Valve v, int o, int c, Reset r, int ct){
    valve = v;
    open = o;
    closed = c;
    reset = r;
    check_time = ct;

}
/******************************************************************************/


/******************************************************************************/
// copy constructor
Valve_info::Valve_info(const Valve_info& v){
    valve = v.valve;
    open = v.open;
    closed = v.closed;
    last_time = v.last_time;
    reset = v.reset;
    check_time = v.check_time;
    last_check = v.last_check;
}
/******************************************************************************/


/******************************************************************************/
// copy assignment
Valve_info& Valve_info::operator=(const Valve_info& v){

    if (this == &v) {
        return *this;
    }

    valve = v.valve;
    open = v.open;
    closed = v.closed;
    last_time = v.last_time;
    reset = v.reset;
    check_time = v.check_time;
    last_check = v.last_check;

    return *this;
}
/******************************************************************************/


/******************************************************************************/
// put-to operator
ostream& operator<<(ostream& os, const Valve_info& v){

    os << "Valve: " << v.valve.getNumber() << ": open - " << v.open 
        << ", closed - " << v.closed;

    return os;
}
/******************************************************************************/