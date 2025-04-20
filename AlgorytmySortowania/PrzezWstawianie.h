#ifndef PROJEKTALGORYTMYSORTOWANIA_PRZEZWSTAWIANIE_H
#define PROJEKTALGORYTMYSORTOWANIA_PRZEZWSTAWIANIE_H

#include <vector>
#include <algorithm>

using namespace std;

class PrzezWstawianie {
public:
    template<typename T>
    // Implementacja sortowania przez wstawianie
    static void sortuj(vector<T>& dane, int lewo, int prawo) {
        for (int i = lewo + 1; i <= prawo; ++i) {
            T aktualny = dane[i];
            int j = i - 1;

            // Przesuwaj elementy większe od aktualnego w prawo
            while (j >= lewo && dane[j] > aktualny) {
                dane[j + 1] = dane[j];
                --j;
            }
            dane[j + 1] = aktualny;
        }
    }

    // Wrapper
    template<typename T>
    static void sortuj(vector<T>& dane) {
        if (!dane.empty())
            sortuj(dane, 0, dane.size() - 1);
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_PRZEZWSTAWIANIE_H
