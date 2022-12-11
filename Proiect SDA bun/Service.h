#pragma once
#include "RepositoryUtilizatori.h"
#include "ReteaPrietenie.h"
#include "ReteaError.h"
#include "ReteaPrietenieError.h"

class Service {
private:
	RepositoryUtilizatori repositoryUtilizatori;
	ReteaPrietenie* reteaPrietenie;
public:
	Service(RepositoryUtilizatori repositoryUtilizatori);
	Service();
	void addUtilizator(char * nume, int varsta, char * parola);
	void updateUtilizator(int indice, char* nume, int varsta, char* parola);
	void deleteUtilizator(int indice);
	Lista<Utilizator> getAll();
	int verifyUserName(char* nume);
	void verifyPassword(char* password, int indice);
	Lista<Utilizator> getSuggestions(int indice);
	Lista<Utilizator> getFriends(int indice);
	void addFriend(int indice1, int indice2);
	void deleteFriend(int indice1, int indice2);
	ReteaPrietenie* getReteaPrietenie();
};