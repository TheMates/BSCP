// cv08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myLIFO.h"
#include <complex>
#include <Windows.h>	//Sleep()
#include <conio.h>		//_kbhit() for detecting keyboard in while loop

using namespace std;

class triple
{
	int a, b,c;
public:
	triple() = default;
	triple(int aa, int bb,int cc) :a(aa), b(bb),c(cc) { };

	friend ostream &operator <<(ostream &out, triple& src)
	{
		return out << src.a << " " << src.b << " " << src.c;
	}
};

unsigned int SleepTime = 350;

int main()
{
	LIFO<complex<double>> lifo(3);
	
	while(!_kbhit())
	{
		auto operation = rand() % 2;
		//auto newnumber = rand() % 100;		//int, double, float, ...
		auto newNumber = complex<double>(rand() % 100, rand() % 100);			//complex
		//auto newnumber = triple(rand() % 100, rand() % 100, rand() % 100);	//class triple
		try
		{
			if (operation == 0)
				lifo.push(newNumber);
			else
				lifo.pop();

		}
		catch (exception &e)
		{
			cout << e.what();
		}
				
		Sleep(SleepTime);
	}
	cout << "Terminated." << endl;
	cin.ignore();
	cin.get();
}
