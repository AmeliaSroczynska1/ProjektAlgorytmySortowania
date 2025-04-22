#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class QuickSort {
public:
    enum PivotType { LEWY, PRAWY, SRODKOWY, LOSOWY };
    static PivotType pivotTyp;

    template<typename T>
    static void wybierzPivot(vector<T>& dane, int lewo, int prawo) {
        switch(pivotTyp) {
            case LEWY:
                break; // już na właściwym miejscu
            case PRAWY:
                swap(dane[lewo], dane[prawo]);
                break;
            case SRODKOWY: {
                int srodek = lewo + (prawo - lewo) / 2;
                swap(dane[srodek], dane[prawo]);
                break;
            }
            case LOSOWY: {
                static mt19937 gen(random_device{}());
                uniform_int_distribution<int> dist(lewo, prawo);
                int losowy = dist(gen);
                swap(dane[losowy], dane[prawo]);
                break;
            }
        }
    }

    template<typename T>
    static int podzial(vector<T>& dane, int lewo, int prawo) {
        wybierzPivot(dane, lewo, prawo);
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

    template<typename T>
    static void sortuj(vector<T>& data, int lewo, int prawo) {
        if (lewo < prawo) {
            int pivotIndeks = podzial(data, lewo, prawo);
            sortuj(data, lewo, pivotIndeks - 1);
            sortuj(data, pivotIndeks + 1, prawo);
        }
    }

    template<typename T>
    static void sortuj(vector<T>& dane) {
        if (!dane.empty())
            sortuj(dane, 0, dane.size() - 1);
    }
};

#endif // SORTING_ALGORITHMS_H
