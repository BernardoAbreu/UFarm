/*
 * time.cpp
 */

#include <cstring>
#include <cstdio>

#include "time.h"

/******************************************************************************/
// default constructor
Time::Time() {
    this->getCurrentTime();
}
/******************************************************************************/


/******************************************************************************/
// constructor
Time::Time(const time_t time){
    now = time;
    ttme = localtime(&now);

}
/******************************************************************************/


/******************************************************************************/
//constructor
Time::Time(struct tm * time){

    now = mktime(time);
    ttme = localtime(&now);
}
/******************************************************************************/


/******************************************************************************/
// copy constructor 
Time::Time(const Time& t) {
    now = t.now;
    ttme = t.ttme;
}
/******************************************************************************/


/******************************************************************************/
// copy assignment
Time& Time::operator=(const Time& rhs){
    if (this == &rhs) {
	   return *this;
    }

    // copy from rhs
    now = rhs.now;
    ttme = rhs.ttme;

    return *this;
}
/******************************************************************************/


/******************************************************************************/
Time& Time::getCurrentTime(){
    now = time(0);          //Gets Current time
    ttme = localtime(&now);
    return *this;
}
/******************************************************************************/


/******************************************************************************/
double operator-(const Time& t1, const Time& t2){
    return  difftime ( t1.now, t2.now );         //Returns difference in seconds
}
/******************************************************************************/


/******************************************************************************/
// put-to operator
ostream& operator<<(ostream& os, const Time& t){
    os << ctime(&t.now);
    return os;
}
/******************************************************************************/