#pragma once
#include <iostream>
#include <string.h>
#include "Zwierze.h"

class Wilk : public Zwierze {

public:
	Wilk(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	Organizm* rozmnoz(int x, int y) override;

	~Wilk();
};
