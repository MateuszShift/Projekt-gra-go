#include <iostream>
#include "Swiat.h"
#include <conio.h>

using namespace std;

void pokazMenu() {
    cout << "Symulacja Mateusz Michalski 193355 grupa 1 2023\n";
    cout << "Klawisze do poruszania sie czlowiekiem: w - gora s - dol a - lewo d - prawo\n";
    cout << "Rozpocznij gre wpisujac 1, wczytaj gre plikajac 2\n";
}

int main() {
    srand(time(NULL));

    pokazMenu();

    int N, M, input, inputP;
    cin >> input;
    Swiat* swiat = NULL;
    switch (input) {
    case 1: {
        cout << "Wprowadz rozmiar planszy: \n";
        cout << "szerokosc: ";
        cin >> N;
        cout << "wysokosc: ";
        cin >> M;
        swiat = new Swiat(N, M);
        while (swiat->getStatusSymulacji() == true) {
            system("cls");
            swiat->rysujSwiat();
            swiat->wykonajTure();
            cout << "jezeli chcesz przejsc do kolejnej tury nacisnij enter";
            //wyswietlanie informacji o zwierzetach po czlowieku i przejscie do kolejnej tury
            inputP = getchar();
        }

        break;
    }
    case 2: {
        std::ifstream zapisanaSymulacja;
        zapisanaSymulacja.open("zapissymulacji.txt", std::ios::in);

        //poza odczytem zwierzat trzeba takze odczytac informacje o samej grze i specjalnej umiejetnosci z 1 linii odczytanego pliku
        int primIloscTur, primUmiejetnoscSpecjalna;

        //odczyt podstawowych informacji
        zapisanaSymulacja >> N >> M >> primIloscTur >> primUmiejetnoscSpecjalna;
       
        //tworzenie swiata o danych wymiarach
        Swiat zapisanySwiat(N, M, zapisanaSymulacja);

        zapisanySwiat.setTuraSymulacji(primIloscTur);            
        zapisanySwiat.setLicznikUmiejetnosciCzlowieka(primUmiejetnoscSpecjalna);               
        
        while (zapisanySwiat.getStatusSymulacji()) { //postepowanie tak samo jak w przypadku normalnej gry
            system("cls");
            zapisanySwiat.rysujSwiat();
            zapisanySwiat.wykonajTure();
            cout << "jezeli chcesz przejsc do kolejnej tury nacisnij enter\n";
            inputP = getchar();
        }

        break;
    }
    case 3: {
        break;
    }
    }

    return 0;
}