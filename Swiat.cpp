#include "Swiat.h"
#include <string>
#include "Organizm.h"
#include "Czlowiek.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "BarszczSosnowskiego.h"

using namespace std;

Swiat::Swiat(int N, int M) : N(N), M(M) {
    
    tablicaOrganizmow = new Organizm * *[N]; //tablica organizmow 
    for (int x = 0; x < N; x++) {
        tablicaOrganizmow[x] = new Organizm * [M];
    }

    //przypisanie aby byla pusta

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            tablicaOrganizmow[x][y] = NULL;
        }
    }

    kolejkaOrganizmow = new elementKolejki(N * M); //stworzenie kolejki nowej

    dodajOrganizmyDoPlanszy();

    statusSymulacji = true;
}

void Swiat::dodajOrganizmyDoPlanszy() {
    //dodawanie zwierzat do planszy
    ustawRandomowo(new Czlowiek(-1, -1, 5, this));
    ustawRandomowo(new Wilk(-1, -1, 1, true, this));
    ustawRandomowo(new Wilk(-1, -1, 1, true, this));
    ustawRandomowo(new Owca(-1, -1, 1, true, this));
    ustawRandomowo(new Owca(-1, -1, 1, true, this));
    ustawRandomowo(new Lis(-1, -1, 1, true, this));
    ustawRandomowo(new Lis(-1, -1, 1, true, this));
    ustawRandomowo(new Zolw(-1, -1, 1, true, this));
    ustawRandomowo(new Zolw(-1, -1, 1, true, this));
    ustawRandomowo(new Antylopa(-1, -1, 1, true, this));
    ustawRandomowo(new Antylopa(-1, -1, 1, true, this));
    //dodawanie poszczegolnych roslin do planszy
    ustawRandomowo(new Trawa(-1, -1, 1, true, this));
    ustawRandomowo(new Mlecz(-1, -1, 1, true, this));
    ustawRandomowo(new Guarana(-1, -1, 1, true, this));
    ustawRandomowo(new Jagody(-1, -1, 1, true, this));
    ustawRandomowo(new BarszczSosnowskiego(-1, -1, 1, true, this));
}

