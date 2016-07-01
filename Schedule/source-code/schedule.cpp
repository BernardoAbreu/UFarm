#include <string>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "schedule.h"

Schedule::Schedule(){
    last_minute = Time.getCurrentTime().getMinute();

    outfile = "schedule_info.txt";
}

// constructor
Schedule::Schedule(int);

// destructor
Schedule::˜Schedule();

// copy constructor
Schedule::Schedule(const Valve& v);

// copy assignment
Schedule& Schedule::operator=(const Valve& v);


void Schedule::addValve(valve_info info){
        valves[valve.getNumber()] = info;
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
    valves.remove(num);
}



void Schedule::monitorValves(){
        Time time;
        time.getCurrentTime();

        if (last_minute != time.getMinute()){
            bool checknow = false;
            
            for (key, v in self.valves.iteritems()){
                //passed_time = (time.minute + time.hour*60) - (v.last_time.hour*60 + v.last_time.minute)
                
                passed_time = time - v.last_time;
                passed_check = time - v.last_check;
                //p_c_time = passed_check.days*24*60 + passed_check.seconds/60.0                            
                
                                
                if (v.reset == time ){
                    v.valve.setState(v.reset.getState());
                    v.last_time = time;

                    with open(self.outfile, "a") as myfile:
                        myfile.write('Valve {} {}'.format(v.valve.getNumber(),'open' if v.valve.getState() else 'closed'))
                    
                    cout << "Valve " << v.valve.getNumber() << " " << ((v.valve.getState()) ? "open" : "closed");
                }
                else{
                    if (passed_check.getSecond()/60.0 >= v.check_time){
                    //if (p_c_time >= v.check_time);
                        v.last_check = time;
                        
                        cout << "Checking valve " << v.valve.getNumber();

                        outstr = 'Checking valve ' + str( v.valve.getNumber() ) + '\n'
                                
                        state_ok = v.valve.readState();
                        
                        if (state_ok){
                            outstr += 'Valve {} ok: {}'.format(v.valve.getNumber(), 'open' if v.valve.getState() else 'closed')

                            cout << "Valve " << v.valve.getNumber() << " ok:" << ((v.valve.getState()) ? "open" : "closed");
                        }

                        else{
                            outstr += 'Error on valve {}: Currently {}. Should be {}'.format(v.valve.getNumber(),'open' if v.valve.getValveState() else 'closed','open'if v.valve.getState() else 'closed')
                            

                            cout << "Error on valve " << v.valve.getNumber() 
                            << ". Currently " << ((v.valve.getValveState()) ? "open" : "closed") 
                            << ". Should be " << ((v.valve.getState()) ? "open" : "closed");
                        }

                        appendToFile(outfile, outstr);

                    }      
                    if (v.valve.getState()){
                        if (passed_time.getSecond()/60.0 >= v.open){
                        //if (passed_time >= v.open){
                            //v.valves.sendState = False
                            v.valve.sendState(false);
                            v.last_time = time;
                            
                            if (!checknow){
                                with open(self.outfile, "a") as myfile:
                                    myfile.write('\n'+str(time)+'\n')

                                cout << time;
                                checknow = true;
                            }

                            cout << "Valve " << v.valve.getNumber() << ((v.valve.getState()) ? "open" : "closed");
                                
                            with open(self.outfile, "a") as myfile:
                                myfile.write('Valve {} {}\n'.format(v.valve.getNumber(),'open' if v.valve.getState() else 'closed'))
                        }
                    }
                    else{     
                        if ( passed_time.getSecond() / 60.0 >= v.closed ) {
                        //if (passed_time >= v.closed){
                            v.valve.sendState(true);
                            v.last_time = time;
                           
                            if (!checknow){
                                with open(self.outfile, "a") as myfile:
                                    myfile.write('\n'+str(time)+'\n')
                                
                                cout << time;
                                checknow = true;
                            }

                            cout "Valve " << v.valve.getNumber() << ((v.valve.getState()) ? "open" : "closed");
                                
                            with open(self.outfile, "a") as myfile:
                                myfile.write('Valve {} {}\n'.format(v.valve.getNumber(),'open' if v.valve.getState() else 'closed'))
                        }
                    }
                }
            }
        }
    
        last_minute = time.getminute();
        sleep(50)
}
