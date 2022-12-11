#include "UI.h"
using namespace std;

UI::UI(Service serviceRetea, ServiceAdmin serviceAdmin, ServiceMesaj serviceMesaj)
{
	this->serviceRetea = serviceRetea;
	this->serviceAdmin = serviceAdmin;
	this->serviceMesaj = serviceMesaj;
}

UI::UI()
{
}

void UI::loginCreateOption()
{
	cout << "Tastati 1 pentru logare " << endl;
	cout << "Tastati 2 pentru creare cont" << endl;
	cout << "Tastati 'admin' pentru a gestiona evenimente pentru utilizatori" << endl;
	cout << "Tastati x pentru a iesi din aplicatie" << endl << endl;
}

void UI::loginCreate()
{
	char optiune[100];
	cout << "Login/ create account" << endl;
	while (true)
	{
		loginCreateOption();

		cin.getline(optiune, 100);
		
		if (strcmp(optiune, "1") == 0)
		{
			try {
				char nume[100], parola[100];
				cout << "Introduceti numele dumneavoastra" << endl;
				cin.getline(nume, 100);
				int indice = this->serviceRetea.verifyUserName(nume);
				cout << "Introduceti parola dumneavoastra" << endl;
				cin.getline(parola, 100);
				this->serviceRetea.verifyPassword(parola, indice);
				cout << endl;
				loggedIn(indice);
				cin.getline(optiune, 100);
			}

			catch (ReteaError& error)
			{
				cout << error.what() << endl << endl;
			}

			catch (...)
			{
				cout << "Eroare necunoscuta" << endl;
			}
		}

		else if (strcmp(optiune, "2") == 0)
			createAccount();

		else if (strcmp(optiune, "admin") == 0)
			loggedInAdmin();

		else if (strcmp(optiune, "x") == 0)
			break;

		else
			cout << "Optiune gresita, alegeti din nou!" << endl << endl;
	}
}

void UI::loggedInMenu()
{
	cout << "Tastati 1. pentru a afisa lista de prieteni" << endl;
	cout << "Tastati 2. pentru a adauga un prieten" << endl;
	cout << "Tastati 3. pentru a sterge un prieten" << endl;
	cout << "Tastati 4. pentru a trimite un mesaj" << endl;
	cout << "Tastati 5. pentru a sterge un mesaj" << endl;
	cout << "Tastati a. pentru a afisa o conversatie" << endl;
	cout << "Tastati 6. pentru a va modifica contul" << endl;
	cout << "Tastati 7. pentru a va sterge contul" << endl;
	cout << "Tastati 8. pentru a vizualiza evenimente disponibile" << endl;
	cout << "Tastati x. pentru a va deconecta" << endl;
	cout << "Dati optiunea:" << endl << endl;
}

void citireDateEveniment(char nume[100], int &ziua, int &luna,int &anul,int &ora)
{
		cout << "Numele evenimentului:" << endl;
		cin.getline(nume, 100);
		if (strlen(nume) < 3)
			throw ReteaError("Numele trebuie sa fie de minim 3 caractere");

		cout << "Ziua:" << endl;
		cin >> ziua;
		if (!cin)
			throw InputError("Trebuia sa introduci un int la ziua!");
		if (ziua < 1 || ziua > 31)
			throw InputError("Zi incorecta!");

		cout << "Luna:" << endl;
		cin >> luna;
		if (!cin)
			throw InputError("Trebuia sa introduci un int la luna!");
		if (luna < 1 || luna > 12)
			throw InputError("Luna incorecta!");

		cout << "Anul:" << endl;
		cin >> anul;
		if (!cin)
			throw InputError("Trebuia sa introduci un int la an!");
		if (anul < 2022)
			throw InputError("An incorect!");

		cout << "Ora:" << endl;
		cin >> ora;
		if (!cin)
			throw InputError("Trebuia sa introduci un int la ora!");
		if (ora < 0 || ora > 23)
			throw InputError("Ora incorecta!");

}

