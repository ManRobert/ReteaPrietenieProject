#include "Mesaj.h"
#include <string.h>
#include <iostream>
using namespace std;

Mesaj::Mesaj()
{
	this->indiceUtilizator1 = -1;
	this->indiceUtilizator2 = -1;
	this->mesaj = nullptr;
	this->indice = -1;
}

Mesaj::Mesaj(int indiceU1, int indiceU2, char* mesaj)
{
	this->indice = -1;
	this->indiceUtilizator1 = indiceU1;
	this->indiceUtilizator2 = indiceU2;
	this->mesaj = new char[strlen(mesaj) + 1];
	strcpy_s(this->mesaj, strlen(mesaj) + 1, mesaj);
}

Mesaj::Mesaj(const Mesaj& mesaj)
{
	this->mesaj = new char[strlen(mesaj.mesaj) + 1];
	strcpy_s(this->mesaj, strlen(mesaj.mesaj) + 1, mesaj.mesaj);
	this->indice = mesaj.indice;
	this->indiceUtilizator1 = mesaj.indiceUtilizator1;
	this->indiceUtilizator2 = mesaj.indiceUtilizator2;
}

Mesaj::~Mesaj()
{
	if (this->mesaj!= nullptr)
	{
		delete[]this->mesaj;
		this->mesaj = nullptr;
	}
}

void Mesaj::setIndiceU1(int indice)
{
	this->indiceUtilizator1 = indice;
}

void Mesaj::setIndiceU2(int indice)
{
	this->indiceUtilizator2 = indice;
}

void Mesaj::setMesaj(char* mesaj)
{
	if (this->mesaj)
	{
		delete[]this->mesaj;
		this->mesaj = NULL;
	}
	this->mesaj = new char[strlen(mesaj) + 1];
	strcpy_s(this->mesaj, strlen(mesaj) + 1, mesaj);
}

void Mesaj::setIndice(int indice)
{
	this->indice = indice;
}

int Mesaj::getIndice1()
{
	return this->indiceUtilizator1;
}

int Mesaj::getIndice2()
{
	return this->indiceUtilizator2;
}

int Mesaj::getIndice()
{
	return this->indice;
}

char* Mesaj::getMesaj()
{
	return this->mesaj;
}

Mesaj& Mesaj::operator=(const Mesaj& mesaj)
{
	setIndiceU1(mesaj.indiceUtilizator1);
	setIndiceU2(mesaj.indiceUtilizator2);
	setMesaj(mesaj.mesaj);
	setIndice(mesaj.indice);
	return *this;
}
