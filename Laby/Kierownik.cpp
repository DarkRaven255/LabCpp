#include "Kierownik.h"

Kierownik::Kierownik(const char* nd, int lp):
	m_NazwaDzialu(nd),
	m_nLiczbaPracownikow(lp)
{
}

Kierownik::Kierownik(const Kierownik& wzor)
{
	//m_Imie = wzor.m_Imie;
	//m_Nazwisko = wzor.m_Nazwisko;
	//m_DataUrodzenia = wzor.m_DataUrodzenia;
	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}


Kierownik::~Kierownik()
{
}

Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	if (this != &wzor)
	{
		//m_Imie = wzor.m_Imie;
		//m_Nazwisko = wzor.m_Nazwisko;
		//m_DataUrodzenia = wzor.m_DataUrodzenia;
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	return this->Porownaj(wzor) == 0;
}

Pracownik* Kierownik::KopiaObiektu()
{
	Kierownik *copy = new Kierownik(*this);
	return copy;
}

void Kierownik::WypiszDane()
{
	std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& s)
{
	wy << s.m_NazwaDzialu;
	wy << s.m_nLiczbaPracownikow;
	return wy;
}

std::istream& operator>>(std::istream& we, Kierownik& s)
{
	we >> s.m_NazwaDzialu;
	we >> s.m_nLiczbaPracownikow;
	return we;
}
