#include "Kierownik.h"

Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* nd, int lp) :
	Pracownik(im, naz, dzien, miesiac, rok),
	m_NazwaDzialu(nd),
	m_nLiczbaPracownikow(lp)
{
}

Kierownik::Kierownik(const Kierownik& wzor):
	Pracownik(wzor),
	m_NazwaDzialu(wzor.m_NazwaDzialu),
	m_nLiczbaPracownikow(wzor.m_nLiczbaPracownikow)
{
}


Kierownik::~Kierownik()
{
}

Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	if (this != &wzor)
	{
		static_cast<Pracownik&>(*this) = wzor;
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	return this->Porownaj(wzor) == 0 && m_NazwaDzialu == wzor.m_NazwaDzialu && m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow;
}

Pracownik* Kierownik::KopiaObiektu() const
{
	return new Kierownik(*this);
}

void Kierownik::WypiszDane()
{
	std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& s)
{
	const Pracownik &p = s;
	wy << p << std::endl;
	wy << s.m_NazwaDzialu;
	wy << s.m_nLiczbaPracownikow << std::endl;
	return wy;
}

std::istream& operator>>(std::istream& we, Kierownik& s)
{
	Pracownik &p = s;
	we >> p;
	we >> s.m_NazwaDzialu;
	we >> s.m_nLiczbaPracownikow;
	return we;
}
