#pragma once
#include <iostream>



class Matice
{
private:
	double ** _data;
	unsigned int _rows, _cols;

	void scalarOperation(double scalar, double(*operation)(double, double));
	static Matice& matrixOperation(const Matice &loperand, const Matice &roperand, double(*operation)(double, double));

public:
	Matice();
	Matice(unsigned int rows, unsigned int cols);
	Matice(const Matice &src);
	Matice(double a);
	~Matice();

	double* operator[](unsigned int i)const;

	Matice operator -();

	friend std::ostream & operator <<(std::ostream & out, Matice &src);
	friend Matice operator +(const Matice &first, const Matice &second);
	friend Matice operator -(const Matice &first, const Matice &second);
	friend Matice operator *(const Matice &first, const Matice &second);
	friend Matice operator /(const Matice &first, const Matice &second);

	Matice& operator =(const Matice &src);

	void fill(double limit);
	
};
