#include <fstream>
#include <sstream>
#include "schedule.h"



using namespace std;

//Define macro for converting to string
#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()


//Creates node for communication
const uint8_t pipes[][6] = {"1Node","2Node"};


//Generic Radio
RF24 radio(22,0);



int main(){

    Schedule sch;

    //Setup radio
    setup(radio, pipes[0], pipes[1]);


    //Adds Valve 1, 1 minute open, 2 minutes closed, reset at 16:51
    sch.addValve( Valve_info( Valve(1), 1, 2, Reset(16,51,true) ) );

    //Adds Valve 2, 2 minutes open, 1 minute closed
    sch.addValve( Valve_info( Valve(2), 2, 1 ) );

    //Adds Valve 3, 3 minutes open, 3 minutes closed
    sch.addValve( Valve_info( Valve(3), 3, 3 ) );

    //Adds Valve 4, 2 minutes open, 4 minutes closed
    sch.addValve( Valve_info( Valve(4), 2, 4 ) );
    
    //Get current time
    Time t;
    cout << "Started running: " << t << endl;

    //Get current Date
    string s = SSTR(t.getMonth()) + "-" + SSTR(t.getDay()) + "-" + 
            SSTR(t.getYear());
            
    sch.setOutFile("info-" + s + ".txt");


    //Record start of program on file
    /**************************************************************************/
    ofstream out;

    out.open(sch.getOutFile().c_str(), ios::app);

    out << "Started running: " << t << endl;

    out.close();
    /**************************************************************************/

    //Forever loop - Ctrl+c to finish
    while (true){
        sch.monitorValves(radio);
    }

    return 0;
}