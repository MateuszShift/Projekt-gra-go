#pragma once
#include <iostream>
#include <string.h>
#include "Roslina.h"

class Jagody : public Roslina {
public:
	Jagody(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	//sprawdzic czy jezeli dotknie jagod to umiera zwierze
	void akcja() override;
	Organizm* rozmnoz(int x, int y) override;
	~Jagody();

};