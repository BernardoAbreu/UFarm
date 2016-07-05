#include <fstream>
#include "schedule.h"
#include "rfsignal.h"

using namespace std;

const uint8_t pipes[][6] = {"1Node","2Node"};

RF24 radio(22,0);

int main(){


    setup(radio, pipe[0], pipe[1]);

    Schedule sch;

    sch.addValve( Valve_info( Valve(0), 1, 2, Reset(16,51,true) ) );
    sch.addValve( Valve_info( Valve(1), 2, 1 ) );

    sch.setOutFile("info.txt");
    
    Time t;
    cout << "Started running: " << t << endl;

    ofstream out;
    
    out.open(sch.getOutFile().c_str(), ios::app);
    
    out << "Started running: " << t << endl;

    out.close();
    
    while (true){
        sch.monitorValves(radio);
    }

    return 0;
}