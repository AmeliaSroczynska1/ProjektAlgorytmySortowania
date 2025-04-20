#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <random>
#include <iostream>

using namespace std;

class ObslugaDanych {
public:
    template<typename T>
    static vector<T> generatorDanych(int rozmiar) {
        vector<T> dane(rozmiar);                       // Tworzenie wektora
        random_device rd;                              // Tworzenie urządzenia losowego do inicjalizacji generatora
        mt19937 gen(rd());

        if constexpr (is_integral_v<T>) {                     // Jeśli int
            uniform_int_distribution<T> rozklad(1, 100);      // Rozkład równomierny dla liczb całkowitych od 1 do 100
            for (auto& element : dane)
                element = rozklad(gen);                       // Losuje liczbę całkowitą i przypisuje do elementu
        } else {                                              // Jeśli float, double
            uniform_real_distribution<T> rozklad(0.0, 100.0); // Rozkład równomierny dla liczb rzeczywistych od 0.0 do 100.0
            for (auto& element : dane)
                element = rozklad(gen);                       // Losuje liczbę rzeczywistą i przypisuje do elementu
        }
        return dane;                                   // Zwróć wygenerowany wektor
    }

    template<typename T>
    static void wyswietlDane(const vector<T>& data) { // Metoda wyświetlająca zawartość wektora
        for (const auto& element : data)              // Iteracja po każdym elemencie wektora
            cout << element << " ";
        cout << "\n";
    }
};

#endif // DATA_HANDLER_H

