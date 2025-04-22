#ifndef PROJEKTALGORYTMYSORTOWANIA_MENU_H
#define PROJEKTALGORYTMYSORTOWANIA_MENU_H

#include <iostream>
#include <vector>
#include <fstream>
#include "ObslugaDanych.h"
#include "AlgorytmySortowania/PrzezKopcowanie.h"
#include "AlgorytmySortowania/PrzezWstawianie.h"
#include "AlgorytmySortowania/Shella.h"
#include "AlgorytmySortowania/QuickSort.h"
#include "ObslugaPliku.h"
#include "Test.h"
#include "Timer.h"

using namespace std;

class Menu {
public:
    static void pokaz() {
        ObslugaPliku obsluga;
        vector<int> dane;

        cout << "Witaj w programie do sortowania!" << endl;

        // Wersja z wczytywaniem pliku
        /*
        string plik;
        cout << "Podaj nazwe pliku do wczytania: ";
        cin >> plik;
        obsluga.otworz(plik);
        dane = obsluga.dane;
        */

        // Wybór rozmiaru tablicy
        int rozmiar;
        cout << "\nWprowadz rozmiar tablicy danych do posortowania: ";
        cin >> rozmiar;

        // Wybór algorytmu sortowania
        cout << endl << "Wybierz algorytm sortowania:" << endl;
        cout << "1 - Sortowanie szybkie" << endl;
        cout << "2 - Sortowanie Shella" << endl;
        cout << "3 - Sortowanie przez wstawianie" << endl;
        cout << "4 - Sortowanie przez kopcowanie" << endl;

        int wybor;
        cin >> wybor;

        // Definicja funkcji sortującej i nazwy algorytmu
        void (*wybranyAlgorytm)(vector<int>&) = nullptr; // Wskaźnik do funkcji
        string nazwaAlgorytmu;

        switch(wybor) {
            case 1:
                wybranyAlgorytm = QuickSort::sortuj;
                nazwaAlgorytmu = "QuickSort";
                break;
            case 2:
                wybranyAlgorytm = Shella::sortuj;
                nazwaAlgorytmu = "Shella";
                break;
            case 3:
                wybranyAlgorytm = PrzezWstawianie::sortuj;
                nazwaAlgorytmu = "PrzezWstawianie";
                break;
            case 4:
                wybranyAlgorytm = PrzezKopcowanie::sortuj;
                nazwaAlgorytmu = "PrzezKopcowanie";
                break;
            default:
                cout << "Nieznany algorytm sortowania!" << endl;
                return;
        }

        // Główna pętla 100 iteracji
        long long lacznyCzas = 0; // Zmienna na łączny czas

        for (int i = 0; i < 100; ++i) {
            // Generowanie nowych danych dla każdej iteracji
            dane = ObslugaDanych::generatorDanych<int>(rozmiar);
            vector<int> daneKopia = dane;

            // Pomiar czasu i sortowanie
            Timer timer(nazwaAlgorytmu);
            wybranyAlgorytm(daneKopia);
            timer.zatrzymaj(); // Oblicz czas
            lacznyCzas += timer.pobierzCzas(); // Dodaj do sumy

            // Sprawdzanie poprawności sortowania
            if (Test::testSortowanie(daneKopia) > 0) {
                cout << "Blad sortowania w iteracji " << i+1 << endl;
            }
        }

        // Zapis łącznego czasu do pliku
        ObslugaPliku::zapiszCzas(nazwaAlgorytmu, lacznyCzas, rozmiar);

        cout << "\nTestowanie zakonczone. Sredni czas: " << lacznyCzas/100 << " mikrosekund" << ", czyli " <<
        lacznyCzas/100/1000 << " ms" << endl;
        cout << "Wynik zapisano w pliku czasy_sortowania.txt" << endl;
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_MENU_H
