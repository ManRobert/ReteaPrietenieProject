#pragma once
#include "Nod.h"
template<class T>

class ArboreBinar
{
private:	

	Nod<T>* radacina;
	//<summary>
	// adauga un element de tipul T
	//</summary>
	//<param name="element"> elementul de adaugat </param>
	//<param name="nod"> elementul de unde se incepe parcurgerea </param>
	int numberOfElelements;
	void privateAdd(Nod<T>* nod, T element)
	{
		if (nod->info > element)
		{
			if (nod->stanga != nullptr)
			{
				privateAdd(nod->stanga, element);
			}
			else
			{
				nod->stanga = new Nod<T>(element, nullptr, nullptr);
				this->numberOfElelements++;
			}
		}
		else if (nod->info < element)
		{
			if (nod->dreapta != nullptr)
				privateAdd(nod->dreapta, element);
			else
			{
				nod->dreapta = new Nod<T>(element, nullptr, nullptr);
				this->numberOfElelements++;
			}
		}
	}

	//<summary>
	// cauta un element de tipul T
	//</summary>
	//<param name="element"> elementul de cautat </param>
	//<param name="nod"> elementul de unde se incepe parcurgerea </param>
	// <returns> true/false </returns>
	bool search(Nod <T>* nod, T element)
	{
		if (nod == NULL)
			return false;

		else if (nod->info == element)
			return true;

		if (nod->info > element)
			return search(nod->stanga, element);
		else if (nod->info < element)
			return search(nod->dreapta, element);
	}

	//<summary>
	// afiseaza elementele
	//</summary>
	//<param name="nod"> elementul de unde incepe parcurgerea </param>
	void privateAfisare(Nod <T>* nod)
	{
		if (nod != nullptr)
		{
			privateAfisare(nod->stanga);
			cout << nod->info << endl;
			privateAfisare(nod->dreapta);
		}
	}

	//<summary>
	// cauta cel mai din dreapta element din subarborele cu radacina noulNod si il pune in nodDeSters
	//</summary>
	//<param name="noulNod"> primul nod din subarborele stang al nodului de sters </param>
	//<param name="nodDeSters"> nod de sters </param>
	template<class T>
	void findNod(Nod<T>*& noulNod, Nod<T>*& nodDeSters)
	{
		if (noulNod->dreapta)
		{
			findNod(noulNod->dreapta, nodDeSters);
		}
		else
		{
			nodDeSters->info = noulNod->info;
			Nod<T>* auxiliar = noulNod;
			noulNod = noulNod->stanga;
			delete auxiliar;
			this->numberOfElelements--;
		}
	}
	//<summary>
	// sterge un element de tipul T
	//</summary>
	//<param name="element"> elementul de sters </param>
	//<param name="nod"> elementul de unde se incepe parcurgerea </param>
	void privateDeleteElem(Nod<T>*& nod, T element)
	{
		if (nod != nullptr)
		{
			if (nod->info == element)
			{
				if (nod->stanga == nullptr && nod->dreapta == nullptr)
				{
					delete nod;
					nod = NULL;
					this->numberOfElelements--;
				}

				else if (nod->dreapta == NULL)
				{
					Nod<T>* auxiliar = nod;
					nod = nod->stanga;
					delete auxiliar;
					this->numberOfElelements--;
				}

				else if (nod->stanga == NULL)
				{
					Nod<T>* auxiliar = nod;
					nod = nod->dreapta;
					delete auxiliar;
					this->numberOfElelements--;
				}
				else
					findNod(nod->stanga, nod);
			}
			else
			{
				if (nod->info > element)
					this->privateDeleteElem(nod->stanga, element);
				else
					this->privateDeleteElem(nod->dreapta, element);
			}
		}
		else return;
	}

public:
	/// <summary>
	/// Constructorul implicit
	/// </summary>
	ArboreBinar();
	/// <summary>
	/// metoda de afisare
	/// </summary>
	void afisare();
	//<summary>
	// adauga un element de tipul T
	//</summary>
	//<param name="element"> elementul de adaugat </param>
	void add(T element);
	//<summary>
	// sterge un element de tipul T
	//</summary>
	//<param name="element"> elementul de sters </param>
	void deleteElem(T element);
	//<summary>
	// returneaza numarul elementelor
	//</summary>
	// <returns> numarul </returns>
	int size();
	//<summary>
	// cauta un element de tipul T
	//</summary>
	//<param name="elem"> elementul de cautat </param>
	// <returns> true/false </returns>
	bool searchElem(T elem);
};

template<class T>
inline ArboreBinar<T>::ArboreBinar()
{
	this->radacina = nullptr;
	this->numberOfElelements = 0;
}

template<class T>
inline void ArboreBinar<T>::afisare()
{
	this->privateAfisare(this->radacina);
}

template<class T>
inline void ArboreBinar<T>::add(T element)
{
	if (this->radacina == nullptr)
	{
		this->radacina = new Nod<T>(element, nullptr, nullptr);
		this->numberOfElelements++;
	}
	else this->privateAdd(this->radacina, element);
}

template<class T>
inline void ArboreBinar<T>::deleteElem(T element)
{
	this->privateDeleteElem(this->radacina, element);
}

template<class T>
inline int ArboreBinar<T>::size()
{
	return this->numberOfElelements;
}

template<class T>
inline bool ArboreBinar<T>::searchElem(T elem)
{
	return this->search(this->radacina, elem);
}