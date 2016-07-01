/*
 * time.cpp
 */

#include <cstring>
#include <cstdio>

#include "time.h"

// default constructor

Time::Time() {
    now = time(0);

    ttme = localtime(&now);
}

// constructor

Time::Time(const time_t time){
    now = time;

    ttme = localtime(&now);

}

Time::Time(const struct tm * time){
    now = mktime(time);

    ttme = time;

}

// destructor
//Time::~Time() {}


// copy constructor 

Time::Time(const Time& t) {
    now = t.now;
    
    ttme = t->ttme;
}

// copy assignment

Time& Time::operator=(const Time& rhs){

    if (this == &rhs) {
	return *this;
    }

    // now copy from rhs
    
    now = rhs.now;

    ttme = rhs->ttme;

    return *this;
}

Time& Time::getCurrentTime(){
    now = time(0);

    ttme = localtime(&now);

    return *this;
}


double operator-(const Time& t1, const Time& t2){
    return  difftime ( t1.now, t2.now );
}


// put-to operator

ostream& operator<<(ostream& os, const Time& t){
    os << ctime(&t.now);
    return os;
}

// relational operators

int operator<(const Time& t1, const Time& t2){
    return (t1-t2) < 0;
}

int operator>(const Time& t1, const Time& t2){
    return (t1-t2) > 0;
}

int operator==(const Time& t1, const Time& s2){
    return (t1-t2) == 0;
}
