// cv05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
using namespace std;

int main(int argc, char * argv[])
{
	
	Tvar *col[10];

	col[0] = new Kruh(4.5);
	col[1] = new Obdelnik(2.1,2.1);
	col[2] = new Barevny_obdelnik(3, 5, "cervena");
	col[3] = new Trojuhelnik(2, 3, 4);
	col[4] = new Kruh(2);
	col[5] = new Kruh(7.5);
	col[6] = new Obdelnik(2.9, 2.1);
	col[7] = new Barevny_obdelnik(3, 1, "modra");
	col[8] = new Trojuhelnik(5, 4, 3);
	col[9] = new Kruh(4);

	for(auto i = 0;i<10;i++)
	{
		col[i]->print();
	}

	sortByParameter(col, 10, false, false);
	cout << endl << endl;
	
	for (auto i = 0; i < 10; i++)
	{
		col[i]->print();
	}
	system("pause");
	
}

