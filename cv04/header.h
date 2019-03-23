#pragma once
#include <string>
#include <iostream>

class Pole
{
private:
	int* _pole;
	unsigned int _size;

public:
	Pole(int size);
	Pole(int size, int value);
	Pole(char *ch);
	Pole(Pole &src);		//copy constructor
	~Pole();

	int getLength() const;
	int operator[](unsigned int index) const;
	void fillRand();
	void print();
	void add(Pole &second);

	friend void add(Pole &A, Pole &B, Pole &C);
};



