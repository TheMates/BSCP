#pragma once
#include <vector>
#include <memory>
#include <string>

template<typename T> class pole
{
	std::unique_ptr<T[]> data;		//zkusím ty nový pointery, a vím jak to funguje zhruba
	unsigned int size;

public:
	pole(unsigned int size)
	{
		this->size = size;
		data = std::make_unique<T[]>(this->size);
	}
	~pole()
	{
		std::cout << std::endl << "Destructing..." << std::endl;		//unique_ptr se o sebe postará sám, snad
	}

	T& operator [](unsigned int index)
	{
		return  data.operator[](index);
	}
	unsigned int length() const
	{
		return size;
	}

	friend std::ostream& operator <<(std::ostream& out, pole& src)
	{
		for (auto i = 0; i < src.length(); i++)
		{
			out << src.operator[](i) << std::endl;
		}
		out << std::endl;
		return out;
	}
};

class Osoba
{
	int ID, telefon;
	std::string jmeno, prijmeni;
public:
	Osoba(std::string jmeno = "", std::string prijmeni = "",int telefon = -1);
	~Osoba() = default;

	int getID() const { return ID; }
	int getTel() const { return telefon; }
	std::string getJmeno() const { return jmeno; }
	std::string getPrijmeni() const { return prijmeni; }

	void setID(const int value) { ID = value; }
	void setTel(const int value) { telefon = value; }
	void setJmeno(const std::string &value) { jmeno = value; }
	void setPrijmeni(const std::string& value) { prijmeni = value; }

	friend std::ostream& operator <<(std::ostream& out, Osoba& src);

};



