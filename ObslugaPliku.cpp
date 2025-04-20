#include "ObslugaPliku.h"
#include <iostream>

using namespace std;

bool ObslugaPliku::otworzPlik(const string& nazwaPliku) {
    plik.open(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Błąd otwarcia pliku!" << endl;
        return false;
    }
    cout<< "Plik otwarty pomyslnie!" << endl;
    return true;
}

bool ObslugaPliku::wczytajRozmiar() {
    if (!plik.is_open()) {
        cout << "Plik nie jest otwarty!" << endl;
        return false;
    }
    if (!(plik >> rozmiar)) {
        cout << "Blad odczytu rozmiaru!" << endl;
        return false;
    }
    return true;
}

bool ObslugaPliku::wczytajWyniki() {
    if (!plik.is_open()) {
        cout << "Plik nie jest otwarty!" << endl;
        return false;
    }
    dane.resize(rozmiar);
    for (int i = 0; i < rozmiar; ++i) {
        if (!(plik >> dane[i])) {
            cout << "Blad odczytu danych!" << endl;
            return false;
        }
    }
    return true;
}

void ObslugaPliku::zamknijPlik() {
    if (plik.is_open()) {
        plik.close();
    }
}

// Nowa metoda otworz - cała logika wczytywania w jednym miejscu
void ObslugaPliku::otworz(const std::string& nazwaPliku) {
    if (!otworzPlik(nazwaPliku)) {
        return;
    }
    if (!wczytajRozmiar()) {
        zamknijPlik();
        return;
    }
    if (!wczytajWyniki()) {
        zamknijPlik();
        return;
    }
    zamknijPlik();
}
