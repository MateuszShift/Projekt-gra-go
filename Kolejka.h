
#pragma once
#include <iostream>

class Organizm;

struct kolejka {
	Organizm* elementOrganizm;
	kolejka* next;
};

class elementKolejki {
private:
	int maksymalnyRozmiar;
	int rozmiar = 0;
public:
	elementKolejki(int rozmiarMaks);
	kolejka* kolejkaOrg;
	int getMaksymalnyRozmiar();
	int getRozmiar();
	void dodajDoKolejki(Organizm* organizmDoDodania);
	void usunZKolejki(Organizm* organizmDoUsuniecia);
	~elementKolejki();
};
