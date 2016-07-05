/*
 * schedule.h
 */

#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__


#include <map>
#include <string>
#include "valve_info.h"
#include "rfsignal.h"

using namespace std;


typedef map<int, Valve_info> valve_map;

typedef map<int, Valve_info>::iterator iter;

class Schedule{

    public:

        // default constructor
        Schedule();

        // destructor
        ~Schedule();

        // copy constructor
        Schedule(const Schedule& v);

        // copy assignment
        Schedule& operator=(const Schedule& v);
        
        void addValve(Valve_info);



        void removeValve(int);


        void monitorValves(RF24&);


        void setOutFile(string out) { outfile = out; }

        Valve_info& getValve_Info(int i) { return valves->find(i)->second; }
        
        
        string getOutFile() const { return outfile; }
        
    
    private:

        int last_minute;
        string outfile;
        valve_map *valves;
};

#endif
