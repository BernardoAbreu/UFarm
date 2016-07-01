#include <iostream>
#include <unistd.h>
#include <ctime>
#include "time.h"

using namespace std;


int main(){

	cout << "Hello" << endl;
	Time t1;

	sleep(1);

	cout << "Hello2" << endl;
	time_t now = time(0);
	cout << "Hello3" << endl;

	tm *ltm = localtime(&now);
	cout << "Hello4" << endl;
   	Time t2(now);
   	cout << "Hello5" << endl;
   	Time t3(ltm);
   	cout << "Hello6" << endl;

   	if (t2 == t3){
   		cout << "ok" << endl;
   	}
   	cout << "Hello7" << endl;

	// print various components of tm structure.
	cout << "Year: " << t1.getYear() <<endl;
	cout << "Month: " << t1.getMonth() << endl;
	cout << "Day: " <<  t1.getDay() << endl;
	cout << "Time: " <<  t1.getHour() << ":";
	cout <<  t1.getMinute() << ":";
	cout <<  t1.getSecond() << endl;

	cout << t1 << endl;

	t2 = t1;

	cout << "t2: " << t2 << endl;
	Time t4 = t3;

	cout << "t3: " << t3 << endl;
	cout << "t4: " << t4 << endl;

	Time t5(t1);

	cout << "t5: " << t5 << endl;


	sleep (5);

	t5.getCurrentTime();

	cout << "Seconds from the beginning: " << (t5-t1) << endl;
	

}