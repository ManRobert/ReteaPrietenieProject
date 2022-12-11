#include "ReteaPrietenie.h"
#include <iostream>

using namespace std;

ReteaPrietenie::ReteaPrietenie()
{
	this->retea = new int* [1];
	this->retea[0] = new int[1];
	this->numarColoane = 1;
	this->numarLinii = 1;
	this->retea[0][0] = 0;
	readFromFile();
}

ReteaPrietenie* ReteaPrietenie::instance = 0;

ReteaPrietenie* ReteaPrietenie::getInstance()
{

	if (instance == 0)
	{
		instance = new ReteaPrietenie();
	}

	return instance;

}

int* ReteaPrietenie::getLinie(int linie)
{
	return retea[linie - 1];
}

void ReteaPrietenie::resize()
{
	int** auxiliar;
	auxiliar = new int* [this->numarLinii];
	for (int i = 0; i < this->numarLinii; i++)
		auxiliar[i] = new int[this->numarColoane];

	for (int i = 0; i < this->numarLinii; i++)
		for (int j = 0; j < this->numarColoane; j++)
			auxiliar[i][j] = this->retea[i][j];

	for (int i = 0; i < this->numarLinii; i++)
		delete[]this->retea[i];
	delete[]this->retea;

	retea = new int* [this->numarLinii + 1];
	for (int i = 0; i < this->numarLinii + 1; i++)
		retea[i] = new int[this->numarColoane + 1];

	for (int i = 0; i < this->numarLinii; i++)
		for (int j = 0; j < this->numarColoane; j++)
			retea[i][j] = auxiliar[i][j];

	for (int i = 0; i <= this->numarLinii; i++)
		this->retea[i][this->numarColoane] = 0;

	for (int i = 0; i <= this->numarColoane; i++)
		this->retea[this->numarLinii][i] = 0;

	for (int i = 0; i < this->numarLinii; i++)
		delete[]auxiliar[i];
	delete[]auxiliar;

	this->numarColoane++;
	this->numarLinii++;
	writeToFile();
}

void ReteaPrietenie::addFriend(int profile1, int profile2)
{
	this->retea[profile1][profile2] = 1;
	this->retea[profile2][profile1] = 1;
	writeToFile();
}

void ReteaPrietenie::deleteFriend(int profile1, int profile2)
{
	this->retea[profile1][profile2] = 0;
	this->retea[profile2][profile1] = 0;
	writeToFile();
}

void ReteaPrietenie::afiseaza()
{
	for (int i = 0; i < this->numarLinii; i++) {
		for (int j = 0; j < this->numarColoane; j++)
			cout << this->retea[i][j] << " ";
		cout << endl;
	}
}

bool ReteaPrietenie::check(int profile1, int profile2)
{
	return this->retea[profile1][profile2] == 1 && this->retea[profile2][profile1] == 1;
}

void ReteaPrietenie::writeToFile()
{
	ofstream retea("retea.txt");
	retea << this->numarLinii << endl;
	for (int i = 0; i < numarLinii; i++)
	{
		for (int j = 0; j < numarColoane; j++)
			retea << this->retea[i][j] << " ";
		retea << endl;
	}
	retea.close();
}

void ReteaPrietenie::readFromFile()
{
	ifstream retea("retea.txt");
	int n, i = 0, j = 0;
	retea >> n;
	if (n > 0)
	{
		for (int i = 0; i < this->numarLinii; i++)
			delete[]this->retea[i];
		delete[]this->retea;

		this->retea = new int* [n];
		for (int i = 0; i < n; i++)
			this->retea[i] = new int[n];

		numarLinii = n;
		numarColoane = n;

		while (!retea.eof() && i < n)
		{
			if (j < n)
			{
				retea >> this->retea[i][j];
				j++;
			}
			else
			{
				i++;
				j = 0;
			}
		}
	}
	retea.close();
}

void ReteaPrietenie::deleteOneProfile(int indice)
{
	int** auxiliar;
	auxiliar = new int* [this->numarLinii - 1];
	for (int i = 0; i < this->numarLinii - 1; i++)
		auxiliar[i] = new int[this->numarColoane - 1];

	int x = 0, y, i = 0;

	for (int i = 0; i < this->numarLinii; i++)
	{	
		y = 0;
		if (i != indice)
		{
			for (int j = 0; j < this->numarColoane; j++)
			{
				if (j != indice)
				{
					auxiliar[x][y] = this->retea[i][j];
					y++;
				}
			}
			x++;
		}
	}

	for (int i = 0; i < this->numarLinii; i++)
		delete[]this->retea[i];
	delete[]this->retea;

		numarLinii--;
		numarColoane--;

	retea = new int* [this->numarLinii];
	for (int i = 0; i < this->numarLinii; i++)
		retea[i] = new int[this->numarColoane];

	for (int i = 0; i < this->numarLinii; i++)
		for (int j = 0; j < this->numarColoane; j++)
		{
			retea[i][j] = auxiliar[i][j];
		}

	for (int i = 0; i < this->numarLinii - 2; i++)
		delete[]auxiliar[i];
	delete[]auxiliar;

	if (numarLinii == 0)
	{
		this->retea = new int* [1];
		this->retea[0] = new int[1];
		this->numarColoane = 1;
		this->numarLinii = 1;
		this->retea[0][0] = 0;

	}

	writeToFile();
}

int ReteaPrietenie::getNumarLinii()
{
	return this->numarLinii;
}

void ReteaPrietenie::setNumarLinii(int numar)
{
	this->numarLinii = numar;
}

void ReteaPrietenie::setNumarColoane(int numar)
{
	this->numarColoane = numar;
}
