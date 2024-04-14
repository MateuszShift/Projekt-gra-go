#include "Czlowiek.h"
#include <iostream>
//#include <conio.h>

#define GORA 119 
#define LEWO 97
#define PRAWO 100
#define DOL 115
#define UMIEJETNOSCSPEC 'p'

void Czlowiek::rysuj() {
	std::cout << "&";
}
Czlowiek::Czlowiek(int x, int y, int wiekWTurach, Swiat* swiat) : Zwierze(5,4,x,y,wiekWTurach, false, swiat){}

void Czlowiek::akcja() {
	int ruchCzlowieka;
	wiekWTurach++;

	int pozycja[2];
	pozycja[0] = polozenie[0];
	pozycja[1] = polozenie[1];

	std::cout << "wykonaj ruch czlowieka (WASD)";

	if (swiat->getTuraSymulacji() == 1) {
		ruchCzlowieka = getchar();
	}
	ruchCzlowieka = getchar();
	if (ruchCzlowieka == GORA) {
		pozycja[1]--;
	}
	else if (ruchCzlowieka == DOL) {
		pozycja[1]++;
	}
	else if (ruchCzlowieka == PRAWO) {
		pozycja[0]++;
	}
	else if (ruchCzlowieka == LEWO) {
		pozycja[0]--;
	}
	else if (ruchCzlowieka == 32) {
		swiat->zapiszSymulacje();;
		std::cout << "Zapisano symulacje\n";
	}
	else if (ruchCzlowieka == 33) {
		swiat->setStatusSymulacji();
		std::cout << "Zakonczono symulacje\n";
		return;
	}
	else if (ruchCzlowieka == UMIEJETNOSCSPEC) {
		umiejetnoscSpecjalna();
	}

	if (pozycja[0] < 0 || pozycja[1] < 0 || pozycja[0] >= swiat->getN() || pozycja[1] >= swiat->getM()) {
		std::cout << "Tura przepadla, nie mozna wychodzic poza obszar symulacji\n";
		return;
	}


	if (swiat->tablicaOrganizmow[pozycja[0]][pozycja[1]] == NULL) { //zmiana polozenia organizmu
		swiat->tablicaOrganizmow[pozycja[0]][pozycja[1]] = this;
		swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
		polozenie[0] = pozycja[0];
		polozenie[1] = pozycja[1];
	}
	else {
		kolizja(swiat->tablicaOrganizmow[pozycja[0]][pozycja[1]]);
	}

}

std::string Czlowiek::getNazwa() {
	return "czlowiek";
}

//5%5 = 0 czyli niesmiertelnosc

void Czlowiek::umiejetnoscSpecjalna() {
	//jezeli licznik jest od 10 do 5 to jest niesmiertelny, jezeli jest od 5 do 1 to znaczy cooldown kiedy mozna go uzyc
	//int silaDotychczasowa = this->getSila();
	if (swiat->getLicznikUmiejetnosciCzlowieka() == 0) {
		std::cout << "Aktywowano niesmiertelnosc czlowieka\n";
		swiat->setLicznikUmiejetnosciCzlowieka(11);
	}
	else if(swiat->getLicznikUmiejetnosciCzlowieka() > 5){
		std::cout << "Czlowiek jest juz niesmiertelny!!!\n";
	}
	else {
		std::cout << "Odczekaj jeszcze " << swiat->getLicznikUmiejetnosciCzlowieka() << " aby moc uzyc specjalnej umiejetnosci\n";
		//this->setSila(silaDotychczasowa);
	}
}

Organizm* Czlowiek::rozmnoz(int pX, int pY) {
	return new Czlowiek(pX, pY, 1, swiat);
}



Czlowiek::~Czlowiek() {
	swiat->setStatusSymulacji();
}
