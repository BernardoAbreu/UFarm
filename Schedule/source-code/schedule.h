/*
 * schedule.h
 */

#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__


#include <map>
#include <string>
#include "valve_info.h"


using namespace std;


typedef map<int, Valve_info> valve_map;

typedef map<int, Valve_info>::iterator iter;

class Schedule{

    public:


        /**
         * Default Constructor
         *
         * Creates a new instance of Schedule. Initializes Last Minute checked
         * to current minute. Allocates map of valve_info for valves.
         */
        Schedule();


        /**
         * Destructor
         *
         * Desallocates map of valve_info
         */
        ~Schedule();


        /**
         * Copy Constructor
         *
         * Creates a new instance of Schedule by copying another instance.
         *
         * @param s Schedule object to be copied
         */
        Schedule(const Schedule& s);


        /**
         * Copy Assignment
         *
         * Copies the information of Schedule object to this one
         *
         * @param s object to be copied
         */
        Schedule& operator=(const Schedule& s);


        /**
         * Adds a Valve to the schedule
         * @param Valve_info A Valve_info instance with the information
         *                   regarding the schedule
         */
        void addValve(Valve_info);


        /**
         * Remove a valve from the schedule
         * @param int The number of the valve to be removed
         */
        void removeValve(int);


        /**
         * Monitors states of valves. Sends information and reads it.
         *
         * @param RF24 Radio being used to communicate
         */
        void monitorValves(RF24&);


        /**
         * Set method to define file used to store information of the process
         * @param out String with file name
         */
        void setOutFile(string out) { outfile = out; }


        /**
         * Get Method for Valve_info
         * @param  i Id number of valve
         * @return   Valve_info object
         */
        Valve_info& getValve_Info(int i) { return valves->find(i)->second; }
        
        
        /**
         * Get method for name of output file
         * @return String with file name.
         */
        string getOutFile() const { return outfile; }

    private:

        //Minute of last valve check
        int last_minute;

        //Name of output file
        string outfile;

        //Map of valves
        valve_map *valves;
};

#endif