void Swiat::rysujSwiat() {
    for (int i = 0; i < N+2; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;
    for (int x = 0; x < M; x++) {
        std::cout << "%";
        for (int y = 0; y < N; y++) {
            if (tablicaOrganizmow[y][x] == NULL) {
                std::cout << " ";
            }
            else {
                tablicaOrganizmow[y][x]->rysuj();
            }
        }
        std::cout << "%";
        std::cout << std::endl;
    }
    for (int i = 0; i < N + 2; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;
    std::cout << "Legenda: specjalna umiejetnosc - wpisz p , zapisz - wpisz spacja, W - wilk, Y - antylopa, x - barszcz sosnowskiego, & - czlowiek, g - guarana\n";
    std::cout << "j - jagody, l - lis, o - mlecz, * - owca, : - trawa, @ - zolw\n";
    std::cout << "Licznik umiejetnosci " << licznikUmiejetnosciCzlowieka << std::endl;
    std::cout << "Tura gry " << turaSymulacji << std::endl;
}

void Swiat::wykonajTure() {
    
    kolejka* tempElement = kolejkaOrganizmow->kolejkaOrg->next;


    while (tempElement != NULL) {
        // Nowo narodzone organizmy siê nie ruszaj¹
        if (tempElement->elementOrganizm->nowyOrganizm == true) {
            tempElement->elementOrganizm->nowyOrganizm = false;
        }
        else {
            tempElement->elementOrganizm->akcja();
        }
        tempElement = tempElement->next;
    }

    if (licznikUmiejetnosciCzlowieka > 0) {
        licznikUmiejetnosciCzlowieka--;
    }

    //bez tego getchara nie mozna uzyskac mozliwosci zapisu albo wyjscia z programu

    getchar();
    turaSymulacji++;
}



int Swiat::getN() {
    return N;
}

int Swiat::getM() {
    return M;
}

int Swiat::getTuraSymulacji() {
    return turaSymulacji;
}
void Swiat::setTuraSymulacji(int turaSym) {
    this->turaSymulacji = turaSym;
}


int Swiat::getLicznikUmiejetnosciCzlowieka() {
    return licznikUmiejetnosciCzlowieka;
}

void Swiat::setLicznikUmiejetnosciCzlowieka(int czlowiekLicznik) {
    this->licznikUmiejetnosciCzlowieka = czlowiekLicznik;
}

bool Swiat::getStatusSymulacji() {
    return statusSymulacji;
}

void Swiat::setStatusSymulacji() {
    if (statusSymulacji == true) {
        statusSymulacji = false;
    }
    else {
        statusSymulacji = true;
    }
}

void Swiat::ustawRandomowo(Organizm* org) {
    int pX, pY;

    pX = rand() % getN();
    pY = rand() % getM();


    //ustawianie nowego organizmu na pozycji randomowej i przypisanie go do tablicy z organizmami na tej pozycji oraz do kolejki wywolania akcji
    //testowane na jednym ifie ale dziala lepiej i dodaje wiecej na wielu

    if (tablicaOrganizmow[pX][pY] == NULL) {
        org->setX(pX);
        org->setY(pY);
        tablicaOrganizmow[pX][pY] = org;
        kolejkaOrganizmow->dodajDoKolejki(org);
    }
    else if (tablicaOrganizmow[pX][pY + 1] && pY+1 < M) {
        org->setX(pX);
        org->setY(pY+1);
        tablicaOrganizmow[pX][pY+1] = org;
        kolejkaOrganizmow->dodajDoKolejki(org);
    }
    else if (tablicaOrganizmow[pX][pY - 1] && pY - 1 > 0) {
        org->setX(pX);
        org->setY(pY-1);
        tablicaOrganizmow[pX][pY-1] = org;
        kolejkaOrganizmow->dodajDoKolejki(org);
    }
    else if (tablicaOrganizmow[pX + 1][pY] == NULL && pX+1 < N) {
        org->setX(pX+1);
        org->setY(pY);
        tablicaOrganizmow[pX+1][pY] = org;
        kolejkaOrganizmow->dodajDoKolejki(org);
    }
    else if (tablicaOrganizmow[pX - 1][pY] == NULL && pX-1 > 0) {
        org->setX(pX-1);
        org->setY(pY);
        tablicaOrganizmow[pX-1][pY] = org;
        kolejkaOrganizmow->dodajDoKolejki(org);
    }
    else {
        delete org;
    }
}

void Swiat::ustawNaPozycji(Organizm* org, int x, int y) {
    org->setX(x);
    org->setY(y);
    tablicaOrganizmow[x][y] = org;
    kolejkaOrganizmow->dodajDoKolejki(org);
};


//void Swiat::zapiszSwiat()

void Swiat::zapiszSymulacje() {
    
    std::ofstream plikZapisu;
    
    plikZapisu.open("zapissymulacji.txt", std::ios::out);

    if (plikZapisu) {
        
        plikZapisu << N << " " << M << " " << turaSymulacji << " " << licznikUmiejetnosciCzlowieka << '\n';
        
        kolejka* elementKolejki = kolejkaOrganizmow->kolejkaOrg->next;
        
        while (elementKolejki != NULL) {

            plikZapisu << elementKolejki->elementOrganizm->getNazwa() << " " << elementKolejki->elementOrganizm->getX() << " " << elementKolejki->elementOrganizm->getY() << " " << elementKolejki->elementOrganizm->getSila() << " " << elementKolejki->elementOrganizm->getWiekWTurach() << " " << elementKolejki->elementOrganizm->getNowyOrganizm() << '\n';
        
            elementKolejki = elementKolejki->next;
        }
    }
    else {
        
        plikZapisu.close();
        
        return;
    }
    
}

Swiat::Swiat(int N, int M, std::ifstream& odczytajPlik) : N(N), M(M) {
    tablicaOrganizmow = new Organizm * *[N]; //tablica organizmow 
    for (int x = 0; x < N; x++) {
        tablicaOrganizmow[x] = new Organizm * [M];
    }

    //przypisanie aby byla pusta

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            tablicaOrganizmow[x][y] = NULL;
        }
    }

    kolejkaOrganizmow = new elementKolejki(N * M);

    Organizm* organizm;
    std::string zapis;

    int primX, primY, primWiekWTurach, primCzyNowy, primSila;

    while (odczytajPlik >> zapis) {
        odczytajPlik >> primX >> primY >> primSila >> primWiekWTurach >> primCzyNowy;
        odczytajOrganizmy(zapis, primWiekWTurach, primCzyNowy, primX, primY, this);
    }

    statusSymulacji = true;
}

void Swiat::odczytajOrganizmy(std::string zapis, int wiekPrimWTurach, bool primCzyNowy, int primX, int primY, Swiat* swiat) {
    if (zapis == "czlowiek") {
        ustawNaPozycji(new Czlowiek (-1,-1,wiekPrimWTurach, swiat), primX, primY);
    }
    else if (zapis == "zolw") {
        ustawNaPozycji(new Zolw(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "owca") {
        ustawNaPozycji(new Owca(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "wilk") {
        ustawNaPozycji(new Wilk(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "antylopa") {
        ustawNaPozycji(new Antylopa(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "lis") {
        ustawNaPozycji(new Lis(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "barszcz") {
        ustawNaPozycji(new BarszczSosnowskiego(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "trawa") {
        ustawNaPozycji(new Trawa(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "mlecz") {
        ustawNaPozycji(new Mlecz(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "guarana") {
        ustawNaPozycji(new Guarana(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
    else if (zapis == "jagody") {
        ustawNaPozycji(new Jagody(-1, -1, wiekPrimWTurach, primCzyNowy, swiat), primX, primY);
    }
}


Swiat::~Swiat() {
    //std::cout << "Koniec rozgrywki";
}