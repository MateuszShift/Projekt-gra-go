#include <iostream>
#include <string.h>
#include "BarszczSosnowskiego.h"



BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Roslina(x,y,10,wiekWTurach, czyNowy, swiat){}


void BarszczSosnowskiego::rysuj() {
	std::cout << "x";
}

std::string BarszczSosnowskiego::getNazwa() {
	return "barszcz";
}

void BarszczSosnowskiego::akcja() {

	wiekWTurach++;

	int nowaPozycja[2];

	nowaPozycja[0] = polozenie[0];
	nowaPozycja[1] = polozenie[1];

    if (nowaPozycja[1] != 0 && swiat->getLicznikUmiejetnosciCzlowieka()<5 && swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1] != NULL) { //sprawdzenie czy jest organizm 2 pola nizej niz barszcz
        if (swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "czlowiek" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "owca" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "lis" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "antylopa" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "wilk" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() == "zolw") {
            std::cout << this->getNazwa() << " eliminuje " << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getNazwa() << " na pozycji [" << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getX() << "," << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]->getY() << "]\n";
            
            swiat->kolejkaOrganizmow->usunZKolejki(swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] - 1]);
            swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1]-1] = NULL;
        }
    }

    if (nowaPozycja[1] != swiat->getM() - 1  && swiat->getLicznikUmiejetnosciCzlowieka() < 5 && swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1] != NULL) { //sprawdzenie czy jest organizm 2 pola wyzej niz barszcz
        if (swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "czlowiek" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "owca" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "lis" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "antylopa" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "wilk" || swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() == "zolw") {
            std::cout << this->getNazwa() << " eliminuje " << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getNazwa() << " na pozycji [" << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getX() << "," << swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]->getY() << "]\n";

            swiat->kolejkaOrganizmow->usunZKolejki(swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1]);
            swiat->tablicaOrganizmow[nowaPozycja[0]][nowaPozycja[1] + 1] = NULL;
        }
    }

    if (nowaPozycja[0] != swiat->getN() - 1 && swiat->getLicznikUmiejetnosciCzlowieka() < 5 && swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]] != NULL) { //sprawdzenie czy jest organizm 2 pola w prawo niz barszcz
        if (swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "czlowiek" || swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "owca" || swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "lis" || swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "antylopa" || swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "wilk" || swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() == "zolw") {
            std::cout << this->getNazwa() << " eliminuje " << swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getNazwa() << " na pozycji [" << swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getX() << "," << swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]->getY() << "]\n";

            swiat->kolejkaOrganizmow->usunZKolejki(swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]]);
            swiat->tablicaOrganizmow[nowaPozycja[0] + 1][nowaPozycja[1]] = NULL;
        }
    }

    if (nowaPozycja[0] != 0 && swiat->getLicznikUmiejetnosciCzlowieka() < 5 && swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]] != NULL) { //sprawdzenie czy jest organizm 2 pola w lewo niz barszcz
        if (swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "czlowiek" || swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "owca" || swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "lis" || swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "antylopa" || swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "wilk" || swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() == "zolw") {
            std::cout << this->getNazwa() << " eliminuje " << swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getNazwa() << " na pozycji [" << swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getX() << "," << swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]->getY() << "]\n";

            swiat->kolejkaOrganizmow->usunZKolejki(swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]]);
            swiat->tablicaOrganizmow[nowaPozycja[0] - 1][nowaPozycja[1]] = NULL;
        }
    }


    int szansaNaRozmnozenie;

    szansaNaRozmnozenie = rand() % 100 + 1;

    //szansa do zmiany jezeli za szybko lub za wolno
        //std::cout << this->getNazwa() << " o pozycji [" << this->getX() << "," << this->getY() << "] probuje sie rozsadzic\n";
    int* nowaPoz = znajdzPoleBezPrzeszkod();
    if (nowaPoz[0] != -1 && nowaPoz[1] != -1) {
        if (szansaNaRozmnozenie < 3) {
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


Organizm* BarszczSosnowskiego::rozmnoz(int x, int y) {
    return new BarszczSosnowskiego(x,y,1,true,swiat);
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}