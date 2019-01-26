#include "Napis.h"
#include <string.h>
#include <iostream>


Napis::Napis()
{
}


Napis::~Napis()
{
}

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	strcpy_s(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	std::cout << m_pszNapis;
}

void Napis::Wpisz()
{
	std::cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(m_pszNapis,por_napis);
}
