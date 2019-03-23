// cv06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
#include <iostream>
using namespace std;



int main()
{

	Matice A(3, 4), B(3, 4), C(3, 4);
	
	A.fill(20);
	B.fill(20);
	C.fill(20);
	try { C = -A + B + 3 + B[1][2]; }
	catch(const char*e)
	{
		cout << e;
	}
	
	cout << A << endl<< B << endl<<C<<endl;
	
	system("pause");
}

