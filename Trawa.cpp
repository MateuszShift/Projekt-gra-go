#include <iostream>
#include <string.h>
#include "Trawa.h"

Trawa::Trawa(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Roslina(x,y,0,wiekWTurach, czyNowy, swiat) {}


void Trawa::rysuj() {
	std::cout << ":"; 
}

std::string Trawa::getNazwa() {
	return "trawa";
}

Organizm* Trawa::rozmnoz(int x, int y) {
	return new Trawa(x,y,1,true,swiat);
}

Trawa::~Trawa(){}