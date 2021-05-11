//Source.cpp

#include <iostream>
#include "Bill.h"

using namespace std;

int main()
{
	Bill B1;
	Bill::Time T1, T2; //T1-timebeg, T2 - timeend

	cin >> B1;
	cout << endl;
	cout << " Enter talk start time:" << endl;
	cin >> T1;
	cout << " Enter talk end time:" << endl;
	cin >> T2;

	cout << "------------------------------------------------------------------------";
	cout << B1;
	cout << " Talk start time: ";
	cout << T1 << endl;
	cout << " Talk end time: ";
	cout << T2;
	cout << endl;

	cout << " Sum to pay: " << B1.For_Pay(T1, T2) << "UAH" << endl << endl;

	cout << "Size of class = " << sizeof(B1) << endl;
	cout << "Bill: " << Bill::getCounter() << endl;
	cout << "Bill::Time: " << Bill::Time::getCounter() << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << endl;
	cout << "T1 (Talk start time): " << T1 << endl;
	cout << "++T1 (hour): " << ++T1 << endl;
	cout << "--T1 (hour): " << --T1 << endl;
	cout << "T1++ (second): " << T1++ << endl;
	cout << "T1-- (second): " << T1-- << endl << endl;

	cout << "B1 (taryf): " << B1 << endl;
	cout << "++B1 (taryf): " << ++B1 << endl;
	cout << "--B1 (taryf): " << --B1 << endl;
	cout << "B1++ (taryf): " << B1++ << endl;
	cout << "B1-- (taryf): " << B1-- << endl << endl;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "                       MANIPULATIONS WITH TIME                          " << endl << endl;

	cout << "Talk start time is earlier than talk end time: ";
	if (T1 < T2)
		cout << " TRUE" << endl << endl;
	else
		cout << " FALSE" << endl << endl;

	cout << "Talk end time minus talk start time (in seconds): ";
	unsigned int q = Difference(T1, T2);
	cout << q << endl;

	cout << "Talk end time minus talk start time (in minutes): ";
	unsigned int k = DifferenceForT(T1, T2);
	cout << k << endl << endl;

	cout << "Talk start time in seconds: ";
	unsigned int s = T1.ToSeconds();
	cout << s << endl;
	cout << "Talk start time in minutes: ";
	unsigned int m = T1.ToMinutes();
	cout << m << endl << endl;

	cout << "Talk end time in seconds: ";
	unsigned int o = T2.ToSeconds();
	cout << o << endl;
	cout << "Talk end time in minutes: ";
	unsigned int i = T2.ToMinutes();
	cout << i << endl << endl;

	cout << "Subtracting from time a specified number of seconds (talk start time): " << endl;
	unsigned int substr;
	do { cout << "Enter how much seconds to substract: "; cin >> substr;
	} while (substr < 1);

	Bill::Time p = T1 - substr;
	cout << p << endl;

	unsigned int seconds;
	cout << "Adding to time a specified number of seconds (talk start time which was substracted): " << endl;
	do { cout << "Enter how much seconds to add: "; cin >> seconds;
	} while (seconds < 1);

	Bill::Time pp = T1 + seconds;
	cout << pp << endl;

	cout << "------------------------------------------------------------------------" << endl;

	//
	cout << "Bill::Pair + 1: " << Bill::Time::getCounter() << endl;
	{
		Bill s();
		cout << "Bill local: " << Bill::getCounter() << endl;
		cout << "Bill::Time local: " << Bill::Time::getCounter() << endl;
		Bill::Time m;
		cout << "Time::Time local + 1: " << Bill::Time::getCounter() << endl;
	}
	//

	cout << "Bill : " << Bill::getCounter() << endl;
	cout << "Bill::Time: " << Bill::Time::getCounter() << endl << endl;

	return 0;
}
 