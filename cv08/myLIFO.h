#pragma once
#include <iostream>
#include <vector>

using namespace  std;

template<typename T> class LIFO
{
	T* data;
	//vector<T> vdata;
	unsigned int capacity, occupied = 0;

public:
	LIFO(unsigned int size) :capacity(size)
	{
		data = new T[size];
		//vdata.resize(size);
		cout << "Zasobnik typu: " << typeid(T).name() <<". Kapacita: "<<capacity<< endl;
		
	};
	~LIFO()
	{
		delete[] data;
	}
	void push(T value)
	{
		if (occupied < capacity)
		{
			data[occupied++] = value;
			cout << "Hodnota: " << value << " je nyni posledni. Obsazeno: " << occupied << "/" << capacity << endl;;
		}
		else
			throw std::out_of_range("Zasobnik je plny!\n");
	}
	void pop()
	{
		if (occupied >0)
		{
			--occupied;
			if (occupied == 0)
				cout << "Zasobnik je nyni prazdny. Obsazeno: " << occupied << "/" << capacity << endl;
			else{}
				cout << "Hodnota: " << data[occupied] << " je nyni posledni. Obsazeno: " << occupied << "/" << capacity << endl;
		}
		else
			throw std::out_of_range("Zasobnik je prazdny!\n");

	}
};


