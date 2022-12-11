#include "Utilizator.h"
#include <string.h>
#include<iostream>
using namespace std;


Utilizator::Utilizator()
{
	this->parola = nullptr;
	this->indice = -1;
	this->nume = nullptr;
	this->varsta = 0;
}

Utilizator::Utilizator(char* nume, int varsta, char* parola)
{
	this->indice = -1;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->parola = new char[strlen(parola) + 1];
	strcpy_s(this->parola, strlen(parola) + 1, parola);
	this->varsta = varsta;
}

Utilizator::Utilizator(const Utilizator& utilizator)
{
	this->nume = new char[strlen(utilizator.nume) + 1];
	strcpy_s(this->nume,strlen(utilizator.nume) + 1, utilizator.nume);

	this->parola = new char[strlen(utilizator.parola) + 1];
	strcpy_s(this->parola, strlen(utilizator.parola) + 1, utilizator.parola);

	this->indice = utilizator.indice;
	this->varsta = utilizator.varsta;
}

Utilizator::~Utilizator()
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = nullptr;
	}

	if (this->parola)
	{
		delete[]this->parola;
		this->nume = nullptr;
	}
}

void Utilizator::setNume(char* nume)
{
	if (this->nume)
	{
		delete[]this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

}

void Utilizator::setVarsta(int varsta)
{
	this->varsta = varsta;
}

void Utilizator::setIndice(int indice)
{
	this->indice = indice;
}


void Utilizator::setParola(char* parola)
{
	if (this->parola)
	{
		delete[]this->parola;
		this->parola = NULL;
	}
	this->parola = new char[strlen(parola) + 1];
	strcpy_s(this->parola, strlen(parola) + 1, parola);
}

int Utilizator::getVarsta()
{
	return this->varsta;
}

char* Utilizator::getNume()
{
	return this->nume;
}

char* Utilizator::getParola()
{
	return this->parola;
}

int Utilizator::getIndice()
{
	return this->indice;
}

Utilizator& Utilizator::operator=(const Utilizator& utilizator)
{
	this->setIndice(utilizator.indice);
	this->setNume(utilizator.nume);
	this->setVarsta(utilizator.varsta);
	this->setParola(utilizator.parola);
	return *this;
}