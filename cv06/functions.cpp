#include "header.h"
#include <iostream>
using namespace std;


void Matice::scalarOperation(double scalar, double(* operation)(double, double))
{
	for (auto r = 0; r < _rows; r++)
	{
		for (auto c = 0; c < _cols; c++)
			_data[r][c] = operation(scalar, _data[r][c]);
	}
}

Matice& Matice::matrixOperation(const Matice& loperand, const Matice& roperand, double(* operation)(double, double))
{
	Matice *result;
	if (loperand._rows == 1 && loperand._cols == 1 || roperand._rows == 1 && roperand._cols == 1)
	{
		if (loperand._rows == 1)
		{
			result = new Matice(roperand);
			result->scalarOperation(loperand[0][0], operation);
		}
		else
		{
			result = new Matice(loperand);
			result->scalarOperation(roperand[0][0], operation);
		}
	}
	else
	{
		if (loperand._rows != roperand._rows || loperand._cols != roperand._cols)
			throw("Dimension mismatch!\n\n");

		result = new Matice(loperand);
		for (auto r = 0; r < result->_rows; r++)
		{
			for (auto c = 0; c < result->_cols; c++)
			{
				result->_data[r][c] = operation(loperand[r][c], roperand[r][c]);
			}
		}
	}
	return *result;
}

Matice::Matice()
{
	_data = NULL;
}
Matice::Matice(unsigned int rows, unsigned int cols)
{
	_rows = rows;
	_cols = cols;
	_data = new double*[_rows];
	for(auto  i = 0;i<_cols;i++)
	{
		_data[i] = new double[_cols];
	}
}
Matice::Matice(const Matice& src)
{
	_rows = src._rows;
	_cols = src._cols;
	_data = new double*[_rows];
	for (auto i = 0; i < _cols; i++)
	{
		_data[i] = new double[_cols];
	}
	for(auto r = 0;r<_rows;r++)
	{
		for (auto c = 0; c < _cols; c++)
			_data[r][c] = src._data[r][c];
	}
}
Matice::Matice(double a)
{
	_rows = _cols = 1;
	_data = new double*[1];
	_data[0] = new double[1];
	_data[0][0] = a;
}
Matice::~Matice()
{
	for (auto i = 0; i < _rows; i++)
		delete[] _data[i];
}
double* Matice::operator[](unsigned int i) const
{
	return _data[i];
}

Matice Matice::operator-()
{
	Matice result(*this);
	for(auto r = 0;r<this->_rows;r++)
	{
		for(auto c = 0;c<this->_cols;c++)
		{
			result[r][c] *= -1;
		}
	}
	return result;
}
std::ostream & operator<<(std::ostream & out, Matice & src)
{
	for (auto r = 0; r < src._rows; r++)
	{
		for (auto c = 0; c < src._cols; c++)
			out << src._data[r][c] << "\t";
		out << endl;
	}
	out << endl;
	return out;
}

//operátory buï provedou pøíslušnou operaci se skalárem, nebo v pøípadì shody dimenzí èíslo po èísle. Korektní násobení/dìlení matic jsem neimplementoval
Matice operator+(const Matice& first, const Matice& second)
{
	try { return Matice::matrixOperation(first, second, [](double loperand, double roperand) {return loperand + roperand; }); }
	catch (const char* e)
	{
		throw;
	}
}
Matice operator-(const Matice& first, const Matice& second)
{
	try { return Matice::matrixOperation(first, second, [](double loperand, double roperand) {return loperand - roperand; }); }
	catch (const char* e)
	{
		throw;
	}
}
Matice operator*(const Matice& first, const Matice& second)
{
	try { return Matice::matrixOperation(first, second, [](double loperand, double roperand) {return loperand * roperand; }); }
	catch (const char* e)
	{
		throw;
	}
}
Matice operator/(const Matice& first, const Matice& second)
{
	try { return Matice::matrixOperation(first, second, [](double loperand, double roperand) {return loperand / roperand; }); }
	catch (const char* e)
	{
		throw;
	}
}


Matice& Matice::operator=(const Matice& src)
{
	if(_data !=NULL)
	{
		for (auto i = 0; i < _rows; i++)
			delete []_data[i];
	}
	_rows = src._rows;
	_cols = src._cols;
	_data = new double*[_rows];
	for (auto i = 0; i < _cols; i++)
	{
		_data[i] = new double[_cols];
	}
	for (auto r = 0; r < _rows; r++)
	{
		for (auto c = 0; c < _cols; c++)
			_data[r][c] = src._data[r][c];
	}
	return *this;
}

void Matice::fill(double limit)
{
	for (auto r = 0; r < _rows; r++)
	{
		for (auto c = 0; c < _cols; c++)
			_data[r][c] = limit/float(1+rand() % 29);
			//_data[r][c] = float(1 + rand() % int(limit));
	}
}
