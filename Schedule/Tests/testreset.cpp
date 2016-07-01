#include <iostream>
#include <unistd.h>
#include <ctime>
#include "reset.h"
#include "time.h"

using namespace std;


int main(){


	Reset r1;

	cout << "r1 "<< r1 << endl;

	Time t1;

	Reset r2(t1);

	cout << "r2 "<< r2 << endl;

	Reset r3 = r2;

	cout << "r3 "<< r3 << endl;

	if (r3 == r2) cout << "ok" << endl;

	Reset r4(14,30,true);

	cout << "r4 "<< r4 << endl;

	Reset r5(15,50);

	cout << "r5 "<< r5 << endl;

	Reset r6 = t1;

	r6.setState(1);

	cout << "r6 " << r6 << endl;


	cout << r5 - r4 << endl;

	return 0;
}