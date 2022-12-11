#include "ListaError.h"

ListaError::ListaError(const char* error) :listaError(error), exception(error)
{
}

const char* ListaError::what()
{
	return this->listaError;
}