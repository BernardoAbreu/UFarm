#include <iostream>
#include <fstream>
#include <unistd.h>
#include "schedule.h"

Schedule::Schedule(){
    Time t;
    last_minute = t.getMinute();

    outfile = "schedule_info.txt";
    valves = new valve_map();
}

// constructor
//Schedule::Schedule(int){}

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


//TODO
void Schedule::addValve(Valve_info info){
    valves->insert(make_pair(info.getValve().getNumber(), info));
}

//void addValve(Valve, int, int, Reset, int){
//        #self.valves[valve.getNumber()] = {'valve' : valve,
//                                           'open' : t_open,
//                                           'closed' : t_closed,
//                                           'last_time' : datetime.now().time(),
//                                           'reset' : reset}
//        self.valves[valve.getNumber()] = Info(valve, t_open, t_closed, reset,check)
//    }

//TODO
void Schedule::removeValve(int num){
    valves->erase (num); 
}



void Schedule::monitorValves(){
        Time time;

        if (last_minute != time.getMinute()){
            bool checknow = false;
            
            ofstream out;
            out.open(outfile.c_str(), ios::app);

            for(iter it = valves->begin(); it != valves->end(); it++ ){
                Valve_info& v = it->second;
                //passed_time = (time.minute + time.hour*60) - (v.getLastTime().hour*60 + v.getLastTime().minute)
                

                double passed_time = time - v.getLastTime();
                double passed_check = time - v.getLastCheck();

                //p_c_time = passed_check.days*24*60 + passed_check.seconds/60.0                            
                
                                
                if ((v.getReset() == time ) && v.getReset().getAvailable()){
                    v.getValve().setState(v.getReset().getState());
                    v.setLastTime(time);

                    //with open(self.outfile, "a") as myfile:
                        //myfile.write('Valve {} {}'.format(v.getValve().getNumber(),'open' if v.getValve().getState() else 'closed'))
                    
                    out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                    cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                }
                else{
                    if (passed_check/60.0 >= v.getCheckTime()){
                    //if (p_c_time >= v.getCheckTime());
                        v.setLastCheck(time);
                        
                        out << "Checking valve " << v.getValve().getNumber();
                        cout << "Checking valve " << v.getValve().getNumber();

                        //outstr = 'Checking valve ' + str( v.getValve().getNumber() ) + '\n'
                                
                        bool state_ok = v.getValve().readState();
                        
                        if (state_ok){
                            //outstr += 'Valve {} ok: {}'.format(v.getValve().getNumber(), 'open' if v.getValve().getState() else 'closed')

                            out << "Valve " << v.getValve().getNumber() << " ok:" << ((v.getValve().getState()) ? "open" : "closed");
                            cout << "Valve " << v.getValve().getNumber() << " ok:" << ((v.getValve().getState()) ? "open" : "closed");
                        }

                        else{
                            //outstr += 'Error on valve {}: Currently {}. Should be {}'.format(v.getValve().getNumber(),'open' if v.getValve().getValveState() else 'closed','open'if v.getValve().getState() else 'closed')
                            

                            out << "Error on valve " << v.getValve().getNumber() 
                            << ". Currently " << ((v.getValve().getValveState()) ? "open" : "closed") 
                            << ". Should be " << ((v.getValve().getState()) ? "open" : "closed");

                            cout << "Error on valve " << v.getValve().getNumber() 
                            << ". Currently " << ((v.getValve().getValveState()) ? "open" : "closed") 
                            << ". Should be " << ((v.getValve().getState()) ? "open" : "closed");
                        }

                        out << endl;
                        cout << endl;

                        //appendToFile(outfile, outstr);

                    }      
                    if (v.getValve().getState()){
                        if (passed_time/60.0 >= v.getOpen()){
                        //if (passed_time >= v.getOpen()){
                            //v.getValve()s.sendState = False
                            v.getValve().sendState(false);
                            v.setLastTime(time);
                            
                            if (!checknow){
                                //with open(self.outfile, "a") as myfile:
                                    //myfile.write('\n'+str(time)+'\n')
                                
                                out << "\n" << time;
                                cout << "\n" << time;
                                checknow = true;
                            }

                            out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            
                            //with open(self.outfile, "a") as myfile:
                                //myfile.write('Valve {} {}\n'.format(v.getValve().getNumber(),'open' if v.getValve().getState() else 'closed'))
                        }
                    }
                    else{     
                        if ( passed_time / 60.0 >= v.getClosed() ) {
                        //if (passed_time >= v.getClosed()){
                            v.getValve().sendState(true);
                            v.setLastTime(time);
                           
                            if (!checknow){
                                //with open(self.outfile, "a") as myfile:
                                    //myfile.write('\n'+str(time)+'\n')
                                
                                out << "\n" << time;
                                cout << "\n" << time;
                                checknow = true;
                            }

                            out << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            cout << "Valve " << v.getValve().getNumber() << " " << ((v.getValve().getState()) ? "open" : "closed") << endl;
                            
                            //with open(self.outfile, "a") as myfile:
                                //myfile.write('Valve {} {}\n'.format(v.getValve().getNumber(),'open' if v.getValve().getState() else 'closed'))
                        }
                    }
                }
            }
            out.close();
        }
        
    
        last_minute = time.getMinute();
        sleep(60);
        
}
