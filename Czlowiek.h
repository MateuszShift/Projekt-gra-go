#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
	Czlowiek(int x, int y, int wiekWTurach, Swiat* swiat);
	void rysuj() override;
	void akcja() override;
	//void kolizja(Organizm* innyOrganizm) = 0;
	std::string getNazwa() override;
	void umiejetnoscSpecjalna();
	Organizm* rozmnoz(int pX, int pY) override;
	~Czlowiek();
};