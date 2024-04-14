#include <iostream>
#include "Zwierze.h"
#include <string>

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, int wiekWTurach, bool czyNoweZwierze, Swiat* swiat) : Organizm(sila, inicjatywa, x , y, wiekWTurach, czyNoweZwierze, swiat) {}

void Zwierze::akcja() {
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

void Zwierze::kolizja(Organizm* innyOrganizm) {
	if (sprawdzCzyTenSamGatunek(*innyOrganizm) == true) {
		if (this->getNazwa() == "czlowiek" && innyOrganizm->getNazwa() == "czlowiek") { //bez tego zapisu wyskakiwal dziwny blad o zderzaniu sie czlowieka sam ze soba
			return;
		}
		else {
			int szansaNaRozmnozenie = rand() % 100 + 1;
			if (szansaNaRozmnozenie > 50) {
				std::cout << "Nastapilo zderzenie dwoch takich samych gatunkowo zwierzat " << this->getNazwa() << " [" << polozenie[0] << "," << polozenie[1] << "] z " << innyOrganizm->getNazwa() << "[" << innyOrganizm->getX() << "," << innyOrganizm->getY() << "]\n";
				rozmnazanie();
				return;
			}
			else {
				std::cout << "Nastapilo zderzenie dwoch takich samych gatunkowo zwierzat " << this->getNazwa() << " [" << polozenie[0] << ", " << polozenie[1] << "] z " << innyOrganizm->getNazwa() << "[" << innyOrganizm->getX() << ", " << innyOrganizm->getY() << "] ale NIE udalo sie im rozmnozyc\n";
				return;
			}
		}
	}
	else {
		//jezeli nie ten sam gatunek to 
		if (this->odbijAtak(innyOrganizm)) {
			std::cout << this->getNazwa() << " [" << polozenie[0] << "," << polozenie[1] << "]" << " odbil atak " << innyOrganizm->getNazwa() << " [" << innyOrganizm->getX() << "," << innyOrganizm->getY() << "]\n";
		}

		if (innyOrganizm->getNazwa() == "guarana") {
			sila += 3;
			std::cout << this->getNazwa() << " zjadl guarane na pozycji [" << innyOrganizm->getX() << "," << innyOrganizm->getY() << "]\n";
			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
			polozenie[0] = innyOrganizm->getX();
			polozenie[1] = innyOrganizm->getY();
			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = this;

			swiat->kolejkaOrganizmow->usunZKolejki(innyOrganizm);
			return;

		}

		std::cout << "Walka " << this->getNazwa() << " [" << polozenie[0] << "," << polozenie[1] << "], " <<  innyOrganizm->getNazwa() << " [" << innyOrganizm->getX() << "," << innyOrganizm->getY() << "]\n";
		//if(this->getNazwa() != "czlowiek" && innyOrganizm->getNazwa() == "czlowiek" && )
		if (this->getNazwa() == "czlowiek" &&  swiat->getLicznikUmiejetnosciCzlowieka() > 5) {
			if (innyOrganizm->getNazwa() == "barszcz" || innyOrganizm->getNazwa() == "jagody") {
				std::cout << "Czlowiek jest niesmiertelny i " << innyOrganizm->getNazwa() << " nie jest w stanie go pokonac\n";
				//this->znajdzNowePole();
			}
			else {
				std::cout << this->getNazwa() << " jest teraz niesmiertelny i pokonuje " << innyOrganizm->getNazwa() << std::endl;
				swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
				polozenie[0] = innyOrganizm->getX();
				polozenie[1] = innyOrganizm->getY();

				swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = this;

				swiat->kolejkaOrganizmow->usunZKolejki(innyOrganizm);
			}
		}
		else if (sila >= innyOrganizm->getSila()) {
			std::cout << "Wygral " << this->getNazwa() << "\n";

			//trzeba usunac przegranego //zastepujemy go wygranym na jego miejscu

			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
			polozenie[0] = innyOrganizm->getX();
			polozenie[1] = innyOrganizm->getY();

			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = this;

			swiat->kolejkaOrganizmow->usunZKolejki(innyOrganizm);

		}
		else {
			std::cout << "Wygral " << innyOrganizm->getNazwa() << "\n";
			//wygral inny wiec usuwamy dany organizm

			swiat->tablicaOrganizmow[polozenie[0]][polozenie[1]] = NULL;
			swiat->kolejkaOrganizmow->usunZKolejki(this);
		}
	}
}

void Zwierze::rozmnazanie() {
	int* pozycjaDlaNowego = znajdzPoleBezPrzeszkod(); //potrzeba jest pola ktore nie jest zajete
	//sprawdzenie czy jest jeszcze miejsce
	if (pozycjaDlaNowego[0] == -1 && pozycjaDlaNowego[1] == -1) {
		return; //brak miejsca
	}
	//if (swiat->tablicaOrganizmow[pozycjaDlaNowego[0]][pozycjaDlaNowego[1]]->getWiekWTurach() == 1) {
		//return;
	//}
	rozmnoz(pozycjaDlaNowego[0], pozycjaDlaNowego[1]);
	delete pozycjaDlaNowego;
}

bool Zwierze::sprawdzCzyTenSamGatunek(Organizm& organizm) {
	return this->getNazwa() == organizm.getNazwa();
}

Zwierze::~Zwierze(){}