void citireNumeEveniment(char nume[100], int& ziua, int& luna, int& anul, int& ora)
{
		cout << "Numele evenimentului:" << endl;
		cin.getline(nume, 100);
		if (strlen(nume) < 3)
			throw ReteaError("Numele trebuie sa fie de minim 3 caractere");

		ziua = 10;

		luna = 10;

		anul = 2022;

		ora = 10;
}

void UI::loggedInAdmin()
{
	while (true)
	{
		cout << "1. Adauga eveniment pentru utilizatori" << endl;
		cout << "2. Sterge un eveniment" << endl;
		cout << "3. Vizualizeaza evenimente" << endl;
		cout << "4. Pentru a cauta un eveniment" << endl;
		cout << "x Deconecteaza-te" << endl << endl;

		char optiune3[100];
		cin.getline(optiune3, 100);

		if (strcmp(optiune3, "1") == 0)
		{
			try
			{
				cout << "Atentie! Dupa inchiderea programului acest eveniment va fi sters!" << endl;
				cout << "Vor ramane doar evenimentele initiale!" << endl << endl;

				char nume[100];
				int ziua, luna, anul, ora;
				citireDateEveniment(nume, ziua, luna, anul, ora);
				this->serviceAdmin.adauga(nume, ziua, luna, anul, ora);
				cin.getline(optiune3, 100);
			}

			catch (InputError& error)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << error.what() << endl << endl;
			}

			catch (ReteaError& error)
			{
				cout << error.what() << endl << endl;
			}

			catch (...)
			{
				cout << "Eroare necunoscuta" << endl;
			}
		}

		else if (strcmp(optiune3, "2") == 0)
		{
			try
			{
				char nume[100];
				int ziua, luna, anul, ora;
				citireNumeEveniment(nume, ziua, luna, anul, ora);
				this->serviceAdmin.sterge(nume, ziua, luna, anul, ora);
			}

			catch (ReteaError& error)
			{
				cout << error.what() << endl << endl;
			}

			catch (...)
			{
				cout << "Eroare necunoscuta" << endl;
			}
		}

		else if (strcmp(optiune3, "3") == 0)
		{
			try 
			{
				this->serviceAdmin.vizuealizeaza();
			}

			catch (...)
			{
				cout << "Eroare necunoscuta" << endl;
			}
		}

		else if (strcmp(optiune3, "4") == 0)
		{
			try {
				char nume[100];
				int ziua, luna, anul, ora;
				citireNumeEveniment(nume, ziua, luna, anul, ora);
				bool verify = this->serviceAdmin.cautare(nume, ziua, luna, anul, ora);
				if (verify)
					cout << "Evenimentul exista" << endl;
				else cout << "Evenimentul nu exista" << endl;
			}

			catch (ReteaError& error)
			{
				cout << error.what() << endl << endl;
			}

			catch (...)
			{
				cout << "Eroare necunoscuta" << endl;
			}
		}

		else if(strcmp(optiune3, "x") == 0)
			break;

		else cout << "Optiune gresita" << endl << endl;
	}
}

