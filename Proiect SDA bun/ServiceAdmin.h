#pragma once
#include "Eveniment.h"
#include "RepositoryEvenimente.h"
#include "InputError.h"
#include "Eveniment.h"

class ServiceAdmin {
private:
	RepositoryEvenimente evenimente;
public:
	ServiceAdmin();
	ServiceAdmin(RepositoryEvenimente evenimente);
	~ServiceAdmin();
	void adauga(char* nume, int ziua, int luna, int an, int ora);
	void sterge(char* nume, int ziua, int luna, int an, int ora);
	bool cautare(char* nume, int ziua, int luna, int an, int ora);
	void vizuealizeaza();
};