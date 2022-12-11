#pragma once
#include "Lista.h"
#include "Utilizator.h"
#include <sstream>
#include <fstream>
#include <string>

class RepositoryUtilizatori {
private:
	Lista<Utilizator> utilizatori;
public:
	RepositoryUtilizatori();
	~RepositoryUtilizatori();
	void readFromFile();
	void writeToFile();
	void updateFile();
	void addUtilizator(Utilizator utilizator);
	void updateUtilizator(int indice, Utilizator utilizatorNou);
	void deleteUtilizator(int indice);
	Lista<Utilizator> getAll();
	int getSize();
};
