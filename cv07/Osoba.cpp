#include "myheader.h"

Osoba::Osoba( std::string jmeno, std::string prijmeni, int telefon)
{
	ID = rand() % 999999;
	this->jmeno = jmeno;
	this->prijmeni = prijmeni;
	this->telefon = telefon;
}



std::ostream& operator<<(std::ostream& out, Osoba& src)
{
	out << "ID:" <<src.ID<< std::endl<<src.jmeno << " " << src.prijmeni << " " << std::endl << "telefon: " << src.telefon << std::endl << std::endl;
	return out;
}
