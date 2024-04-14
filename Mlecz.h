#pragma once
#include <iostream>
#include <string.h>
#include "Roslina.h"


class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	Organizm* rozmnoz(int x, int y) override;
	void akcja() override;
	~Mlecz();
};
