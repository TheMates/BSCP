#pragma once
#include <iostream>
#include <string>


class Tvar
{
 protected:
	 float *_dimensions;
	 int _size;
	 std::string printPrivate();
	 friend void swap(Tvar& a, Tvar& b);
	

 public:
	 Tvar(int size);
	 ~Tvar();

	 virtual void print() = 0;
	 virtual float obvod() = 0;
	 virtual float obsah() = 0;

};


class Kruh: public Tvar
 {
 public:
	 Kruh(float radius);
	 void print() override;
	 float obvod() override;
	 float obsah() override;

 };



class Trojuhelnik : public Tvar
 {
 public: 
	 Trojuhelnik(float a, float b, float c);
	 void print() override;
	 float obvod() override;
	 float obsah() override;
 };

 class Obdelnik :public Tvar
 {
 public: 
	 Obdelnik(float a, float b);
	 void print() override;
	 float obvod() override;
	 float obsah() override;
 };

 class Barevny_obdelnik : public Obdelnik
 {
 private:
	 std::string _barva;
 public:
	 Barevny_obdelnik(float a, float b, std::string barva);
	void print() override;
 };

 void sortByParameter(Tvar **col,unsigned int size, bool byObvod, bool ascending);
 int getNext(Tvar * *col, unsigned int startIdx, unsigned int size, bool byObvod, bool ascending);
