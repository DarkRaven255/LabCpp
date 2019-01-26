#pragma once
#include "Napis.h"
#include "Data.h"

class Pracownik
{
public:
	Pracownik();
	~Pracownik();
	const char* Imie() const;
	const char* Nazwisko() const;

	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(const int nowy_dzien,const int nowy_miesiac,const int nowy_rok);

	void Wypisz() const;
	void Wpisz();

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;

	Pracownik* m_pNastepny;

private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
};

