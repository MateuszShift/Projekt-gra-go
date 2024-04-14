#include <iostream>
#include <string.h>
#include "Mlecz.h"


Mlecz::Mlecz(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Roslina(x,y,0,wiekWTurach, czyNowy, swiat){}

void Mlecz::rysuj() {
	std::cout << "o";
}

std::string Mlecz::getNazwa() {
	return "mlecz";
}

Organizm* Mlecz::rozmnoz(int x, int y) {
	return new Mlecz(x, y, 1, true, swiat);
}

void Mlecz::akcja() {
	wiekWTurach++;
	for (int i = 0; i < 3; i++) { 
		//sprawdz trzy razy czy mozna sie rozmnozyc podczas jednej tury
		int czyRozmnozy = rand() % 100 + 1;
		if (czyRozmnozy > 50) {
			Roslina::akcja(); 
			wiekWTurach--;
		}
	}
}

Mlecz::~Mlecz(){}
