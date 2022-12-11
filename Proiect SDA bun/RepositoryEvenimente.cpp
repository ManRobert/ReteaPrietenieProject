#include "RepositoryEvenimente.h"

RepositoryEvenimente::RepositoryEvenimente()
{

}

RepositoryEvenimente::~RepositoryEvenimente()
{

}

void RepositoryEvenimente::addEveniment(Eveniment eveniment)
{
	this->evenimente.add(eveniment);
}

void RepositoryEvenimente::deleteEveniment(Eveniment eveniment)
{
	this->evenimente.deleteElem(eveniment);
}

void RepositoryEvenimente::afisare()
{
	this->evenimente.afisare();
}

bool RepositoryEvenimente::cautare(Eveniment eveniment)
{
	return this->evenimente.searchElem(eveniment);
}
