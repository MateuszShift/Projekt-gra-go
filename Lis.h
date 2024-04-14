#pragma once
#include <iostream>
#include <string.h>
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	void akcja() override;
	Organizm* rozmnoz(int x, int y) override;
	~Lis();


};