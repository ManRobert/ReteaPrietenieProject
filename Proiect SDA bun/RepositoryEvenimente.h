#pragma once
#include "ArboreBinar.h"
#include "Eveniment.h"
class RepositoryEvenimente
{
private:
	ArboreBinar<Eveniment> evenimente;
public:
	RepositoryEvenimente();
	~RepositoryEvenimente();
	void addEveniment(Eveniment eveniment);
	void deleteEveniment(Eveniment eveniment);
	void afisare();
	bool cautare(Eveniment eveniment);
};