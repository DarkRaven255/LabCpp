#include "Pracownik.h"
#include <string.h>
#include <iostream>

int Pracownik::ID = 0;

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok):
	m_Imie(im),
	m_Nazwisko(naz),
	m_DataUrodzenia(dzien,miesiac,rok),
	m_pNastepny(nullptr),
	m_nIDZatrudnienia(ID++)
{
}

Pracownik::Pracownik(const Pracownik& wzor):
	m_Imie(wzor.m_Imie),
	m_Nazwisko(wzor.m_Nazwisko),
	m_DataUrodzenia(wzor.m_DataUrodzenia),
	m_nIDZatrudnienia(ID++)
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

void Pracownik::DataUrodzenia(const int nowy_dzien, const int nowy_miesiac, const int nowy_rok)
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
	std::cout << std::endl;
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

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	if (SprawdzNazwisko(wzorzec.Nazwisko()) == 0)
	{
		if (SprawdzImie(wzorzec.Imie()) == 0)
		{
			if (m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 0) return 0;
			if (m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) < 0) return -1;
			return 1;
		}
		if (SprawdzImie(wzorzec.Imie()) < 0) return -1;
		return 1;
	}
	if (SprawdzNazwisko(wzorzec.Nazwisko()) < 0) return -1;
	return 1;
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if(this!=&wzor)
	{
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
	}
	return *this;
}

bool Pracownik::operator==(const Pracownik& wzor)
{
	return this->Porownaj(wzor) == 0;
}

void Pracownik::WypiszDane()
{
	std::cout << *this << std::endl;
}

Pracownik* Pracownik::KopiaObiektu()
{
	Pracownik *copy = new Pracownik(*this);
	return copy;
}

std::ostream& operator<<(std::ostream& wy, const Pracownik& p)
{
	wy << p.m_Imie;
	wy << p.m_Nazwisko;
	wy << p.m_DataUrodzenia;
	return wy;
}

std::istream& operator>>(std::istream& we, Pracownik& p)
{
	we >> p.m_Imie;
	we >> p.m_Nazwisko;
	we >> p.m_DataUrodzenia;
	return we;
}
