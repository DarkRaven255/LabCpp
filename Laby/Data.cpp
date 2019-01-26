#include "Data.h"
#include <iostream>


Data::Data():
	m_nDzien(1),
	m_nMiesiac(1),
	m_nRok(2000)
{
}


Data::~Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Wypisz() const
{
	std::cout << m_nDzien << "." << m_nMiesiac << "." << m_nRok;
}

void Data::Wpisz()
{
	std::cout << "Dzien: ";
	std::cin >> m_nDzien;
	std::cout << "Miesiac: ";
	std::cin >> m_nMiesiac;
	std::cout << "Rok: ";
	std::cin >> m_nRok;
	Koryguj();
}

int Data::Porownaj(const Data & wzor) const
{
	if (m_nDzien == wzor.Dzien() && m_nMiesiac == wzor.Miesiac() && m_nRok == wzor.Rok()) return 0;
	else if (m_nRok>wzor.Rok()) return 1;
	else if (m_nMiesiac > wzor.Miesiac()) return 1;
	else if (m_nDzien > wzor.Rok()) return 1;
	else return -1;
}

void Data::Koryguj()
{
	if (m_nMiesiac < 1)m_nMiesiac = 1;
	else if (m_nMiesiac > 12)m_nMiesiac = 12;

	if (m_nDzien < 1)m_nDzien = 1;

	switch (m_nMiesiac)
	{
	case 1: case 5: case 3: case 7: case 8: case 10: case 12:
		if (m_nDzien > 31) m_nDzien = 31;
		break;
	case 4: case 6: case 9: case 11:
		if (m_nDzien > 30) m_nDzien = 30;
		break;
	case 2:
		if ((m_nRok % 4 == 0) && (m_nRok % 100 != 0) && (m_nDzien > 29)) m_nDzien = 29;
		else m_nDzien = 28;
		break;
	}
}