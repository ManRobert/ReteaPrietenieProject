#pragma once
#include <exception>

using namespace std;

class ReteaPrietenieError : public exception
{
private:
	const char* reteaPrietenieError;

public:
	ReteaPrietenieError(const char*);
	const char* what();
};
