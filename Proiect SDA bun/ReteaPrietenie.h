#pragma once
#include <fstream>

class ReteaPrietenie
{
private:
	int** retea;
	int numarLinii;
	int numarColoane;
	ReteaPrietenie();
	static ReteaPrietenie* instance;
public:
	static ReteaPrietenie* getInstance();
	int* getLinie(int linie);
	void resize();
	void addFriend(int profile1, int profile2);
	void deleteFriend(int profile1, int profile2);
	void afiseaza();
	bool check(int profile1, int profile2);
	void writeToFile();
	void readFromFile();
	void deleteOneProfile(int indice);
	int getNumarLinii();
	void setNumarLinii(int numar);
	void setNumarColoane(int numar);
};
