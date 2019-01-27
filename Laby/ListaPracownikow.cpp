#include "ListaPracownikow.h"
#include <iostream>
#include <fstream>


ListaPracownikow::ListaPracownikow():
	m_pPoczatek(nullptr),
	m_nLiczbaPracownikow(0)
{
}


ListaPracownikow::~ListaPracownikow()
{
	delete[] m_pPoczatek;
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
	auto *toAdd = p.KopiaObiektu();

	if (m_pPoczatek == nullptr)
	{
		m_pPoczatek = toAdd;
		m_nLiczbaPracownikow++;
	}
	else
	{
		Pracownik *current = m_pPoczatek;
		Pracownik *last = nullptr;
		while (current!= nullptr)
		{
			int cmp = toAdd->Porownaj(*current);

			if (!cmp)
			{
				std::cout << "\n\nPracownik juz jest na liscie!\n\n";
				delete toAdd;
				break;
			}
			if (cmp > 0 && current->m_pNastepny == nullptr)
			{
				current->m_pNastepny = toAdd;
				m_nLiczbaPracownikow++;
				break;
			}
			if (cmp <0 && last == nullptr)
			{
				m_pPoczatek = toAdd;
				m_pPoczatek->m_pNastepny = current;
				m_nLiczbaPracownikow++;
				break;
			}
			if(cmp > 0 && toAdd->Porownaj(*current->m_pNastepny)<0)
			{
				toAdd->m_pNastepny = current->m_pNastepny;
				current->m_pNastepny = toAdd;
				m_nLiczbaPracownikow++;
				break;
			}
			last = current;
			current = current->m_pNastepny;
		}
	}
}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	if (m_nLiczbaPracownikow == 0)
	{
		std::cout << "Brak takiego pracownika!\n" << std::endl;
	}
	else
	{
		Pracownik *temp = m_pPoczatek;
		if (wzorzec.Porownaj(*temp) == 0)
		{
			m_pPoczatek = temp->m_pNastepny;
			m_nLiczbaPracownikow--;
			delete temp;
		}
		else
		{
			while (temp->m_pNastepny != nullptr)
			{
				if (!(wzorzec.Porownaj(*temp->m_pNastepny)))
				{
					Pracownik *tmp = temp->m_pNastepny->m_pNastepny;
					delete temp->m_pNastepny;
					temp->m_pNastepny = tmp;
					m_nLiczbaPracownikow--;
					break;
				}
				temp = temp->m_pNastepny;
			}
		}
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik *temp = m_pPoczatek;

	if(temp==nullptr)
	{
		std::cout << "Lista jest pusta!\n\n";
	}
	else
	{
		while (temp != nullptr)
		{
			temp->Wypisz();
			temp = temp->m_pNastepny;
		}
	}
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	Pracownik *temp = m_pPoczatek;
	Napis szNazwisko;
	Napis szImie;
	szNazwisko.Ustaw(nazwisko);
	szImie.Ustaw(imie);
	for (auto i = 0; i < m_nLiczbaPracownikow; i++)
	{
		if (szNazwisko.SprawdzNapis(temp->Nazwisko()) == 0 && szImie.SprawdzNapis(temp->Imie()) == 0)
		{
			return temp;
		}
		temp = temp->m_pNastepny;
	}
	return nullptr;
}

void ListaPracownikow::ZapiszDoPliku()
{
	std::ofstream fOut;
	fOut.open("lista.txt");

	auto *pracownik = m_pPoczatek;
	while(pracownik != nullptr)
	{
		fOut << *pracownik;
		if(pracownik->m_pNastepny!=nullptr) fOut << std::endl;
		pracownik = pracownik->m_pNastepny;
	}
	fOut.close();
}

void ListaPracownikow::WczytajZPliku()
{
	std::ifstream fIn;
	fIn.open("lista.txt");

	Pracownik pracownik;
	while(!fIn.eof())
	{
		fIn >> pracownik;
		Dodaj(pracownik);
	}
	fIn.close();
}
