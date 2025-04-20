#ifndef PROJEKTALGORYTMYSORTOWANIA_SHELLA_H
#define PROJEKTALGORYTMYSORTOWANIA_SHELLA_H

#include <vector>
#include <algorithm>

using namespace std;

class Shella {
public:
    template<typename T>
    static void sortuj(vector<T>& dane, int lewo, int prawo) {
        int rozmiar = prawo - lewo + 1;

        // Generowanie sekwencji przerw (wersja klasyczna: N/2, N/4, ..., 1)
        for (int przerwa = rozmiar / 2; przerwa > 0; przerwa /= 2) {

            // Sortowanie podzbiorów dla aktualnej przerwy
            for (int i = lewo + przerwa; i <= prawo; ++i) {
                T aktualny = dane[i];
                int j = i;

                // Przesuwanie elementów w podzbiorze
                while (j >= lewo + przerwa && dane[j - przerwa] > aktualny) {
                    dane[j] = dane[j - przerwa];
                    j -= przerwa;
                }
                dane[j] = aktualny;
            }
        }
    }

    // Wersja sortująca cały wektor
    template<typename T>
    static void sortuj(vector<T>& dane) {
        if (!dane.empty())
            sortuj(dane, 0, dane.size() - 1);
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_SHELLA_H
