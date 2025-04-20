#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm>

using namespace std;

class QuickSort {
public:
    template<typename T>
    // Implementacja podziału - uzywam tego w implementacji sortuj
    static int podzial(vector<T> &dane, int lewo, int prawo) {
        T pivot = dane[prawo];
        int i = lewo - 1;
        for (int j = lewo; j < prawo; ++j) {
            if (dane[j] <= pivot) {
                ++i;
                swap(dane[i], dane[j]);
            }
        }
        swap(dane[i + 1], dane[prawo]);
        return i + 1;
    }

    // Implementacja sortuj
    template<typename T>
    static void sortuj(vector<T> &data, int lewo, int prawo) {
        if (lewo < prawo) {
            int pivotIndeks = podzial(data, lewo, prawo);
            sortuj(data, lewo, pivotIndeks - 1);
            sortuj(data, pivotIndeks + 1, prawo);
        }
    }

    // Wrapper
    template<typename T>
    static void sortuj(vector<T> &dane) {               // Upraszcza wywołanie sortuj
        if (!dane.empty())
            sortuj(dane, 0, dane.size() - 1);    // Wywołuje rekurencyjnie sortuj z odpowiednimi parametrami początkowymi
    }
};

#endif // SORTING_ALGORITHMS_H
