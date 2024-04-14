#pragma once
#include <iostream>
#include <string.h>
#include "Organizm.h"


class Roslina : public Organizm {
public:
	Roslina(int x, int y, int sila, int wiekWTurach, bool czyNowy, Swiat* swiat);
	void akcja() override;
	//virtual void kolizja(Organizm* innyOrganizm) override; //nie potrzeba dodawac kolizji tutaj bo i tak rosliny sie nie ruszaja wiec trzeba dodac elementy w kolizji
	//jezeli zwierze wejdzie na pole ktore jest albo w otoczeniu albo na dana rosline
	~Roslina();
};