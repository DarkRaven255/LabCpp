#include "Pracownik.h"
#include <string.h>
#include <iostream>


Pracownik::Pracownik()
{
}


Pracownik::~Pracownik()
{
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	std::cout << " ";
	m_Nazwisko.Wypisz();
	std::cout << " ";
	m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
	std::cout << "Podaj imie: ";
	m_Imie.Wpisz();
	std::cout << "Podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	std::cout << "Podaj date:\n";
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}
