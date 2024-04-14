#pragma once
#include <iostream>
#include <string.h>
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	void akcja() override;
	void kolizja(Organizm* innyOrganizm) override;

	Organizm* rozmnoz(int x, int y) override;


	~Antylopa();
};
