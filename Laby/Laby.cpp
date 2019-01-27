#include <iostream>
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Napis.h"
#include "Kierownik.h"

int main()
{
	char z{'k'};

	Pracownik toMod;
	Kierownik toModK;
	Pracownik const *isFound;
	ListaPracownikow listWorkers;
	ListaPracownikow listManagers;
	Napis imie, nazwisko;

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
			listManagers.Dodaj(toMod);
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
	}
	return 0;
}
