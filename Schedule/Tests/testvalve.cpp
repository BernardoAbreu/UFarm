#include <iostream>
#include "valve.h"

using namespace std;

int main(){

	Valve v1(0);

	cout << "Valve " << v1.getNumber() << " " << ((v1.getState()) ? "open" : "closed")<< endl;

	v1.setState(true);

	cout << "Valve " << v1.getNumber() << " " << ((v1.getState()) ? "open" : "closed") << endl;	

	v1.setState(0);

	cout << "Valve " << v1.getNumber() << " " << ((v1.getState()) ? "open" : "closed") << endl;
        
}