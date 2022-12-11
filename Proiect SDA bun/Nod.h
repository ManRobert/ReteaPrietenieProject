#pragma once
#include<iostream>
using namespace std;
template<class T>
class ArboreBinar;
template<class T>

class Nod
{
private:
	T info;
	Nod<T>* stanga;
	Nod<T>* dreapta;

public:
	/// <summary>
	/// Constructorul cu informatia info
	/// </summary>	
	///<param name="info"> informatia trimisa pt constructor </param>
	Nod(T info);
	/// <summary>
	/// Constructorul cu informatia info, nod stanga, nod dreapta
	/// </summary>	
	///<param name="info"> informatia trimisa pt constructor </param>
	/// <param name="stanga"> nodul stanga trimis pt constructor </param>
	/// <param name="dreapta"> nodul dreapta trimis pt constructor </param>
	Nod(T info, Nod<T>* stanga, Nod<T>* dreapta):info(info), stanga(stanga),dreapta(dreapta){};
	friend class ArboreBinar<T>;
};

template<class T>
inline Nod<T>::Nod(T info)
{
	this->info = info;
}

