#pragma once
class Utilizator
{
private:
	int indice;
	char* nume;
	int varsta;
	char* parola;
public:
	Utilizator();
	Utilizator(char* nume, int varsta, char* parola);
	Utilizator(const Utilizator& utilizator);
	~Utilizator();
	void setNume(char* nume);
	void setVarsta(int varsta);
	void setIndice(int indice);
	void setParola(char* parola);
	int getVarsta();
	char* getNume();
	char* getParola();
	int getIndice();
	Utilizator& operator=(const Utilizator& utilizator);
};