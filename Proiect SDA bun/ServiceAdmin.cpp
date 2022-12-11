#include "ServiceAdmin.h"

ServiceAdmin::ServiceAdmin()
{
}

ServiceAdmin::ServiceAdmin(RepositoryEvenimente evenimente)
{
	this->evenimente = evenimente;
}

ServiceAdmin::~ServiceAdmin()
{
}

void ServiceAdmin::adauga(char* nume, int ziua, int luna, int an, int ora)
{
	Eveniment eveniment(nume, ziua, luna, an, ora);
	this->evenimente.addEveniment(eveniment);
}

void ServiceAdmin::sterge(char* nume, int ziua, int luna, int an, int ora)
{
	Eveniment eveniment(nume, ziua, luna, an, ora);
	evenimente.deleteEveniment(eveniment);
}

bool ServiceAdmin::cautare(char* nume, int ziua, int luna, int an, int ora)
{
	Eveniment eveniment(nume, ziua, luna, an, ora);
	return this->evenimente.cautare(eveniment);
}

void ServiceAdmin::vizuealizeaza()
{
	evenimente.afisare();
}
