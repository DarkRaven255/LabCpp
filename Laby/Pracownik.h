#pragma once
#include "Napis.h"
#include "Data.h"

class Pracownik
{
public:
	Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik &wzor);
	virtual ~Pracownik();
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

	Pracownik &operator=(const Pracownik &wzor);
	bool operator==(const Pracownik &wzor);

	friend std::ostream& operator<<(std::ostream &wy, const Pracownik &p);
	friend std::istream& operator>>(std::istream &we, Pracownik &p);

	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu() const;

private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int ID;
};

