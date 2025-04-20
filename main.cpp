#include <iostream>
#include "AlgorytmySortowania/QuickSort.h"
#include "ObslugaDanych.h"

using namespace std;

int main() {
    // Generowanie danych testowych
    vector<int> dane = ObslugaDanych::generatorDanych<int>(10);

    // Wyświetlanie danych przed sortowaniem
    cout << "Dane przed sortowaniem:\n";
    ObslugaDanych::wyswietlDane(dane);

    // Sortowanie
    quickSort(dane);

    // Wyświetlanie danych po sortowaniu
    cout << "\nDane po sortowaniu:\n";
    ObslugaDanych::wyswietlDane(dane);

    return 0;
}
