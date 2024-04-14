#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"




class Organizm {
protected:
	Swiat* swiat;
	int sila;
	int inicjatywa;
	int wiekWTurach;
	int polozenie[2]; //mozna by bylo dac na x i y ale wtedy nie mozna zwrocic polozenia na raz a tablice tak mozna tez bylo zrobic dodatkowa klase polozenie 

public:

	bool nowyOrganizm;

	Organizm(int sila, int inicjatywa, int pX, int pY, int wiekWTurach, bool nowyOrg, Swiat* swiat);

	int getSila();
	void setSila(int sila);
	int getInicjatywa();
	int getX();
	int getY();
	void setX(int x);
	void setY(int Y);
	int getWiekWTurach();
	int setWiekWTurach();
	bool getNowyOrganizm();

	virtual int* znajdzNowePole();
	int* znajdzPoleBezPrzeszkod();

	//virtual dla tych specjalnych umiejetnosci zwierzat

	virtual std::string getNazwa() = 0;
	virtual void rysuj() = 0;
	virtual void akcja() = 0;
	//virtual void kolizja(Organizm* innyOrganizm) = 0;
	virtual Organizm* rozmnoz(int pX, int pY) = 0; //dla sytuacji kiedy dwa organizmy tego samego gatunku sie zetkna
	virtual bool odbijAtak(Organizm* innyOrganizm);
	virtual ~Organizm();
};