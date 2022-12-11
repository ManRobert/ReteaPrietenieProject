#include <iostream>
#include "RepositoryUtilizatori.h"
#include "RepositoryEvenimente.h"
#include "Service.h"
#include "ServiceAdmin.h"
#include "UI.h"
#include "RepositoryMesaj.h"
#include "ServiceMesaj.h"
using namespace std;


int main()
{
	RepositoryUtilizatori repositoryUtilizatori;
	RepositoryEvenimente repositoryEvenimente;
	RepositoryMesaj repositoryMesaj;

	char nume1[6] = "nume1", nume2[6] = "nume2", nume3[6] = "nume3";
	Eveniment eveniment1(nume1, 2, 1, 2022, 0);
	Eveniment eveniment2(nume2, 2, 2, 2023, 1);
	Eveniment eveniment3(nume3, 3, 3, 2024, 2);
	repositoryEvenimente.addEveniment(eveniment1);
	repositoryEvenimente.addEveniment(eveniment2);
	repositoryEvenimente.addEveniment(eveniment3);

	Service serviceRetea(repositoryUtilizatori);
	ServiceAdmin serviceAdmin(repositoryEvenimente);
	ServiceMesaj serviceMesaj(repositoryMesaj);
	UI uiRetea(serviceRetea, serviceAdmin, serviceMesaj);
	uiRetea.loginCreate();

	return 0;
}
