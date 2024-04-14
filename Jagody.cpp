#include <iostream>
#include <string.h>
#include "Jagody.h"


Jagody::Jagody(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Roslina(x,y,99,wiekWTurach, czyNowy, swiat) {}

void Jagody::rysuj() {
	std::cout << "j";
}

std::string Jagody::getNazwa() {
	return "jagody";
}

Organizm* Jagody::rozmnoz(int x, int y) {
	return new Jagody(x, y, 1, true, swiat);
}

void Jagody::akcja() {
	wiekWTurach++;
	int szansaNaRozsianie = rand() % 100 + 1;

	int* nowaPoz = znajdzPoleBezPrzeszkod();
	if (nowaPoz[0] != -1 && nowaPoz[1] != -1) {
		if (szansaNaRozsianie < 3) {
			rozmnoz(nowaPoz[0], nowaPoz[1]);
			std::cout << "Udalo sie rozsadzic " << this->getNazwa() << std::endl;
		}
		else {
			delete nowaPoz;
			return;
		}
	}
	else {
		delete nowaPoz;
		//std::cout << "Nie udalo sie rozsadzic " << this->getNazwa() << std::endl;
		return;
	}


}

Jagody::~Jagody() {}



