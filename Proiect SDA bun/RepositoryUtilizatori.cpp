#include "RepositoryUtilizatori.h"

RepositoryUtilizatori::RepositoryUtilizatori()
{
	readFromFile();
}

RepositoryUtilizatori::~RepositoryUtilizatori()
{

}

void RepositoryUtilizatori::readFromFile()
{
	fstream utilizatoriCsv;
	string line, word;

	utilizatoriCsv.open("utilizatori.csv", ios::in | ios::app);
	int indice, varsta;
	char nume[100], parola[100];

	while (getline(utilizatoriCsv, line))
	{
		stringstream str(line);
		int j = 0;
		while (getline(str, word, ','))
		{
			if (j == 0)
			{
				indice = stoi(word);
				j = 1;
			}

			else if (j == 1)
			{
				strcpy_s(nume, strlen(word.c_str()) + 1, word.c_str());
				j = 2;
			}

			else if (j == 2)
			{
				varsta = stoi(word);
				j = 3;
			}

			else if (j == 3)
			{
				strcpy_s(parola, strlen(word.c_str()) + 1, word.c_str());
				j = 0;
				Utilizator u(nume, varsta, parola);
				u.setIndice(this->utilizatori.size());
				this->utilizatori.addElem(u);
			}
		}
	}
}

void RepositoryUtilizatori::writeToFile()
{
	fstream utilizatoriCsv;

	utilizatoriCsv.open("utilizatori.csv", ios::out | ios::app);
	utilizatoriCsv.clear();
	utilizatoriCsv << utilizatori[utilizatori.size() - 1].getIndice()
		<< "," << utilizatori[utilizatori.size() - 1].getNume()
		<< "," << utilizatori[utilizatori.size() - 1].getVarsta()
		<< "," << utilizatori[utilizatori.size() - 1].getParola() << endl;
	utilizatoriCsv.close();
}

void RepositoryUtilizatori::updateFile()
{
	fstream utilizatoriCsv;

	utilizatoriCsv.open("utilizatori2.csv", ios::out | ios::app);
	utilizatoriCsv.clear();
	for(int i = 0; i < utilizatori.size(); i++)
		utilizatoriCsv << utilizatori[i].getIndice()
			<< "," << utilizatori[i].getNume()
			<< "," << utilizatori[i].getVarsta()
			<< "," << utilizatori[i].getParola() << endl;
	utilizatoriCsv.close();
	remove("utilizatori.csv");
	rename("utilizatori2.csv", "utilizatori.csv");
}

void RepositoryUtilizatori::addUtilizator(Utilizator utilizator)
{
	this->utilizatori.addElem(utilizator);
	writeToFile();

}

void RepositoryUtilizatori::updateUtilizator(int indice, Utilizator utilizatorNou)
{
	utilizatori[indice] = utilizatorNou;
}

void RepositoryUtilizatori::deleteUtilizator(int indice)
{
	utilizatori.deleteElem(indice);
}

Lista<Utilizator> RepositoryUtilizatori::getAll()
{
	return this->utilizatori;
}

int RepositoryUtilizatori::getSize()
{
	return this->utilizatori.size();
}
