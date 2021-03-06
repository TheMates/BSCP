#include "header.h"
using namespace std;

const float pi = 3.14159265;


std::string Tvar::printPrivate()
{
	return "\t obvod: " + to_string(this->obvod()) + ",\t obsah : " + to_string(this->obsah());
}


Tvar::Tvar(int size) :_size(size)
{
	_dimensions = new float[size];
}

Tvar::~Tvar()
{
	delete _dimensions;
}


Kruh::Kruh(float radius) :Tvar(1)
{
	_dimensions[0] = radius;
}

void Kruh::print()
{
	cout << "Kruh \t\t" << printPrivate() << endl;
}
float Kruh::obvod()
{
	return 2 * pi*_dimensions[0];
}
float Kruh::obsah()
{
	return pi * _dimensions[0] * _dimensions[0];
}

Trojuhelnik::Trojuhelnik(float a, float b, float c) :Tvar(3)
{
	_dimensions[0] = a;
	_dimensions[1] = b;
	_dimensions[2] = c;
}

void Trojuhelnik::print()
{
	cout << "Trojuhelnik \t" << printPrivate() << endl;
}

float Trojuhelnik::obvod()
{
	return _dimensions[0] + _dimensions[1] + _dimensions[2];
}

float Trojuhelnik::obsah()
{
	float s = (_dimensions[0] + _dimensions[1] + _dimensions[2]) / 2.0;
	return sqrt(s*(s - _dimensions[0])*(s - _dimensions[1])*(s - _dimensions[2]));
}

Obdelnik::Obdelnik(float a, float b) :Tvar(2)
{
	_dimensions[0] = a;
	_dimensions[1] = b;
}

void Obdelnik::print()
{
	cout << "Obdelnik \t" << printPrivate() << endl;
}

float Obdelnik::obvod()
{
	return 2 * (_dimensions[0] + _dimensions[1]);
}

float Obdelnik::obsah()
{
	return _dimensions[0] * _dimensions[1];
}

Barevny_obdelnik::Barevny_obdelnik(float a, float b, std::string barva) :Obdelnik(a, b)
{
	_barva = barva;
}

void Barevny_obdelnik::print()
{
	cout << "Barevny obdelnik" << printPrivate() << " barva: " << _barva<<endl;
}

void sortByParameter(Tvar** col, unsigned size, bool byObvod, bool ascending)
{
	auto newLowest = 0;
	for(auto i = 0; i<size;i++)
	{
		newLowest = getNext(col, i, size, byObvod,ascending);
		swap(col[i], col[newLowest]);		
	}	
}


 int getNext(Tvar **col, unsigned int startIdx, unsigned int size, bool byObvod, bool ascending)
{	
	auto localMax = FLT_MAX;
	if (!ascending)
		localMax = FLT_MIN;
	int idx = startIdx;
	for(auto i = startIdx;i<size;i++)
	{
		switch (byObvod)
		{
		case true:
			if(ascending)
			{
				if (col[i]->obvod() < localMax)
				{
					localMax = col[i]->obvod();
					idx = i;
				}
			}
			else
			{
				if (col[i]->obvod() > localMax)
				{
					localMax = col[i]->obvod();
					idx = i;
				}
			}
			break;
		case false:
			if (ascending)
			{
				if (col[i]->obsah() < localMax)
				{
					localMax = col[i]->obsah();
					idx = i;
				}
			}
			else
			{
				if (col[i]->obsah() > localMax)
				{
					localMax = col[i]->obsah();
					idx = i;
				}
			}
			break;
		}
		
	}
	return idx;
}


void swap(Tvar& a, Tvar& b)
{
	std::swap(a._dimensions, b._dimensions);
	std::swap(a._size, b._size);
}




