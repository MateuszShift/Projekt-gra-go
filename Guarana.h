#pragma once
#include <iostream>
#include <string.h>
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void rysuj() override;
	std::string getNazwa() override;
	//nadpisywanie kolizja nie ma tu sensu bo sama Guarana sie zderza sie z czyms innym tylko zwierze lub czlowiek moze wejsc na pole
	Organizm* rozmnoz(int x, int y) override;
	~Guarana(){}


};