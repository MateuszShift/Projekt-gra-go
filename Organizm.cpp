#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, int pX, int pY, int wiekWTurach, bool nowyOrg, Swiat* swiat) : sila(sila), inicjatywa(inicjatywa), wiekWTurach(wiekWTurach), nowyOrganizm(nowyOrg), swiat(swiat) {
	this->polozenie[0] = pX;
	this->polozenie[1] = pY;

	if (pY == -1 && pX == -1) {
		return;
	}
	else {
		swiat->tablicaOrganizmow[pX][pY] = this;
		swiat->kolejkaOrganizmow->dodajDoKolejki(this);
	}
}

int Organizm::getSila() {
	return sila;
}
void Organizm::setSila(int sila) { //potrzebne aby moc zmienic czlowieka w niesmiertelnego
	this->sila = sila;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}

int Organizm::getX() {
	return polozenie[0];
}

void Organizm::setX(int x) {
	this->polozenie[0] = x;
}

int Organizm::getY() {
	return polozenie[1];
}

void Organizm::setY(int y) {
	this->polozenie[1] = y;
}

int Organizm::getWiekWTurach() {
	return wiekWTurach;
}

bool Organizm::getNowyOrganizm() {
	return nowyOrganizm;
}

int *Organizm::znajdzNowePole() {
	int* position = new int[2];

	position[0] = polozenie[0];
	position[1] = polozenie[1];

	int kierunek;
	bool czyMozna;
	do {//jeden ruch w dowolnym kierunku losowym jezeli przy bandzie
		czyMozna = false;
		kierunek = rand() % 4;
		if (kierunek == 0) {
			if (position[1] == 0) {
				czyMozna = true;
			}
			else {
				position[1]--;
			}
		}
		else if (kierunek == 1) {
			if (position[0] == swiat->getN() - 1) {
				czyMozna = true;
			}
			else {
				position[0]++;
			}
		}
		else if (kierunek == 2) {
			if (position[1] == swiat->getM() - 1) {
				czyMozna = true;
			}
			else {
				position[1]++;
			}
		}
		else if (kierunek == 3) {
			if (position[0] == 0) {
				czyMozna = true;
			}
			else {
				position[0]--;
			}
		}
	} while (czyMozna == true);
	return position;
}

int *Organizm::znajdzPoleBezPrzeszkod() {
	int* position = new int[2];

	position[0] = polozenie[0];
	position[1] = polozenie[1];

	if (position[1] != 0 && (swiat->tablicaOrganizmow[position[0]][position[1]-1] == NULL)) { //znaleziono pole wyzej
		position[1]--;
		return position;
	}
	else if (position[0] != 0 && (swiat->tablicaOrganizmow[position[0]-1][position[1]] == NULL)) { //znaleziono pole na lewo
		position[0]--;
		return position;
	}
	else if ((position[1] != swiat->getM() - 1) && (swiat->tablicaOrganizmow[position[0]][position[1]+1] == NULL)) { //znaleziono pole nizej
		position[1]++;
		return position;
	}
	else if ((position[0] != swiat->getN() - 1) && (swiat->tablicaOrganizmow[position[0] + 1][position[1]] == NULL)) { //znaleziono pole na prawo
		position[0]++;
		return position;
	}

	position[0] = -1;
	position[1] = -1;
	return position;
}

bool Organizm::odbijAtak(Organizm* innyOrganizm) {
	return false;
}

Organizm::~Organizm() {};

