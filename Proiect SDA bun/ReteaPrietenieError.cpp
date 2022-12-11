#include "ReteaPrietenieError.h"

ReteaPrietenieError::ReteaPrietenieError(const char* error) :reteaPrietenieError(error), exception(error)
{
}

const char* ReteaPrietenieError::what()
{
	return this->reteaPrietenieError;
}