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

using namespace std;

class Menu {
public:
    static void pokaz() {
        ObslugaPliku obsluga;
        vector<int> dane;

        cout << "Witaj w programie do sortowania!" << endl;
        int wybor;
        cout << "Chcesz wygenerowac losowa tablice do posortowania czy wczytac ja z pliku tekstowego?" << endl;
        cout << "1 - Wygenerowac losowa tablice" << endl;
        cout << "2 - Wczytac z pliku tekstowego" << endl;
        cin >> wybor;
        switch(wybor){
            case 1: {
                // Wybór rozmiaru tablicy
                int rozmiar;
                cout<< "\nWprowadz rozmiar tablicy danych do posortowania: ";
                cin>>rozmiar;

                // Generowanie danych testowych
                dane = ObslugaDanych::generatorDanych<int>(rozmiar);
                break;
            }
            case 2: {
                string plik;
                cout << "Podaj nazwe pliku do wczytania: ";
                cin >> plik;

                obsluga.otworz(plik);
                dane = obsluga.dane; // Przechowuje wczytane dane
                break;
            }
            default:
                cout << "Nieznany wybor, musisz wcisnac 1 lub 2" << endl;
                return;
        }

        // Wyświetlanie danych przed sortowaniem
        cout << "\nDane przed sortowaniem:\n";
        ObslugaDanych::wyswietlDane(dane);

        // Testowanie czy tablica już jest posortowana
        cout << "\nCzy chcesz przetestowac czy tablica jest juz posortowana? (1 - tak, 0 - nie): ";
        int test;
        cin >> test;
        if (test == 1) {
            int czyPosortowana = Test::testSortowanie(dane);
            if (czyPosortowana > 0) {
                cout << "Tablica nie jest posortowana" << endl;
            }
            else {
                cout << "Tablica jest posortowana" << endl;
                return;
            }
        }

        // Kopiowanie danych
        vector<int> daneKopia = dane;

        // Wybór algorytmu sortowania
        cout << endl << "Wybierz algorytm sortowania:" << endl;
        cout << "1 - Sortowanie szybkie" << endl;
        cout << "2 - Sortowanie Shella" << endl;
        cout << "3 - Sortowanie przez wstawianie" << endl;
        cout << "4 - Sortowanie przez kopcowanie" << endl;

        cin >> wybor;

        switch(wybor){
            case 1:
                QuickSort::sortuj(daneKopia);
                break;
            case 2:
                Shella::sortuj(daneKopia);
                break;
            case 3:
                PrzezWstawianie::sortuj(daneKopia);
                break;
            case 4:
                PrzezKopcowanie::sortuj(daneKopia);
                break;
            default:
                cout << "Nieznany algorytm sortowania!" << endl;
                return;
        }

        // Testowanie poprawności sortowania
        cout << "\nCzy chcesz teraz przetestowac czy tablica jest juz posortowana? (1 - tak, 0 - nie): ";
        cin >> test;
        if (test == 1) {
            int czyPosortowana = Test::testSortowanie(daneKopia);
            if (czyPosortowana > 0) {
                cout << "Tablica nie jest posortowana" << endl;
            }
            else {
                cout << "Tablica jest posortowana" << endl;
            }
        }

        // Wyświetlanie danych po sortowaniu
        cout << "\nDane po sortowaniu:\n";
        ObslugaDanych::wyswietlDane(daneKopia);
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_MENU_H
