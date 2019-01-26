#include <iostream>
#include "Pracownik.h"
#include "ListaPracownikow.h"

int main()
{
	char z{'k'};

	while (z != 'w')
	{
		Pracownik toMod;
		Pracownik const *isFound;
		ListaPracownikow list;
		Napis imie, nazwisko;

		std::cout << "1 - Dodaj pracownika\n";
		std::cout << "2 - Usun pracownika\n";
		std::cout << "3 - Wyswietl liste pracownikow\n";
		std::cout << "4 - Wyszukaj pracownika\n";
		std::cout << "w - Wyjdz\n";

		fflush(stdin);
		std::cin >> z;

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
		default: ;
		}
	}
}
