#ifndef __VALVE_H__
#define __VALVE_H__

#include "valve.h"
#include "reset.h"
#include "time.h"

using namespace std;


class Schedule{

    public:

        // default constructor
        Schedule();

        // constructor
        Schedule(int);

        // destructor
        ˜Schedule();

        // copy constructor
        Schedule(const Valve& v);

        // copy assignment
        Schedule& operator=(const Valve& v);
        
        void addValve(valve_info);

        //void addValve(Valve, int, int, Reset, int);


        void removeValve(Valve);


        void monitorValves();


        void setOutFile(string out) { outfile = out; };
        
        
        void getOutFile() const { return outfile; }
        
    
    private:

        string outfile;
        ValveCluster valves;
}

#endif
