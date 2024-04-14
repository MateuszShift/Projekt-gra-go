#pragma once
#include <iostream>
#include "Organizm.h"
#include <string.h>
#include <string>

class Zwierze : public Organizm{
public:
	Zwierze(int sila, int inicjatywa, int x, int y, int wiekWTurach, bool czyNoweZwierze, Swiat* swiat);
	void rysuj() override = 0;
	void akcja() override;
	virtual void kolizja(Organizm* innyOrganizm);
	
	void rozmnazanie();
	bool sprawdzCzyTenSamGatunek(Organizm& organizm);
	std::string getNazwa() override = 0;

	~Zwierze();
};
