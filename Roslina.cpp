#include <iostream>
#include "Roslina.h"
#include <string.h>


Roslina::Roslina(int x, int y, int sila, int wiekWTurach, bool czyNowy, Swiat* swiat) : Organizm(sila, 0, x,y,wiekWTurach, czyNowy,swiat){}


void Roslina::akcja() {
	wiekWTurach++;

	int szansaNaRozmnozenie;

	szansaNaRozmnozenie = rand() % 100 + 1;

	//szansa do zmiany jezeli za szybko lub za wolno
		//std::cout << this->getNazwa() << " o pozycji [" << this->getX() << "," << this->getY() << "] probuje sie rozsadzic\n";
		int* nowaPoz = znajdzPoleBezPrzeszkod();
		if (nowaPoz[0] != -1 && nowaPoz[1] != -1) {
			if (szansaNaRozmnozenie < 7) {
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


Roslina::~Roslina() {}


