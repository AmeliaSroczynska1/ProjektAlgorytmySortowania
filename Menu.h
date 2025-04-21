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
                cout<< "Wprowadz rozmiar tablicy danych do posortowania: ";
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
        cout << "Dane przed sortowaniem:\n";
        ObslugaDanych::wyswietlDane(dane);

        // Testowanie czy tablica już jest posortowana
        cout << "Czy chcesz przetestowac czy tablica jest juz posortowana? (1 - tak, 0 - nie): ";
        int test;
        cin >> test;
        if (test == 1) {
            Test::testSortowanie(dane);
        }

        // Wybór algorytmu sortowania
        cout << endl << "Wybierz algorytm sortowania:" << endl;
        cout << "1 - Sortowanie szybkie" << endl;
        cout << "2 - Sortowanie Shella" << endl;
        cout << "3 - Sortowanie przez wstawianie" << endl;
        cout << "4 - Sortowanie przez kopcowanie" << endl;

        cin >> wybor;

        switch(wybor){
            case 1:
                QuickSort::sortuj(dane);
                break;
            case 2:
                Shella::sortuj(dane);
                break;
            case 3:
                PrzezWstawianie::sortuj(dane);
                break;
            case 4:
                PrzezKopcowanie::sortuj(dane);
                break;
            default:
                cout << "Nieznany algorytm sortowania!" << endl;
                return;
        }

        // Testowanie poprawności sortowania
        cout << "Czy chcesz teraz przetestowac czy tablica jest juz posortowana? (1 - tak, 0 - nie): ";
        cin >> test;
        if (test == 1) {
            Test::testSortowanie(dane);
        }

        // Wyświetlanie danych po sortowaniu
        cout << "\nDane po sortowaniu:\n";
        ObslugaDanych::wyswietlDane(dane);
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_MENU_H
