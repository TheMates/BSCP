#include "header.h"
#include <mutex>
using namespace std;

Pole::Pole(int size)
{
	_size = size;
	_pole = new int[size];
}
Pole::Pole(int size, int value)
{
	_size = size;
	_pole = new int[size];
	for(int i = 0;i<size;i++)
	{
		_pole[i] = value;
	}
}
Pole::Pole(char* ch)
{
	
	_size = strlen(ch);
	_pole = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		_pole[i] = ch[i];
	}
}
Pole::~Pole()
{
	delete _pole;
}
Pole::Pole(Pole& src)
{
	_size = src._size;
	_pole = new int[src._size];
	
	for(auto i = 0 ;i<_size;i++)
	{
		_pole[i] = src._pole[i];
	}
}
int Pole::getLength() const
{
	return _size;
}
int Pole::operator[](unsigned int index) const
{
	return _pole[index];
}
void Pole::fillRand()
{
	for(int i = 0;i<this->_size;i++)
	{
		this->_pole[i] = rand() % 100;
	}
}
void Pole::print()
{
	for(int i =0;i<_size;i++)
	{
		cout << this->operator[](i) << " ";
	}
	cout << endl;
}
void Pole::add(Pole& second)
{
	if (_size != second._size)
		throw("Size mismatch!");
	for (int i = 0; i < _size; i++)
		_pole[i] += second._pole[i];
}

void add(Pole& A, Pole& B, Pole& C)
{
	if (A._size == B._size && A._size != C._size)
		throw("Size mismatch!");
	for (int i = 0; i < A._size; i++)
		C._pole[i] = A._pole[i] + B._pole[i];
}