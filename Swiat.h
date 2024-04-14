#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <typeinfo>
#include "Kolejka.h"

class Organizm;


class Swiat {

private:
	int N, M;
	int turaSymulacji = 1;
	int licznikUmiejetnosciCzlowieka;
	bool statusSymulacji;

public:
	Swiat(int N, int M);
	void dodajOrganizmyDoPlanszy();
	Organizm*** tablicaOrganizmow;
	elementKolejki* kolejkaOrganizmow;
	void rysujSwiat();
	void wykonajTure();
	int getN();
	int getM();
	int getTuraSymulacji();
	void setTuraSymulacji(int turaSym);
	int getLicznikUmiejetnosciCzlowieka();
	void setLicznikUmiejetnosciCzlowieka(int czlowiekLicznik);
	bool getStatusSymulacji();
	void setStatusSymulacji();
	void ustawRandomowo(Organizm* organizmRand); //na poczatek symulacji

	void zapiszSymulacje();
	//Swiat wczytajSymulacje();
	Swiat(int N, int M, std::ifstream& odczytajPlik);
	void odczytajOrganizmy(std::string zapis, int primWiekWTurach, bool primCzyNowy, int primN, int primM, Swiat* swiat);
	void ustawNaPozycji(Organizm* organizmExact, int x, int y);//na wczytywanie
	~Swiat();

};