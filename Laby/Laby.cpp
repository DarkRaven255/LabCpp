#include <iostream>
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Kierownik.h"

using namespace std;

int main()
{
	char z{ 'k' };
	Pracownik toMod;
	Pracownik const *isFound;
	Kierownik toModK;
	ListaPracownikow listWorkers;
	ListaPracownikow listManagers;
	Napis imie, nazwisko;

	while (z != 'w')
	{
		std::cout << "PRACOWNICY:\n";
		std::cout << "1 - Dodaj pracownika\n";
		std::cout << "2 - Usun pracownika\n";
		std::cout << "3 - Wyswietl liste pracownikow\n";
		std::cout << "\nKIEROWNICY:\n";
		std::cout << "4 - Dodaj kierownika\n";
		std::cout << "5 - Usun kierownika\n";
		std::cout << "6 - Wyswietl liste kierownikow\n";
		std::cout << "\nWSZYSCY:\n";
		std::cout << "7 - Wyswietl liste wszystkich pracownikow\n";
		std::cout << "8 - Wyszukaj pracownika\n";
		std::cout << "9 - Zapisz do pliku\n";
		std::cout << "0 - Wczytaj z pliku\n";
		std::cout << "w - Wyjdz\n\n";
		std::cout << "Akcja: ";
		fflush(stdin);
		std::cin >> z;
		fflush(stdin);
		switch (z)
		{
		case '1':
			system("cls");
			cin >> toMod;
			listWorkers.Dodaj(toMod);
			break;
		case '2':
			system("cls");
			cin >> toMod;
			listWorkers.Usun(toMod);
			break;
		case '3':
			system("cls");
			std::cout << "Pracownicy:\n";
			listWorkers.WypiszPracownikow();
			std::cout << "\n\n";
			break;
		case '4':
			system("cls");
			cin >> toModK;
			listManagers.Dodaj(toModK);
			break;
		case '5':
			system("cls");
			cin >> toModK;
			listManagers.Usun(toMod);
			break;
		case '6':
			system("cls");
			std::cout << "Kierownicy:\n";
			listManagers.WypiszPracownikow();
			cout << "\n";
			break;
		case '7':
			system("cls");
			std::cout << "Pracownicy:\n";
			listWorkers.WypiszPracownikow();
			std::cout << "\nKierownicy:\n";
			listManagers.WypiszPracownikow();
			cout << "\n";
			break;
		case '8':
			system("cls");
			std::cout << "Podaj imie: ";
			imie.Wpisz();
			std::cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();
			isFound = listWorkers.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			if (isFound != nullptr)
			{
				cout << "Znaleziono Pracownika!\n";
				isFound->Wypisz();
			}
			else std::cout << "Brak takiego pracownika!\n";
			isFound = listManagers.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			if (isFound != nullptr)
			{
				cout << "Znaleziono Managera!\n";
				isFound->Wypisz();
			}
			else std::cout << "Brak takiego Managera!\n";
			break;
		case '9':
			listWorkers.ZapiszDoPliku();
			listManagers.ZapiszDoPlikuM();
			system("cls");
			std::cout << "Zapisano!\n";
			break;
		case '0':
			listWorkers.WczytajZPliku();
			listManagers.WczytajZPlikuM();
			system("cls");
			std::cout << "Wczytano!\n";
			break;
		default:
			system("cls");
			std::cout << "\nZly wybor!\n";
		case 'w':
			break;
		}
	}
}
