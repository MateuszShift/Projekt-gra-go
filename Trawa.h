#pragma once
#include <iostream>
#include <string.h>
#include "Roslina.h"


class Trawa : public Roslina {
public:
	Trawa(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	Organizm* rozmnoz(int x, int y) override;
	~Trawa();

};