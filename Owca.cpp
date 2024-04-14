#include <iostream>
#include "Owca.h"
#include <string.h>


Owca::Owca(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Zwierze(4,4, x,y, wiekWTurach,czyNowy, swiat) {

}

void Owca::rysuj() {
	std::cout << "*";
}

std::string Owca::getNazwa() {
	return "owca";
}

Organizm* Owca::rozmnoz(int x, int y) {
	return new Owca(x, y, 1, true, swiat);
}

Owca::~Owca(){}