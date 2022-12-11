#pragma once
#include "RepositoryMesaj.h"
#include "Mesaj.h"

class ServiceMesaj
{
private:
	RepositoryMesaj repositoryMesaj;
public:
	ServiceMesaj();
	ServiceMesaj(RepositoryMesaj repositoryMesaj);
	~ServiceMesaj();
	int getSize();
	void trimiteMesaj(int indice1, int indice2, char* mesaj);
	void stergeMesaj(int indice1, int indice2, char* mesaj, int indice);
	Lista<Mesaj> getChat(int indice);
	Lista<Mesaj> getAll();
};
