#include "ServiceMesaj.h"
#include <iostream>
using namespace std;

ServiceMesaj::ServiceMesaj()
{
}

ServiceMesaj::ServiceMesaj(RepositoryMesaj repositoryMesaj)
{
	this->repositoryMesaj = repositoryMesaj;
}

ServiceMesaj::~ServiceMesaj()
{
}

int ServiceMesaj::getSize()
{
	return this->repositoryMesaj.getSize();
}

void ServiceMesaj::trimiteMesaj(int indice1, int indice2, char *mesaj)
{
	Mesaj mesajCreat(indice1, indice2, mesaj);
	mesajCreat.setIndice(this->repositoryMesaj.getSize());
	this->repositoryMesaj.addMesaj(mesajCreat);
}

void ServiceMesaj::stergeMesaj(int indice1, int indice2, char* mesaj, int indice)
{
	Mesaj mesajCreat(indice1, indice2, mesaj);
	mesajCreat.setIndice(indice);
	this->repositoryMesaj.deleteMesaj(mesajCreat);
	Lista<Mesaj> lista = repositoryMesaj.getAll();
	for (int i = 0; i < lista.size(); i++)
		lista[i].setIndice(i);
	this->repositoryMesaj.updateFile();
}

Lista<Mesaj> ServiceMesaj::getChat(int indice)
{
	Lista<Mesaj>chat, mesaje;
	mesaje = this->repositoryMesaj.getAll();
	for (int i = 0; i < mesaje.size(); i++)
		if(mesaje[i].getIndice1() == indice || mesaje[i].getIndice2())
			chat.addElem(mesaje[i]);

	return chat;
}

Lista<Mesaj> ServiceMesaj::getAll()
{
	return this->repositoryMesaj.getAll();
}
