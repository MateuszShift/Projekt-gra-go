#include <iostream>
#include <string.h>
#include "Guarana.h"


Guarana::Guarana(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Roslina(x,y,0,wiekWTurach, czyNowy, swiat) {}

void Guarana::rysuj() {
	std::cout << "g";
}

std::string Guarana::getNazwa() {
	return "guarana";
}

Organizm* Guarana::rozmnoz(int x, int y) {
	return new Guarana(x, y, 1, true, swiat);
}

//Guarana::~Guarana(){}

