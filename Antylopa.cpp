#include <iostream>
#include <string.h>
#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Zwierze(4,4,x,y,wiekWTurach, czyNowy, swiat){}

void Antylopa::rysuj() {
	std::cout << "Y";
}

std::string Antylopa::getNazwa() {
	return "antylopa";
}

Organizm* Antylopa::rozmnoz(int x, int y) {
	return new Antylopa(x,y,1,true, swiat);
}

void Antylopa::akcja() {
	int* nowaPozycja = new int[2];

	nowaPozycja[0] = polozenie[0];
	nowaPozycja[1] = polozenie[1];

	int kierunekRuchu;
	bool czyMoznaRuszyc;

	do {
		czyMoznaRuszyc = false;
		kierunekRuchu = rand() % 4 + 1;
		if (kierunekRuchu == 1) {
			if (nowaPozycja[1] <= 1) {
				czyMoznaRuszyc = true;
			}
			else {
				nowaPozycja[1] -= 2;
			}
		}
		else if (kierunekRuchu == 2) {
			if (nowaPozycja[1] >= swiat->getM() - 2) {
				czyMoznaRuszyc = true;
			}
			else {
				nowaPozycja[1] += 2;
			}
		}
		else if (kierunekRuchu == 3) {
			if (nowaPozycja[0] <= 1) {
				czyMoznaRuszyc = true;
			}
			else {
				nowaPozycja[0] -= 2;
			}
		}
		else if (kierunekRuchu == 4) {
			if (nowaPozycja[0] >= swiat->getN() - 2) {
				czyMoznaRuszyc = true;
			}
			else {
				nowaPozycja[0] += 2;
			}
		}
	} while (czyMoznaRuszyc);

	if (swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] != NULL) {
		//jezeli nie jest puste miejsce to kolizja
	}
	else {
		swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] = this;//zamiana miejsca
		swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL; // poprzednie miejsce staje sie puste
		polozenie[0] = nowaPozycja[0];
		polozenie[1] = nowaPozycja[1];
	}


	delete [] nowaPozycja;
}

void Antylopa::kolizja(Organizm* innyOrganizm) {
	int szansaNaUcieczke;

	szansaNaUcieczke = rand() % 2;

	if (szansaNaUcieczke == 1 && !sprawdzCzyTenSamGatunek(*innyOrganizm) && innyOrganizm->getSila() > sila) {
		std::cout << this->getNazwa() << "[" << polozenie[0] << "," << polozenie[1] << " uniknela kolizji z " << innyOrganizm->getNazwa() << " ktory stoi na pozycji [" << innyOrganizm->getX() << "," << innyOrganizm->getY() << "]\n";
		//jezeli tak to trzeba znalezc miejsce gdzie sie znajdzie po uniknieciu kolizji

		int* nowaPozycja = znajdzPoleBezPrzeszkod();
		
		swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] = this;
		swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]] = NULL;
		polozenie[0] = nowaPozycja[0];
		polozenie[1] = nowaPozycja[1];
	}
	else {
		Zwierze::kolizja(innyOrganizm);
	}
}


Antylopa::~Antylopa() {}