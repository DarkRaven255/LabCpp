#pragma once
#include "Pracownik.h"

class ListaPracownikow
{
public:
	ListaPracownikow();
	~ListaPracownikow();

	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
};

