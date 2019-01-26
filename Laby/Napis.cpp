#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"
#include <string.h>
#include <iostream>

Napis::Napis(const char* nap):
	m_nDl(static_cast<int>(strlen(nap)))
{
	m_pszNapis = new char[m_nDl + 1];
	strncpy(m_pszNapis, nap, m_nDl);
	m_pszNapis[m_nDl] = '\0';
}

Napis::Napis(const Napis& wzor)
{
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl + 1];
	strncpy(m_pszNapis, wzor.Zwroc(), m_nDl);
	m_pszNapis[m_nDl] = '\0';
}

Napis::~Napis()
{
	delete[] m_pszNapis;
}

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	delete[] m_pszNapis;
	m_nDl = static_cast<int>(strlen(nowy_napis));
	m_pszNapis = new char[m_nDl + 1];
	strncpy(m_pszNapis, nowy_napis, m_nDl);
	m_pszNapis[m_nDl] = '\0';
}

void Napis::Wypisz() const
{
	std::cout << m_pszNapis;
}

void Napis::Wpisz()
{
	char buff[1024];
	std::cin >> buff;
	Ustaw(buff);
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(m_pszNapis,por_napis);
}

Napis& Napis::operator=(const Napis& wzor)
{
	if (this != &wzor)
	{
		Ustaw(wzor.m_pszNapis);
	}
	return *this;
}

bool Napis::operator==(const Napis& wzor) const
{
	return m_nDl == wzor.m_nDl && this->SprawdzNapis(wzor.m_pszNapis) == 0;
}

std::ostream& operator<<(std::ostream& wy, const Napis& p)
{
	return wy << p.m_pszNapis << std::endl;
}

std::istream& operator>>(std::istream& we, Napis& p)
{
	char buff[1024];
	we >> buff;
	p.Ustaw(buff);
	return we;
}
