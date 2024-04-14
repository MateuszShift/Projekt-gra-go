#include <iostream>
#include "Lis.h"
#include <string.h>


Lis::Lis(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Zwierze(3,7,x,y,wiekWTurach, czyNowy, swiat) {}


void Lis::rysuj() {
	std::cout << "l";
}

std::string Lis::getNazwa() {
	return "lis";
}

Organizm* Lis::rozmnoz(int x, int y) {
	return new Lis(x, y, 1, true, swiat);
}

void Lis::akcja() {
	int* nowaPozycja = znajdzNowePole();

	if (swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] == NULL) { //jezeli jest puste to porusza sie normalnie
		swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] = this;
		swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
		polozenie[0] = nowaPozycja[0];
		polozenie[1] = nowaPozycja[1];

	}
	else {
		if (swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]]->getSila() > getSila()) {
			std::cout << this->getNazwa() << "o pozycji [" << polozenie[0] << "," << polozenie[1] << "] uniknal kolizji z  " << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]]->getNazwa() << " o pozycji [" << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]]->getX() << "," << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]]->getY() << "]\n";
		}
		else {
			kolizja(swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]]);
		}
	}
	wiekWTurach++;
}

Lis::~Lis() {}