#pragma once
#include <string.h>
#include <iostream>
#include "ListaError.h"
using namespace std;

using namespace std;

template <class T>
class Lista
{
private:
	T* elements;
	int number_of_elements;
	int capacity;
	void resize();
public:
	//<summary>
	// Constructor implicit
	//</summary>
	Lista();
	//<summary>
	// Destructor implicit
	//</summary>
	~Lista() = default;
	//<summary>
	// adauga un element de tipul T
	//</summary>
	//<param name="element"> elementul de adaugat </param>
	void addElem(T element);
	//<summary>
	// sterge un element de pe pozitia indice
	//</summary>
	//<param name="indice"> elementul de sters de pe pozitia </param>
	void deleteElem(int indice);
	//<summary>
	// returneaza toate elementele
	//</summary>
	// <returns> returneaza elementele </returns>
	T* getAll();
	//<summary>
	// returneaza numarul elementelor
	//</summary>
	// <returns> returneaza numarul elementelor </returns>
	int size();
	//<summary>
	// da acces la un elementul de pe pozitia i
	//</summary>
	//<param name="i"> pozitia elementului la care se doreste acces </param>
	// <returns> returneaza adresa </returns>
	T& operator[](int i);
};

template<class T>
inline Lista<T>::Lista()
{
	this->elements = new T[5];
	this->number_of_elements = 0;
	this->capacity = 0;
}

template<class T>
inline void Lista<T>::addElem(T profile)
{
	if (this->capacity == this->number_of_elements)
	{
		resize();
	}
	this->elements[this->number_of_elements] = profile;
	this->number_of_elements++;
}

template<class T>
inline void Lista<T>::deleteElem(int indice)
{	
	/*for (int i = indice; i < number_of_elements - 1; i++)
		elements[i] = elements[i + 1];
	number_of_elements--;*/

	T* auxiliar = new T[this->capacity];

	for (int i = 0; i < indice; i++)
		auxiliar[i] = elements[i];

	for (int i = indice + 1; i < this->number_of_elements; i++)
		auxiliar[i - 1] = elements[i];

	delete[]elements;
	elements = auxiliar;
	number_of_elements--;
}

template<class T>
inline T* Lista<T>::getAll()
{
	return this->elements;
}

template<class T>
inline int Lista<T>::size()
{
	return this->number_of_elements;
}

template<class T>
inline T& Lista<T>::operator[](int i)
{
	if (i < 0 || i >= number_of_elements)
		throw ListaError("Nu exista un element cu acest indice!");
	return elements[i];
}

template<class T>
inline void Lista<T>::resize()
{
	T* auxiliar = new T[this->capacity + 5];
	for (int i = 0; i < this->capacity; i++)
		auxiliar[i] = elements[i];

	delete[]elements;
	elements = auxiliar;
	this->capacity += 5;
}