void UI::loggedIn(int indice)
{
	cout << "Bun venit!" << endl;
	while (true)
	{
			loggedInMenu();

			char optiune2[100];
			cin >> optiune2;

			if (strcmp(optiune2, "1") == 0)
			{
				try
				{
					Lista<Utilizator> listaPrieteni = serviceRetea.getFriends(indice);

					cout << "Prietenii dumneavoastra sunt:" << endl;
					for (int i = 0; i < listaPrieteni.size(); i++)
						cout << listaPrieteni[i].getNume() << endl;
					cout << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}

			}

			else if (strcmp(optiune2, "2") == 0)
			{
				try
				{
				Lista<Utilizator> listaSugestiiPrieteni = serviceRetea.getSuggestions(indice);

				cout << "Sugestii pentru prieteni: " << endl;

				for (int i = 0; i < listaSugestiiPrieteni.size(); i++)
					cout << listaSugestiiPrieteni[i].getIndice() << " " << listaSugestiiPrieteni[i].getNume() << endl;

				cout << "Alegeti un numar. " << endl;


					int indice2;
					cin >> indice2;
					if (!cin)
						throw InputError("Nu ati scris un numar!");
					serviceRetea.addFriend(indice, indice2);
					cout << "Acum sunteti prieteni pe aceasta retea!" << endl << endl;
				}

				catch (InputError& error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << error.what() << endl << endl;
				}

				catch (ReteaPrietenieError& error)
				{
					cout << error.what() << endl << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "3") == 0)
			{
				try
				{
				Lista<Utilizator> listaPrieteni = serviceRetea.getFriends(indice);

				cout << "Sugestii pentru stergere prieteni. Alegeti un numar :" << endl;

				for (int i = 0; i < listaPrieteni.size(); i++)
					cout << listaPrieteni[i].getIndice() << " " << listaPrieteni[i].getNume() << endl;


					int indice2;
					cin >> indice2;
					if(!cin)
						throw InputError("Nu ati scris un numar!");
					serviceRetea.deleteFriend(indice, indice2);
					cout << "Acum nu mai sunteti prieteni pe aceasta retea!" << endl << endl;
				}

				catch (InputError& error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << error.what() << endl << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "4") == 0)
			{
				try
				{
				Lista<Utilizator> listaPrieteni = serviceRetea.getFriends(indice);

				cout << "Puteti da mesaj urmatorilor: " << endl;

				for (int i = 0; i < listaPrieteni.size(); i++)
					cout << listaPrieteni[i].getIndice() << " " << listaPrieteni[i].getNume() << endl;

				cout << "Alegeti un numar: " << endl;

					int indice2;
					cin >> indice2;
					cout << endl;
					if (!cin)
						throw InputError("Nu ati scris un numar!");

					if (serviceRetea.getReteaPrietenie()->check(indice, indice2))
					{
						cout << "Scrieti mesajul: " << endl;
						char mesaj[100];
						cin.getline(mesaj, 100);
						cin.getline(mesaj, 100);
						this->serviceMesaj.trimiteMesaj(indice, indice2, mesaj);
					}

					else cout << "Ati ales un numar gresit! " << endl << endl;
				}

				catch (InputError& error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << error.what() << endl << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "5") == 0)
			{
			try
			{
				cout << "Atentie! Daca stergeti un mesaj cu cineva, acel mesaj va fi sters si pentru cealata persoana" << endl;
				cout << "Aveti urmatorul istoric de mesaje pe care le puteti sterge: " << endl << endl;
				Lista<Mesaj> istoric = serviceMesaj.getAll();
				Lista<Utilizator> lista = serviceRetea.getAll();

				for (int i = 0; i < istoric.size(); i++)
					//if (serviceRetea.getReteaPrietenie()->check(indice, i))
						if (istoric[i].getIndice1() == indice || istoric[i].getIndice2() == indice)
							cout << istoric[i].getIndice() << ".Mesaj: " << istoric[i].getMesaj()
							<<","<<
							" Participanti: " << lista[istoric[i].getIndice1()].getNume()
							<< "-" << lista[istoric[i].getIndice2()].getNume() << endl << endl;
					

				cout << "Dati indicele mesajului de sters: " << endl;

					int indiceMesajDeSters;
					cin >> indiceMesajDeSters;
					cout << indiceMesajDeSters << endl;
					cout << endl;
					if (!cin)
						throw InputError("Nu ati scris un numar!");

					if (istoric[indiceMesajDeSters].getIndice1() == indice || istoric[indiceMesajDeSters].getIndice2() == indice)
					{
						//if (serviceRetea.getReteaPrietenie()->check(indice, indiceMesajDeSters))
							serviceMesaj.stergeMesaj(istoric[indiceMesajDeSters].getIndice1(),
								istoric[indiceMesajDeSters].getIndice2(),
								istoric[indiceMesajDeSters].getMesaj(), indiceMesajDeSters);
					}

					else cout << "Ati ales un numar gresit!" << endl << endl;
				}

				catch (InputError& error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << error.what() << endl << endl;
				}

				catch (ListaError& error)
				{
					cout << error.what() << endl << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "a") == 0)
				{
				try
				{
					Lista<Mesaj> istoric = serviceMesaj.getAll();
					Lista<Utilizator> lista = serviceRetea.getAll();
					cout << "Dati indicele prietenului cu care doriti sa vedeti conversatia " << endl << endl;

					for (int i = 0; i < lista.size(); i++)
						if (serviceRetea.getReteaPrietenie()->check(indice, i))
							cout << lista[i].getIndice() << " " << lista[i].getNume() << endl << endl;
						int indicePrieten;
						cin >> indicePrieten;
						cout << endl;
						if (!cin)
							throw InputError("Nu ati scris un numar!");

						if (serviceRetea.getReteaPrietenie()->check(indice, indicePrieten))
						{
							for (int i = 0; i < istoric.size(); i++)
								if ((istoric[i].getIndice1() == indice && istoric[i].getIndice2() == indicePrieten)
									|| (istoric[i].getIndice1() == indicePrieten && istoric[i].getIndice2() == indice))
									cout << istoric[i].getIndice() << ".Mesaj: " << istoric[i].getMesaj()
									<< "," << 
									" Participanti: " << lista[istoric[i].getIndice1()].getNume()
									<< "-" << lista[istoric[i].getIndice2()].getNume() << endl << endl;
						}
					}

					catch (InputError& error)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << error.what() << endl << endl;
					}

					catch (...)
					{
						cout << "Eroare necunoscuta" << endl;
					}
				}

			else if (strcmp(optiune2, "6") == 0)
			{
				try {
					int varsta;
					cout << "Introduceti noua varsta: ";
					cin >> varsta;
					if (!cin)
						throw InputError("Trebuie sa introduceti doar cifre!");

					char nume[100];
					cout << "Introduceti noul numele: ";
					cin.getline(nume, 100);
					cin.getline(nume, 100);

					char parola[100];
					cout << "Introduceti noua parola: ";
					cin.getline(parola, 100);

					cout << endl;

					serviceRetea.updateUtilizator(indice, nume, varsta, parola);
				}

				catch (ReteaError& error)
				{
					cout << error.what() << endl << endl;
				}

				catch (InputError& error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << error.what() << endl << endl;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "7") == 0)
			{
				try
				{
					cout << "Atentie! Toate chat urile cu dumnevoastra au fost sterse!" << endl << endl;

					int i = 0;
					while (i < serviceMesaj.getSize()) {
						if (serviceMesaj.getAll()[i].getIndice1() == indice || serviceMesaj.getAll()[i].getIndice2() == indice)
							serviceMesaj.stergeMesaj(serviceMesaj.getAll()[i].getIndice1(),
								serviceMesaj.getAll()[i].getIndice2(),
								serviceMesaj.getAll()[i].getMesaj(),
								serviceMesaj.getAll()[i].getIndice());
						else i++;
					}
					serviceRetea.deleteUtilizator(indice);
					break;
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "8") == 0)
			{
				try
				{
					serviceAdmin.vizuealizeaza();
				}

				catch (...)
				{
					cout << "Eroare necunoscuta" << endl;
				}
			}

			else if (strcmp(optiune2, "x") == 0)
			{	
				cout << "La revedere" << endl << endl;
				break;
			}

			else
				cout << "Optiune gresita, alegeti din nou!" << endl << endl;
		}
	}

void UI::createAccount()
{	
	try {
		int varsta;
		cout << "Introduceti varsta dumneavoastra: ";
		cin >> varsta;
		if (!cin)
			throw InputError("Trebuie sa introduceti doar cifre!");

		char nume[100];
		cout << "Introduceti numele dumneavoastra complet: ";
		cin.getline(nume, 100);
		cin.getline(nume, 100);

		char parola[100];
		cout << "Introduceti o parola: ";
		cin.getline(parola, 100);

		this->serviceRetea.addUtilizator(nume, varsta, parola);
		cout << endl;
	}

	catch (ReteaError& error)
	{
		cout << error.what() << endl;
	}

	catch (InputError & error)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << error.what() << endl << endl;
	}

	catch (...)
	{
		cout << "Eroare necunoscuta" << endl;
	}
}
