#include <iostream>
#include "AlgorytmySortowania/QuickSort.h"
#include "AlgorytmySortowania/PrzezWstawianie.h"
#include "ObslugaDanych.h"
#include "AlgorytmySortowania/PrzezKopcowanie.h"
#include "AlgorytmySortowania/Shella.h"

using namespace std;

int main() {
    // Generowanie danych testowych
    vector<int> dane = ObslugaDanych::generatorDanych<int>(10);

    // Wyświetlanie danych przed sortowaniem
    cout << "Dane przed sortowaniem:\n";
    ObslugaDanych::wyswietlDane(dane);

    // Wyświetlanie danych po sortowaniu
    cout << "\nDane po sortowaniu:\n";
    ObslugaDanych::wyswietlDane(dane);

    return 0;
}
