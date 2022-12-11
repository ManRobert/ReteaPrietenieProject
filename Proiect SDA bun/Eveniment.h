#pragma once
#include <iostream>
using namespace std;

class Eveniment
{
private:
	char* nume;
	int ziua, luna, anul, ora;
public:
	Eveniment();
	Eveniment(char* nume, int ziua, int luna, int anul, int ora);
	Eveniment(const Eveniment& eveniment);
	~Eveniment() = default;
	void setNume(char* numeNou);
	void setZiua(int ziuaNoua);
	void setLuna(int lunaNoua);
	void setAnul(int anulNou);
	void setOra(int oraNoua);
	char* getNume();
	int getZiua();
	int getLuna();
	int getAnul();
	int getOra();
	Eveniment& operator=(const Eveniment& eveniment);
	bool operator==(const Eveniment& eveniment);
	bool operator<(const Eveniment& eveniment) const;
	bool operator>(const Eveniment& eveniment) const;
	friend ostream& operator<<(ostream& os, const Eveniment& eveniment);
};