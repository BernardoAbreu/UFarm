#include <fstream>
#include "schedule.h"

using namespace std;

int main(){
	
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
        sch.monitorValves();
    }

    return 0;
}