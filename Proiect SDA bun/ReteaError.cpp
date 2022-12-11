#include "ReteaError.h"

ReteaError::ReteaError(const char* error) :reteaError(error), exception(error)
{
}

const char* ReteaError::what()
{
	return this->reteaError;
}