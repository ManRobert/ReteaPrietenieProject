#pragma once

class Mesaj
{
private:
	int indiceUtilizator1, indiceUtilizator2, indice;
	char* mesaj;
public:
	Mesaj();
	Mesaj(int indiceU1, int indiceU2, char* mesaj);
	Mesaj(const Mesaj& mesaj);
	~Mesaj();
	void setIndiceU1(int indice);
	void setIndiceU2(int indice);
	void setMesaj(char* mesaj);
	void setIndice(int indice);
	int getIndice1();
	int getIndice2();
	int getIndice();
	char* getMesaj();
	Mesaj& operator=(const Mesaj& mesaj);
};