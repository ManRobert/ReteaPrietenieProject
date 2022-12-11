#pragma once
#include <exception>

using namespace std;

class InputError : public exception
{
private:
	const char* inputError;

public:
	InputError(const char*);
	const char* what();
};
