#pragma once
class Data
{
public:
	Data();
	~Data();

	void Ustaw(int d, int m, int r);

	int Dzien() const;
	int Miesiac() const;
	int Rok() const;

	void Wypisz() const;
	void Wpisz();
	
	int Porownaj(const Data &wzor) const;

private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

	void Koryguj();
};

