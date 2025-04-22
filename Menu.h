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
        cout << "Wybierz typ danych:\n1 - int\n2 - float\n";
        int typWyboru;
        cin >> typWyboru;

        if (typWyboru == 1) {
            pokazDlaTypu<int>("int");
        } else if (typWyboru == 2) {
            pokazDlaTypu<float>("float");
        } else {
            cout << "Nieznany typ danych!" << endl;
            return;
        }
    }

private:
    template<typename T>
    static void pokazDlaTypu(const string& typNazwa) {
        ObslugaPliku obsluga;
        vector<T> dane;

        cout << "\nWitaj w programie do sortowania dla " << typNazwa << endl;

        // Wybór rozmiaru tablicy
        int rozmiar;
        cout << "\nWprowadz rozmiar tablicy danych do posortowania: ";
        cin >> rozmiar;

        // Wybór typu tablicy
        cout << "\nWybierz typ tablicy:\n";
        cout << "1 - Losowa\n2 - Posortowana rosnaco\n";
        cout << "3 - Posortowana malejaco\n4 - Czesciowo posortowana (33%)\n";
        cout << "5 - Czesciowo posortowana (66%)\n";
        int wyborTypu;
        cin >> wyborTypu;

        ObslugaDanych::TypDanych typ;
        switch(wyborTypu) {
            case 1: typ = ObslugaDanych::LOSOWE; break;
            case 2: typ = ObslugaDanych::POSORTOWANE_ROSNACO; break;
            case 3: typ = ObslugaDanych::POSORTOWANE_MALEJACO; break;
            case 4: typ = ObslugaDanych::CZESCIOWO_POSORTOWANE1; break;
            case 5: typ = ObslugaDanych::CZESCIOWO_POSORTOWANE2; break;
            default:
                cout << "Nieznany typ, uzywam losowej!\n";
                typ = ObslugaDanych::LOSOWE;
        }

        // Wybór algorytmu sortowania
        cout << endl << "Wybierz algorytm sortowania:" << endl;
        cout << "1 - Sortowanie szybkie" << endl;
        cout << "2 - Sortowanie Shella" << endl;
        cout << "3 - Sortowanie przez wstawianie" << endl;
        cout << "4 - Sortowanie przez kopcowanie" << endl;

        int wybor;
        cin >> wybor;

        // Definicja funkcji sortującej i nazwy algorytmu
        void (*wybranyAlgorytm)(vector<T>&) = nullptr;
        string nazwaAlgorytmu;

        switch(wybor) {
            case 1: {// Wybór typu pivota dla QuickSorta
                cout << "\nWybierz strategie wyboru pivota:\n"
                     << "1 - Lewy\n2 - Prawy\n3 - Srodkowy\n4 - Losowy\n";
                int wyborPivota;
                cin >> wyborPivota;

                switch(wyborPivota) {
                    case 1: QuickSort::pivotTyp = QuickSort::LEWY; break;
                    case 2: QuickSort::pivotTyp = QuickSort::PRAWY; break;
                    case 3: QuickSort::pivotTyp = QuickSort::SRODKOWY; break;
                    case 4: QuickSort::pivotTyp = QuickSort::LOSOWY; break;
                    default:
                        cout << "Nieznany wybor, uzyje domyślnego (czyli prawego)\n";
                        QuickSort::pivotTyp = QuickSort::PRAWY;
                }

                wybranyAlgorytm = QuickSort::sortuj<T>;
                nazwaAlgorytmu = "QuickSort (" + getNazwaPivota() + ")";
                break;
            }
            case 2: {
                // Wybór sekwencji przerw dla Shella
                cout << "\nWybierz sekwencję przerw:\n1 - Klasyczna (N/2)\n2 - Ciura\n";
                int wyborPrzerw;
                cin >> wyborPrzerw;

                switch(wyborPrzerw) {
                    case 1: Shella::gapTyp = Shella::KLASYCZNA; break;
                    case 2: Shella::gapTyp = Shella::CIURA; break;
                    default:
                        cout << "Nieznany wybór, używam domyślnej (czyli klasycznej)\n";
                        Shella::gapTyp = Shella::KLASYCZNA;
                }

                wybranyAlgorytm = Shella::sortuj<T>;
                nazwaAlgorytmu = "Shella (" + getNazwaPrzerw() + ")";
                break;
            }
            case 3:
                wybranyAlgorytm = PrzezWstawianie::sortuj<T>;
                nazwaAlgorytmu = "PrzezWstawianie";
                break;
            case 4:
                wybranyAlgorytm = PrzezKopcowanie::sortuj<T>;
                nazwaAlgorytmu = "PrzezKopcowanie";
                break;
            default:
                cout << "Nieznany algorytm sortowania!" << endl;
                return;
        }

        // Główna pętla 100 iteracji
        float lacznyCzas = 0;

        for (int i = 0; i < 100; ++i) {
            // Wersja ze wczytywaniem z pliku
//            string plik;
//            cout << "Podaj nazwe pliku do wczytania: ";
//            cin >> plik;
//
//            obsluga.otworz(plik);
//            dane = obsluga.dane;

            // Generowanie nowych danych dla każdej iteracji
            dane = ObslugaDanych::generatorDanych<T>(rozmiar, typ);

            // Wyświetlanie danych przed sortowaniem
//            cout << "Dane przed sortowaniem:\n";          // Zakomentowane, bo przy duzych liczbach długo się wypisywało
//            ObslugaDanych::wyswietlDane(dane);

//            // Sprawdzanie czy tablica już przypadkiem jest posortowana
//            if (Test::testSortowanie(dane) == 0) {
//                cout << "Tablica juz jest posortowana przed sortowaniem w iteracji " << i+1 << endl;
//            }

            // Utworzenie kopii tablicy, która będzie sortowana
            vector<T> daneKopia = dane;

            // Pomiar czasu i sortowanie
            Timer timer(nazwaAlgorytmu);
            wybranyAlgorytm(daneKopia);
            timer.zatrzymaj();
            lacznyCzas += timer.pobierzCzas();

            // Wyświetlanie danych po sortowaniu
//            cout << "Dane po sortowaniu:\n";                      // Zakomentowane, bo przy duzych liczbach długo się wypisywało
//            ObslugaDanych::wyswietlDane(daneKopia);

            // Sprawdzanie poprawności sortowania
            if (Test::testSortowanie(daneKopia) > 0) {
                cout << "Blad sortowania w iteracji " << i+1 << endl;
            }
        }

        // Zapis łącznego czasu do pliku
        ObslugaPliku::zapiszCzas(nazwaAlgorytmu, lacznyCzas, rozmiar);

        cout << "\nTestowanie zakonczone. Sredni czas: " << lacznyCzas/100 << " mikrosekund"
             << " (" << lacznyCzas/100/1000 << " ms)" << endl;
        cout << "Wynik zapisano w pliku czasy_sortowania.txt" << endl;
    }

    static string getNazwaPivota() {
        switch(QuickSort::pivotTyp) {
            case QuickSort::LEWY: return "Lewy";
            case QuickSort::PRAWY: return "Prawy";
            case QuickSort::SRODKOWY: return "Środkowy";
            case QuickSort::LOSOWY: return "Losowy";
            default: return "Nieznany";
        }
    }

    static string getNazwaPrzerw() {
        switch(Shella::gapTyp) {
            case Shella::KLASYCZNA: return "Klasyczna";
            case Shella::CIURA: return "Ciura";
            default: return "Nieznana";
        }
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_MENU_H
