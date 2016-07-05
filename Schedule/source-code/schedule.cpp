#include <iostream>
#include <fstream>
#include <unistd.h>
#include "schedule.h"

//Default Constructor
Schedule::Schedule(){
    Time t;
    last_minute = t.getMinute();

    outfile = "schedule_info.txt";
    valves = new valve_map();
}



// destructor
Schedule::~Schedule(){
    delete valves;
}

// copy constructor
Schedule::Schedule(const Schedule& s){
    last_minute = s.last_minute;
    outfile = s.outfile;
    valves = new valve_map(*s.valves);
}

// copy assignment
Schedule& Schedule::operator=(const Schedule& s){
    if (this == &s) {
        return *this;
    }

    delete valves;
    
    // now copy from s
    last_minute = s.last_minute;
    outfile = s.outfile;
    valves = new valve_map(*s.valves);

    return *this;
}


void Schedule::addValve(Valve_info info){
    valves->insert(make_pair(info.getValve().getNumber(), info));
}


void Schedule::removeValve(int num){
    valves->erase (num); 
}


//void Schedule::monitorValves(){
void Schedule::monitorValves(RF24& radio){
        Time time;

        if (last_minute != time.getMinute()){
            bool checknow = false;
            
            ofstream out;
            out.open(outfile.c_str(), ios::app);

            for(iter it = valves->begin(); it != valves->end(); it++ ){
                Valve_info& v = it->second;

                double passed_time = time - v.getLastTime();
                double passed_check = time - v.getLastCheck();

                                
                if ((v.getReset() == time ) && v.getReset().getAvailable()){
                    v.getValve().setState(v.getReset().getState());
                    v.setLastTime(time);
                    
                    out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                    cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                }
                else{
                    if (passed_check/60.0 >= v.getCheckTime()){

                        v.setLastCheck(time);
                        
                        out << "Checking valve " << v.getValve().getNumber();
                        cout << "Checking valve " << v.getValve().getNumber();
                                
                        //bool state_ok = v.getValve().readState(radio);
                        //if (v.getValve().checkState()){
                        if (v.getValve().checkState(radio)){

                            out << "Valve " << v.getValve().getNumber() << " ok:" << ((v.getValve().getState()) ? "open" : "closed");
                            cout << "Valve " << v.getValve().getNumber() << " ok:" << ((v.getValve().getState()) ? "open" : "closed");
                        }

                        else{

                            out << "Error on valve " << v.getValve().getNumber() 
                            << ". Currently " << ((v.getValve().getValveState()) ? "open" : "closed") 
                            << ". Should be " << ((v.getValve().getState()) ? "open" : "closed");

                            cout << "Error on valve " << v.getValve().getNumber() 
                            << ". Currently " << ((v.getValve().getValveState()) ? "open" : "closed") 
                            << ". Should be " << ((v.getValve().getState()) ? "open" : "closed");
                        }

                        out << endl;
                        cout << endl;

                    }      
                    if (v.getValve().getState()){
                        if (passed_time/60.0 >= v.getOpen()){
                            //v.getValve().sendState(false);
                            v.getValve().sendState(radio, false);
                            v.setLastTime(time);
                            
                            if (!checknow){
                                
                                out << "\n" << time;
                                cout << "\n" << time;
                                checknow = true;
                            }

                            out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            
                        }
                    }
                    else{     
                        if ( passed_time / 60.0 >= v.getClosed() ) {
                            //v.getValve().sendState(true);
                            v.getValve().sendState(radio, true);
                            v.setLastTime(time);
                           
                            if (!checknow){
                                
                                out << "\n" << time;
                                cout << "\n" << time;
                                checknow = true;
                            }

                            out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            
                        }
                    }
                }
            }
            out.close();
        }
        
    
        last_minute = time.getMinute();
        sleep(60);
        
}
