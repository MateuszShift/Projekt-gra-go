#pragma once
#include <iostream>
#include "Zwierze.h"
#include <string.h>



class Owca : public Zwierze {
public:

	Owca(int x, int y, int wiekWTurach, bool czyNowe, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	Organizm* rozmnoz(int x, int y) override;

	~Owca();
};