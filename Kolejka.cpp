
#include <iostream>
#include "Kolejka.h"
#include "Organizm.h"


elementKolejki::elementKolejki(int rozmiarMaks) : maksymalnyRozmiar(rozmiarMaks) {
    kolejkaOrg = new kolejka;

    kolejkaOrg->elementOrganizm = NULL;
    kolejkaOrg->next = NULL;
};

int elementKolejki::getMaksymalnyRozmiar() {
    return maksymalnyRozmiar;
};

int elementKolejki::getRozmiar() {
    return rozmiar;
};

void elementKolejki::dodajDoKolejki(Organizm* organizmDoDodania) {
    if (rozmiar >= maksymalnyRozmiar) {
        return;
    }
    kolejka* nowyOrganizm = new kolejka;
    nowyOrganizm->elementOrganizm = organizmDoDodania;
    nowyOrganizm->next = NULL;

    kolejka* tempOrganizm = kolejkaOrg;

    while (tempOrganizm->next != NULL) {
        if (organizmDoDodania->getInicjatywa() > tempOrganizm->next->elementOrganizm->getInicjatywa()) {
            break;

        }
        else if (organizmDoDodania->getInicjatywa() == tempOrganizm->next->elementOrganizm->getInicjatywa()) {
            if (organizmDoDodania->getWiekWTurach() >= tempOrganizm->next->elementOrganizm->getWiekWTurach()) {
                break;
            }
        }
        tempOrganizm = tempOrganizm->next;
    }
    nowyOrganizm->next = tempOrganizm->next;
    tempOrganizm->next = nowyOrganizm;
    rozmiar++;
};

void elementKolejki::usunZKolejki(Organizm* organizmDoUsuniecia) {
    kolejka* tempOrg = kolejkaOrg;
    for (int i = 0; i < rozmiar; i++) {
        if (tempOrg->next->elementOrganizm == organizmDoUsuniecia) {
            break;
        }
        if (i == rozmiar - 1) {
            return;
        }
        tempOrg = tempOrg->next;
    }

    tempOrg->next = tempOrg->next->next;
    delete organizmDoUsuniecia;
    rozmiar--;
};

elementKolejki::~elementKolejki() {}
