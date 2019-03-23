// maincv04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "header.h"
using namespace std;

int main(int argc, char * argv[])
{
	char cs[] = "hello";
	char *cp = cs;

	Pole A(5);
	Pole B(5, 2);
	auto C = new Pole(5);
	C->fillRand();
	auto D = new Pole(cp);
	Pole E(*C);
	E.fillRand();

	A.print();
	B.print();
	C->print();
	D->print();
	E.print();

	cout << endl;

	B.add(*C);
	add(B, E, A);
	B.print();
	A.print();
	
	


	std::system("pause");
}

