#include <iostream>
#include "Wilk.h"


Wilk::Wilk(int x, int y, int wiekWTurach, bool czyNowy, Swiat* swiat) : Zwierze(9,5,x,y,wiekWTurach, czyNowy, swiat){

}

void Wilk::rysuj() {
	std::cout << "w";
}

std::string Wilk::getNazwa() {
	return "wilk";
}

Organizm* Wilk::rozmnoz(int x, int y) {
	return new Wilk(x,y,1,true,swiat);
}

Wilk::~Wilk() {}
