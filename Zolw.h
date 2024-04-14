#pragma once
#include <iostream>
#include <string.h>
#include "Zwierze.h"

class Zolw : public Zwierze {

public:

	Zolw(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	Organizm* rozmnoz(int x, int y) override;
	void akcja() override;
	bool odbijAtak(Organizm* innyOrganizm) override;
	~Zolw();


};

