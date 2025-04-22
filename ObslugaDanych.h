#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

class ObslugaDanych {
public:
    enum TypDanych {
        LOSOWE,
        POSORTOWANE_ROSNACO,
        POSORTOWANE_MALEJACO,
        CZESCIOWO_POSORTOWANE1,
        CZESCIOWO_POSORTOWANE2
    };

    template<typename T>
    static vector<T> generatorDanych(int rozmiar, TypDanych typ = LOSOWE) {
        vector<T> dane(rozmiar);
        random_device rd;
        mt19937 gen(rd());

        // Generuj losowe dane
        if constexpr (is_integral_v<T>) {
            uniform_int_distribution<T> rozklad(1, 10000);
            for (auto& element : dane) element = rozklad(gen);
        } else {
            uniform_real_distribution<T> rozklad(0.0, 10000.0);
            for (auto& element : dane) element = rozklad(gen);
        }

        // Dostosuj dane według wybranego typu
        switch(typ) {
            case POSORTOWANE_ROSNACO:
                sort(dane.begin(), dane.end());
                break;
            case POSORTOWANE_MALEJACO:
                sort(dane.begin(), dane.end(), greater<T>());
                break;
            case CZESCIOWO_POSORTOWANE1: {
                int posortowaneDo = max(1, static_cast<int>(rozmiar * 0.33));
                sort(dane.begin(), dane.begin() + posortowaneDo);
                break;
            }
            case CZESCIOWO_POSORTOWANE2: {
                int posortowaneDo = max(1, static_cast<int>(rozmiar * 0.66));
                sort(dane.begin(), dane.begin() + posortowaneDo);
                break;
            }
            case LOSOWE:
            default:
                break;
        }

        return dane;
    }

    template<typename T>
    static void wyswietlDane(const vector<T>& data) {
        for (const auto& element : data) cout << element << " ";
        cout << "\n";
    }
};

#endif // DATA_HANDLER_H
