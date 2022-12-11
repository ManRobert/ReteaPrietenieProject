#pragma once
#include "Lista.h"
#include "Mesaj.h"
class RepositoryMesaj
{
private:
	Lista<Mesaj> mesaje;

public:
	RepositoryMesaj();
	~RepositoryMesaj();
	void readFromFile();
	void writeToFile();
	void updateFile();
	void addMesaj(Mesaj mesaj);
	void deleteMesaj(Mesaj mesaj);
	Lista<Mesaj> getAll();
	int getSize();
};