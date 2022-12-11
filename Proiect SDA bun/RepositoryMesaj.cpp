#include "RepositoryMesaj.h"
#include <sstream>
#include <fstream>
#include <string>

RepositoryMesaj::RepositoryMesaj()
{
	readFromFile();
}

RepositoryMesaj::~RepositoryMesaj()
{
}

void RepositoryMesaj::readFromFile()
{
	fstream mesajeCsv;
	string line, word;

	mesajeCsv.open("mesaje.csv", ios::in | ios::app);
	int indice, indice1, indice2;
		char mesaj[100];

	while (getline(mesajeCsv, line))
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
				indice1 = stoi(word);
				j = 2;
			}

			else if (j == 2)
			{
				indice2 = stoi(word);
				j = 3;
			}

			else if (j == 3)
			{
				strcpy_s(mesaj, strlen(word.c_str()) + 1, word.c_str());
				j = 0;
				Mesaj m(indice1, indice2, mesaj);
				m.setIndice(this->mesaje.size());
				this->mesaje.addElem(m);
			}
		}
	}
}

void RepositoryMesaj::writeToFile()
{
	fstream mesajeCsv;

	mesajeCsv.open("mesaje.csv", ios::out | ios::app);
	mesajeCsv.clear();
	mesajeCsv << mesaje[mesaje.size() - 1].getIndice()
		<< "," << mesaje[mesaje.size() - 1].getIndice1()
		<< "," << mesaje[mesaje.size() - 1].getIndice2()
		<< "," << mesaje[mesaje.size() - 1].getMesaj() << endl;
	mesajeCsv.close();
}

void RepositoryMesaj::updateFile()
{
	fstream mesajeCsv;

	mesajeCsv.open("mesaje2.csv", ios::out | ios::app);
	mesajeCsv.clear();
	for (int i = 0; i < mesaje.size(); i++)
		mesajeCsv << mesaje[i].getIndice()
		<< "," << mesaje[i].getIndice1()
		<< "," << mesaje[i].getIndice2()
		<< "," << mesaje[i].getMesaj() << endl;
	mesajeCsv.close();
	remove("mesaje.csv");
	rename("mesaje2.csv", "mesaje.csv");
}

void RepositoryMesaj::addMesaj(Mesaj mesaj)
{
	this->mesaje.addElem(mesaj);
	writeToFile();
}

void RepositoryMesaj::deleteMesaj(Mesaj mesaj)
{
	this->mesaje.deleteElem(mesaj.getIndice());
}

Lista<Mesaj> RepositoryMesaj::getAll()
{
	return this->mesaje;
}

int RepositoryMesaj::getSize()
{
	return this->mesaje.size();
}
