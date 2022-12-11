#include "Service.h"

Service::Service(RepositoryUtilizatori repositoryUtilizatori)
{
	this->repositoryUtilizatori = repositoryUtilizatori;
	this->reteaPrietenie = ReteaPrietenie::getInstance();
}

Service::Service()
{
	this->reteaPrietenie = ReteaPrietenie::getInstance();
}

void Service::addUtilizator(char* nume, int varsta, char* parola)
{	
	Lista<Utilizator> lista = repositoryUtilizatori.getAll();
	int i = 0;

	while (i < lista.size())
	{
		if(strcmp(lista[i].getNume(), nume) == 0)
			throw ReteaError("Exista deja utilizator cu acest nume! (Recomandare: adauga in plus caractere pentru un nume unic)");
		i++;
	}

	Utilizator utilizator(nume, varsta, parola);
	utilizator.setIndice(repositoryUtilizatori.getSize());
	repositoryUtilizatori.addUtilizator(utilizator);
	if(repositoryUtilizatori.getSize() > 1)
		reteaPrietenie->resize();
}

void Service::updateUtilizator(int indice, char* nume, int varsta, char* parola)
{
	Lista<Utilizator> lista = repositoryUtilizatori.getAll();
	int i = 0;

	while (i < lista.size())
	{
		if (strcmp(lista[i].getNume(), nume) == 0)
			throw ReteaError("Exista deja utilizator cu acest nume! (Recomandare: adauga in plus caractere pentru un nume unic)");
		i++;
	}

	Utilizator utilizatorNou(nume, varsta, parola);
	utilizatorNou.setIndice(indice);
	repositoryUtilizatori.updateUtilizator(indice, utilizatorNou);
	repositoryUtilizatori.updateFile();
}

void Service::deleteUtilizator(int indice)
{
	repositoryUtilizatori.deleteUtilizator(indice);
	Lista<Utilizator> lista = repositoryUtilizatori.getAll();
	for (int i = 0; i < lista.size(); i++)
		lista[i].setIndice(i);
	repositoryUtilizatori.updateFile();
	reteaPrietenie->deleteOneProfile(indice);
}

Lista<Utilizator> Service::getAll()
{
	return repositoryUtilizatori.getAll();
}

int Service::verifyUserName(char* nume)
{
	Lista<Utilizator> lista = repositoryUtilizatori.getAll();
	bool verify = false;
	int i = 0;
	while (i < lista.size() && !verify)
	{
		if (strcmp(lista[i].getNume(), nume) == 0)
			verify = true;
		else
			i++;
	}
	if (!verify)
		throw ReteaError("Nu exista un utilizator cu acest nume");
	return i;
}

void Service::verifyPassword(char* password, int indice)
{
	Lista<Utilizator> lista = repositoryUtilizatori.getAll();
	bool verify = false;
	if (strcmp(lista[indice].getParola(), password) == 0)
		verify = true;
	if (!verify)
		throw ReteaError("Parola incorecta!");
}

Lista<Utilizator> Service::getSuggestions(int indice)
{
	Lista<Utilizator> lista = repositoryUtilizatori.getAll(), listaSugestii;
	for (int i = 0; i < lista.size(); i++)
		if (!reteaPrietenie->check(indice, i) && indice != i)
			listaSugestii.addElem(lista[i]);

	return listaSugestii;
}

Lista<Utilizator> Service::getFriends(int indice)
{
	Lista<Utilizator> lista = repositoryUtilizatori.getAll(), listaPrieteni;
	for (int i = 0; i < lista.size(); i++)
		if (reteaPrietenie->check(indice, i))
			listaPrieteni.addElem(lista[i]);

	return listaPrieteni;
}

void Service::addFriend(int indice1, int indice2)
{	
	if (indice2 >= 0 && indice2 <= repositoryUtilizatori.getSize() - 1)
	{
		if (!reteaPrietenie->check(indice1, indice2))
			if (indice1 != indice2)
				reteaPrietenie->addFriend(indice1, indice2);
			else throw ReteaPrietenieError("Nu va puteti adauga pe dumneavoastra!");
		else throw ReteaPrietenieError("Sunteti deja prieteni!");
	}
	else throw ReteaPrietenieError("Ai tastat un numar gresit!");
}

void Service::deleteFriend(int indice1, int indice2)
{
	if (reteaPrietenie->check(indice1, indice2))
		reteaPrietenie->deleteFriend(indice1, indice2);
	else throw ReteaPrietenieError("Nu sunteti prieten/a cu persoana aceasta!");
}

ReteaPrietenie* Service::getReteaPrietenie()
{
	return this->reteaPrietenie;
}
