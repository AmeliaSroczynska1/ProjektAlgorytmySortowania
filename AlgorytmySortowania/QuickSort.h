#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int podzial(vector<T>& dane, int lewo, int prawo) {
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

// Implementacja quickSort
template<typename T>
void quickSort(vector<T>& data, int lewo, int prawo) {
    if (lewo < prawo) {
        int pivotIndeks = podzial(data, lewo, prawo);
        quickSort(data, lewo, pivotIndeks - 1);
        quickSort(data, pivotIndeks + 1, prawo);
    }
}

// Wrapper
template<typename T>
void quickSort(vector<T>& dane) {               // Upraszcza wywołanie quickSort
    if (!dane.empty())
        quickSort(dane, 0, dane.size() - 1);    // Wywołuje rekurencyjnie quickSort z odpowiednimi parametrami początkowymi
}

#endif // SORTING_ALGORITHMS_H
