#include <fstream>
#include <sstream>
#include "schedule.h"



using namespace std;


#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()



const uint8_t pipes[][6] = {"1Node","2Node"};

RF24 radio(22,0);

int main(){

    Schedule sch;

    setup(radio, pipes[0], pipes[1]);

    sch.addValve( Valve_info( Valve(1,1), 1, 2, Reset(16,51,true) ) );
    sch.addValve( Valve_info( Valve(1,2), 2, 1 ) );
    sch.addValve( Valve_info( Valve(1,3), 3, 3 ) );
    sch.addValve( Valve_info( Valve(1,4), 2, 4 ) );
    
    Time t;
    cout << "Started running: " << t << endl;
    string s = SSTR(t.getMonth()) + "-" + SSTR(t.getDay()) + "-" + SSTR(t.getYear());
    sch.setOutFile("info-" + s + ".txt");

    ofstream out;
    
    out.open(sch.getOutFile().c_str(), ios::app);
    
    out << "Started running: " << t << endl;

    out.close();
    
    while (true){
        //sch.monitorValves();
        sch.monitorValves(radio);
    }

    return 0;
}