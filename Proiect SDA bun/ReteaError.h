#pragma once
#include <exception>

using namespace std;

class ReteaError : public exception
{
private:
	const char* reteaError;

public:
	ReteaError(const char*);
	const char* what();
};
