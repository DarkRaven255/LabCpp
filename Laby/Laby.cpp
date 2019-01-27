#include <iostream>
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Napis.h"
#include "Kierownik.h"

using namespace std;

int main()
{
	/*char z{'k'};

	Pracownik toMod;
	Pracownik const *isFound;
	Kierownik toModK;
	ListaPracownikow listWorkers;
	ListaPracownikow listManagers;
	Napis imie, nazwisko;
	Data manager;

	while (z!='w')
	{
		std::cout << "1 - Dodaj pracownika\n";
		std::cout << "2 - Usun pracownika\n";
		std::cout << "3 - Wyswietl liste pracownikow\n";
		std::cout << "4 - Wyszukaj pracownika\n";
		std::cout << "5 - Zapisz do pliku\n";
		std::cout << "6 - Wczytaj z pliku\n";
		std::cout << "7 - Dodaj kierownika\n";
		std::cout << "8 - Usun kierownika\n";
		std::cout << "9 - Wyswietl liste kierownikow\n";
		std::cout << "0 - Wyswietl liste wszystkich pracownikow\n";
		std::cout << "w - Wyjdz\n\n";

		fflush(stdin);
		std::cin >> z;
		fflush(stdin);

		switch(z)
		{
		case '1':
			system("cls");
			toMod.Wpisz();
			listWorkers.Dodaj(toMod);
			break;
		case '2':
			system("cls");
			toMod.Wpisz();
			listWorkers.Usun(toMod);
			break;
		case '3':
			system("cls");
			listWorkers.WypiszPracownikow();
			break;
		case '4':
			system("cls");
			std::cout << "Podaj imie: ";
			imie.Wpisz();
			std::cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();

			isFound = listWorkers.Szukaj(nazwisko.Zwroc(), imie.Zwroc());

			if(isFound!=nullptr)
			{
				isFound->Wypisz();
			}
			else std::cout << "Brak takiego pracownika!\n";
			break;
		case '5':
			listWorkers.ZapiszDoPliku();
			system("cls");
			std::cout << "Zapisano!\n";
			break;
		case '6':
			listWorkers.WczytajZPliku();
			system("cls");
			std::cout << "Wczytano!\n";
			break;
		case '7':
			system("cls");
			toModK.Wpisz();
			listManagers.Dodaj(toModK);
			break;
		case '8':
			system("cls");
			toModK.Wpisz();
			listManagers.Usun(toMod);
			break;
		case '9':
			system("cls");
			listManagers.WypiszPracownikow();
			break;
		case '0':
			system("cls");
			std::cout << "Pracownicy:\n";
			listWorkers.WypiszPracownikow();
			std::cout << "Kierownicy:\n";
			listManagers.WypiszPracownikow();
			break;
		default:
			system("cls");
			std::cout << "\nZly wybor!\n";
		case 'w':
			break;
		}
	}*/

	Pracownik *p;
	ListaPracownikow lp;
	const Pracownik *szukany;
	char z;
	int t{};
	Kierownik *k;

	for (;;)
	{

		cout << "MENU" << endl << "----------------------" << endl << "d - dodaj pracownika" << endl << "u - usun pracownika" << endl;
		cout << "w - wyswietl liste pracownikow" << endl << "s - szukaj pracownika" << endl;
		cout << "l - wczytaj z pliku" << endl << "z - zapisz do pliku" << endl;
		cout << "c - skopiuj pracownika" << endl;
		cout << "k - kierownik" << endl;
		cout << "q - wyjscie" << endl << "Wybor: ";
		fflush(stdin);
		cin >> z;

		switch (z)
		{
		case 'd':
			cout << "Dane pracownika do dodania" << endl;
			p = new Pracownik;
			cin >> *p;
			lp.Dodaj(*p);
			delete p;
			break;
		case 'u':
			cout << "Dane pracownika do usuniecia" << endl;
			p = new Pracownik;
			cin >> *p;
			lp.Usun(*p);
			delete p;
			break;
		case 'w':
			cout << "Lista pracownikow: " << endl;
			lp.WypiszPracownikow();
			break;
		case 's':
			cout << "Dane pracownika do wyszukania:" << endl;
			p = new Pracownik;
			cin >> *p;
			szukany = lp.Szukaj(p->Nazwisko(), p->Imie());
			if (szukany != nullptr) { cout << "Znaleziono pracownika." << endl; }
			else { cout << "Nie znaleziono pracownika" << endl; }
			delete p;
			break;
		case 'c':
			cout << "Dane pracownika do skopiowania:" << endl;
			p = new Pracownik;
			cin >> *p;
			szukany = lp.Szukaj(p->Nazwisko(), p->Imie());
			if (szukany != nullptr)
			{
				Pracownik *p1;
				p1 = new Pracownik;
				p1 = p->KopiaObiektu();
				lp.Dodaj(*p1);
				cout << endl << "Znaleziono pracownika i dodano kopie do listy." << endl;
				delete p1;
				/**p1 = *p;
				p1->WypiszDane();
				cout << endl << "Znaleziono pracownika i dodano kopie do listy." << endl;
				lp.Dodaj_kopia(*p1);
				delete p1;*/

			}
			else { cout << "Nie znaleziono pracownika" << endl; }
			delete p;
			break;
		case 'z':
			cout << "Zapisano do pliku" << endl;
			lp.ZapiszDoPliku();
			break;
		case 'k':
			system("CLS");
			t = 0;
			for (;;)
			{
				cout << "d - dodaj kierownika" << endl;
				cout << "w - wyswietl informacje o kierowniku" << endl;
				cout << "s - skopiuj kierownika" << endl;
				cout << "q - wyjsc" << endl;
				cout << "Wybor: ";
				fflush(stdin);
				cin >> z;
				switch (z)
				{
				case'd':
					k = new Kierownik;
					cin >> *k;
					lp.Dodaj(*k);
					t++;
					break;
				case'w':
					if (t > 0 && k != nullptr)
						k->WypiszDane();
					else cout << "Nie ma kierownika";
					break;
				case'q':
					if (t > 0)
						delete k;
					break;
				case's':
					cout << "Dane kierownika do skopiowania:" << endl;
					k = new Kierownik;
					cin >> *k;
					szukany = lp.Szukaj(k->Nazwisko(), k->Imie());
					if (szukany != nullptr)
					{
						t++;
						Kierownik *k1;
						k1 = new Kierownik;
						k1 = k->KopiaObiektu();
						lp.Dodaj(*k1);
						cout << endl << "Znaleziono pracownika i dodano kopie do listy." << endl;
						delete k1;
					}
					else { cout << "Nie znaleziono pracownika" << endl; }
					//delete k;
					break;
				default:
					cout << endl << "Bledny znak" << endl;
				}
				if (z == 'q')
					break;
				getchar();
				getchar();
				system("CLS");
			}
			break;
		case 'l':
			cout << "Odczyt z pliku" << endl;
			lp.WczytajZPliku();
			break;
		case 'q':
			system("CLS");
			cout << "KONIEC PROGRAMU" << endl;
			system("pause");
			return 0;
		default:
			cout << endl << "Bledny znak" << endl;
		}
		getchar();
		getchar();
		system("CLS");
	}
	return 0;
}
