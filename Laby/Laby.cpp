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
	Data manager;


	Napis imiek, nazwiskok, nazwaDzialu;
	int liczbaPracownikow, d, m, r;
	Data data;

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
				isFound->Wypisz();
			}
			else std::cout << "Brak takiego pracownika!\n";
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


	//Pracownik *worker;
	//ListaPracownikow list;
	//const Pracownik *toFind;
	//char z;
	//int t{};
	//Kierownik *manager=nullptr;

	//for (;;)
	//{
	//	cout << "MENU" << endl << "----------------------" << endl << "d - dodaj pracownika" << endl << "u - usun pracownika" << endl;
	//	cout << "w - wyswietl liste pracownikow" << endl << "s - szukaj pracownika" << endl;
	//	cout << "l - wczytaj z pliku" << endl << "z - zapisz do pliku" << endl;
	//	//cout << "c - skopiuj pracownika" << endl;
	//	cout << "k - kierownik" << endl;
	//	cout << "q - wyjscie" << endl << "Wybor: ";
	//	fflush(stdin);
	//	cin >> z;

	//	switch (z)
	//	{
	//	case 'd':
	//		cout << "Dane pracownika do dodania" << endl;
	//		worker = new Pracownik;
	//		cin >> *worker;
	//		list.Dodaj(*worker);
	//		delete worker;
	//		break;
	//	case 'u':
	//		cout << "Dane pracownika do usuniecia" << endl;
	//		worker = new Pracownik;
	//		cin >> *worker;
	//		list.Usun(*worker);
	//		delete worker;
	//		break;
	//	case 'w':
	//		cout << "Lista pracownikow: " << endl;
	//		list.WypiszPracownikow();
	//		break;
	//	case 's':
	//		cout << "Dane pracownika do wyszukania:" << endl;
	//		worker = new Pracownik;
	//		cin >> *worker;
	//		toFind = list.Szukaj(worker->Nazwisko(), worker->Imie());
	//		if (toFind != nullptr) { cout << "Znaleziono pracownika." << endl; }
	//		else { cout << "Nie znaleziono pracownika" << endl; }
	//		delete worker;
	//		break;
	//	//case 'c':
	//	//	cout << "Dane pracownika do skopiowania:" << endl;
	//	//	p = new Pracownik;
	//	//	cin >> *p;
	//	//	szukany = lp.Szukaj(p->Nazwisko(), p->Imie());
	//	//	if (szukany != nullptr)
	//	//	{
	//	//		Pracownik *p1;
	//	//		p1 = new Pracownik;
	//	//		p1 = p->KopiaObiektu();
	//	//		lp.Dodaj(*p1);
	//	//		cout << endl << "Znaleziono pracownika i dodano kopie do listy." << endl;
	//	//		delete p1;
	//	//	}
	//	//	else { cout << "Nie znaleziono pracownika" << endl; }
	//	//	delete p;
	//	//	break;
	//	case 'z':
	//		cout << "Zapisano do pliku" << endl;
	//		list.ZapiszDoPliku();
	//		break;
	//	case 'k':
	//		system("CLS");
	//		t = 0;
	//		for (;;)
	//		{
	//			cout << "d - dodaj kierownika" << endl;
	//			cout << "w - wyswietl informacje o kierowniku" << endl;
	//			//cout << "s - skopiuj kierownika" << endl;
	//			cout << "q - wyjsc" << endl;
	//			cout << "Wybor: ";
	//			fflush(stdin);
	//			cin >> z;
	//			switch (z)
	//			{
	//			case'd':
	//				manager = new Kierownik;
	//				cin >> *manager;
	//				list.Dodaj(*manager);
	//				t++;
	//				break;
	//			case'w':
	//				if (t > 0 && manager != nullptr)
	//					manager->WypiszDane();
	//				else cout << "Nie ma kierownika";
	//				break;
	//			case'q':
	//				if (t > 0)
	//				break;
	//			//case's':
	//			//	cout << "Dane kierownika do skopiowania:" << endl;
	//			//	k = new Kierownik;
	//			//	cin >> *k;
	//			//	szukany = lp.Szukaj(k->Nazwisko(), k->Imie());
	//			//	if (szukany != nullptr)
	//			//	{
	//			//		t++;
	//			//		Kierownik *k1;
	//			//		k1 = new Kierownik;
	//			//		k1 = k->KopiaObiektu();
	//			//		lp.Dodaj(*k1);
	//			//		cout << endl << "Znaleziono pracownika i dodano kopie do listy." << endl;
	//			//		delete k1;
	//			//	}
	//			//	else { cout << "Nie znaleziono pracownika" << endl; }
	//			//	break;
	//			default:
	//				cout << endl << "Bledny znak" << endl;
	//			}
	//			if (z == 'q')
	//				break;
	//			getchar();
	//			getchar();
	//			system("CLS");
	//		}
	//		break;
	//	case 'l':
	//		cout << "Odczyt z pliku" << endl;
	//		list.WczytajZPliku();
	//		break;
	//	case 'q':
	//		system("CLS");
	//		cout << "KONIEC PROGRAMU" << endl;
	//		return 0;
	//	default:
	//		cout << endl << "Bledny znak" << endl;
	//	}
	//	getchar();
	//	getchar();
	//	system("CLS");
	//}
}
