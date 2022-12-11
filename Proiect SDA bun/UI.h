#pragma once
#include "Service.h"
#include "ServiceAdmin.h"
#include "ReteaError.h"
#include "InputError.h"
#include "ServiceMesaj.h"
#include <iostream>
class UI {
private:
	Service serviceRetea;
	ServiceAdmin serviceAdmin;
	ServiceMesaj serviceMesaj;
	void loginCreateOption();
	void loggedInMenu();
	void loggedInAdmin();
	void loggedIn(int indice);
	void createAccount();
public:
	UI(Service serviceRetea, ServiceAdmin serviceAdmin, ServiceMesaj serviceMesaj);
	UI();
	void loginCreate();
};