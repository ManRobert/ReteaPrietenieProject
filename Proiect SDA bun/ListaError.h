#pragma once
#include <exception>

using namespace std;

class ListaError : public exception
{
private:
	const char* listaError;

public:
	ListaError(const char*);
	const char* what();
};
