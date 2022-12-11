#include "Eveniment.h"
#include <string.h>

Eveniment::Eveniment()
{
	this->nume = nullptr;
	this->ziua = 0;
	this->luna = 0;
	this->anul = 0;
	this->ora = 0;
}

Eveniment::Eveniment(char* nume, int ziua, int luna, int anul, int ora)
{
	this->nume = new char(strlen(nume) + 1);
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->ziua = ziua;
	this->luna = luna;
	this->anul = anul;
	this->ora = ora;
}

Eveniment::Eveniment(const Eveniment& eveniment)
{
	this->nume = new char[strlen(eveniment.nume) + 1];
	strcpy_s(this->nume, strlen(eveniment.nume) + 1, eveniment.nume);
	this->ziua = eveniment.ziua;
	this->luna = eveniment.luna;
	this->anul = eveniment.anul;
	this->ora = eveniment.ora;
}

void Eveniment::setNume(char* numeNou)
{
	if (this->nume)
	{
		delete[]this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(numeNou) + 1];
	strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
}

void Eveniment::setZiua(int ziuaNoua)
{
	this->ziua = ziuaNoua;
}

void Eveniment::setLuna(int lunaNoua)
{
	this->luna = lunaNoua;
}

void Eveniment::setAnul(int anulNou)
{
	this->anul = anulNou;
}

void Eveniment::setOra(int oraNoua)
{
	this->ora = oraNoua;
}

char* Eveniment::getNume()
{
	return nume;
}

int Eveniment::getZiua()
{
	return ziua;
}

int Eveniment::getLuna()
{
	return luna;
}

int Eveniment::getAnul()
{
	return anul;
}

int Eveniment::getOra()
{
	return ora;
}

Eveniment& Eveniment::operator=(const Eveniment& eveniment)
{
	setNume(eveniment.nume);
	setZiua(eveniment.ziua);
	setLuna(eveniment.luna);
	setAnul(eveniment.anul);
	setOra(eveniment.ora);
	return *this;
}

bool Eveniment::operator==(const Eveniment& eveniment)
{
	return strcmp(this->nume, eveniment.nume) == 0;
		/* &&
		this->ziua == eveniment.ziua &&
		this->luna == eveniment.luna &&
		this->anul == eveniment.anul &&
		this->ora == eveniment.ora;*/
}

bool Eveniment::operator<(const Eveniment& eveniment) const
{
	return strcmp(this->nume, eveniment.nume) < 0;
}

bool Eveniment::operator>(const Eveniment& eveniment) const
{
	return strcmp(this->nume, eveniment.nume) > 0;
}

ostream& operator<<(ostream& os, const Eveniment& eveniment)
{
	os << "Evenimentul cu numele: " << eveniment.nume << endl
		<< "Cu logatia inca necunoscuta" << endl
		<< "Din ziua: " << eveniment.ziua << endl
		<< "De la ora: " << eveniment.ora << endl
		<< "Din luna:  " << eveniment.luna << endl
		<< "Din anul: " << eveniment.anul << endl << endl;
	return os;
}
