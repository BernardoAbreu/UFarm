using namespace std;


/*
Info
# 0 - Valve
# 1 - Duration of time open   ( in minutes )
# 2 - Duration of time closed ( in minutes )
# 4 - Last time accessed      - (Hour, Minute)
# 5 - Reset Time (Optional)   - ( (Hour, Minute), Initial State )
*/
        
typedef struct {
    Valve valve;
    int open;
    int closed;
    Time last_time;
    Reset reset;
    int check_time;
    Time last_check;
} valve_info;

class ValveCluster{
    
}