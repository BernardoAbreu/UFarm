#include <cstring>
#include <cstdio>

#include "reset.h"

// default constructor

Reset::Reset() {
    hour = 0;
    minute = 0;
    state = false;
}

// constructor
Reset::Reset(const Time* time){
    hour = time->getHour();
    minute = time->getMinute();
    state = false;
}

Reset::Reset(int h, int m, int s){
    hour = h;
    minute = m;
    state = s;
}

Reset::Reset(int h, int m){
    hour = h;
    minute = m;
    state = false;
}



// destructor
//Reset::~Reset() {}


// copy constructor 
Reset::Reset(const Reset& r) {
    hour = r.hour;
    minute = r.minute;
    state = r.state;
}

// copy assignment

Reset& Reset::operator=(const Reset& rhs){

    if (this == &rhs) {
    return *this;
    }

    // now copy from rhs
    hour = r.hour;
    minute = r.minute;
    state = r.state;

    return *this;
}


double operator-(const Reset& t1, const Reset& t2){
    return  (t1.hour*60 + t1.minute) - (t2.hour*60 + t2.minute);
}


// put-to operator

ostream& operator<<(ostream& os, const Reset& t){
    os << t.hour << ":" << t.minute << " - " << ((t.state) ? "open" : "closed");
    return os;
}

// relational operators

int operator<(const Reset& t1, const Reset& t2){
    return (t1-t2) < 0;
}

int operator>(const Reset& t1, const Reset& t2){
    return (t1-t2) > 0;
}

int operator==(const Reset& t1, const Reset& t2){
    return (t1-t2) == 0;
}