#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <random>
#include <iostream>

using namespace std;

class DataHandler {
public:
    template<typename T>
    static vector<T> generateRandomData(int size) {
        vector<T> data(size);                       // Tworzenie wektora o podanym rozmiarze
        random_device rd;                           // Tworzenie urządzenia losowego do inicjalizacji generatora
        mt19937 gen(rd());                      //  Mersenne Twister

        if constexpr (is_integral_v<T>) {           // Jeśli typ T jest int
            uniform_int_distribution<T> dist(1, 100); // Rozkład równomierny dla liczb całkowitych od 1 do 100
            for (auto& element : data)                // Dla każdego elementu w wektorze
                element = dist(gen);                  // Wylosuj liczbę całkowitą i przypisz do elementu
        } else {                                      // Jeśli typ T jest float, double
            uniform_real_distribution<T> dist(0.0, 100.0); // Rozkład równomierny dla liczb rzeczywistych od 0.0 do 100.0
            for (auto& element : data)                     // Dla każdego elementu w wektorze
                element = dist(gen);                       // Wylosuj liczbę rzeczywistą i przypisz do elementu
        }
        return data;                                // Zwróć wygenerowany wektor
    }

    template<typename T>
    static void printData(const vector<T>& data) { // Statyczna metoda wyświetlająca zawartość wektora na ekranie
        for (const auto& element : data)           // Dla każdego elementu w wektorze
            cout << element << " ";
        cout << "\n";
    }
};

#endif // DATA_HANDLER_H

