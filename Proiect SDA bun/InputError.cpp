#include "InputError.h"

InputError::InputError(const char* error) :inputError(error), exception(error)
{
}

const char* InputError::what()
{
	return this->inputError;
}