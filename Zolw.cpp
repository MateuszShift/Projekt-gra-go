#include <iostream>
#include <string.h>
#include "Zolw.h"

Zolw::Zolw(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Zwierze(2,1, x, y,wiekWTurach, czyNowy, swiat){}


void Zolw::rysuj() {
	std::cout << "@";
}

std::string Zolw::getNazwa() {
	return "zolw";
}

Organizm* Zolw::rozmnoz(int x, int y) {
	return new Zolw(x, y, 1, true, swiat);
}

void Zolw::akcja() {
	//W 75% przypadków nie zmienia swojego polozenia
	wiekWTurach++;

	int zmianaPolozenia = rand() % 100 + 1;

	if (zmianaPolozenia > 75) {
		int* nowaPoz = znajdzNowePole();

		if (swiat->tablicaOrganizmow[nowaPoz[0]][nowaPoz[1]] != NULL) {
			kolizja(swiat->tablicaOrganizmow[nowaPoz[0]][nowaPoz[1]]);
		}
		else {
			swiat->tablicaOrganizmow[nowaPoz[0]][nowaPoz[1]] = this;//zamiana miejsca
			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL; // poprzednie miejsce staje sie puste
			polozenie[0] = nowaPoz[0];
			polozenie[1] = nowaPoz[1];
		}
		delete nowaPoz;
	}
}

bool Zolw::odbijAtak(Organizm* innyOrganizm) {
	return innyOrganizm->getSila() < 5;
}

Zolw::~Zolw(){}