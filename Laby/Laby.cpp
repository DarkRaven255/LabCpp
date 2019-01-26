#include <iostream>
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Napis.h"

int main()
{
	char z{'k'};

	Pracownik toMod;
	Pracownik const *isFound;
	ListaPracownikow list;
	Napis imie, nazwisko;

	while (z!='w')
	{
		std::cout << "1 - Dodaj pracownika\n";
		std::cout << "2 - Usun pracownika\n";
		std::cout << "3 - Wyswietl liste pracownikow\n";
		std::cout << "4 - Wyszukaj pracownika\n";
		std::cout << "w - Wyjdz\n\n";

		fflush(stdin);
		std::cin >> z;
		fflush(stdin);

		switch(z)
		{
		case '1':
			system("cls");
			toMod.Wpisz();
			list.Dodaj(toMod);
			break;
		case '2':
			system("cls");
			toMod.Wpisz();
			list.Usun(toMod);
			break;
		case '3':
			system("cls");
			list.WypiszPracownikow();
			break;
		case '4':
			system("cls");
			std::cout << "Podaj imie: ";
			imie.Wpisz();
			std::cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();

			isFound = list.Szukaj(nazwisko.Zwroc(), imie.Zwroc());

			if(isFound!=nullptr)
			{
				isFound->Wypisz();
			}
			else std::cout << "Brak takiego pracownika!\n";
			break;
		case 'w':
			break;
		default:
			system("cls");
			std::cout << "\nZly wybor\n";
		}
	}

	system("PAUSE");
	return 0;
}
