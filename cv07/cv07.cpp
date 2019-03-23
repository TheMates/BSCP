// cv07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myheader.h"

using namespace std;
int main()
{
	pole<int> A(10);
	pole<Osoba> B(10);

	string jmena[10] = { "Petr", "Pavel", "Lukas", "Jakub", "Jan", "Marek", "Jidas", "Tomas", "Juda", "Matous" };
	string prijmeni[10] = { "Blazek", "Coural", "Dolezal", "Eichler", "Hodny", "Chrabry", "Proradny", "Rychly", "Slaby", "Tuma" };

	
	for(auto i = 0;i<10;i++)
	{
		A[i] = i+1;
		B[i].setID(i + 1); B[i].setJmeno(jmena[i]); B[i].setPrijmeni(prijmeni[i]); B[i].setTel(rand() % 999999999);
	}
	cout << A << endl<<B<<endl;

	cin.get();
}

