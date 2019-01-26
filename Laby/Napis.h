#pragma once
class Napis
{
public:
	Napis();
	~Napis();
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;

private:
	char m_pszNapis[40];
};

