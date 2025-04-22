#ifndef PROJEKTALGORYTMYSORTOWANIA_SHELLA_H
#define PROJEKTALGORYTMYSORTOWANIA_SHELLA_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Shella {
public:
    enum GapType { KLASYCZNA, CIURA };
    static GapType gapTyp;

    template<typename T>
    static void sortuj(vector<T>& dane, int lewo, int prawo) {
        vector<int> przerwy = generujPrzerwy(prawo - lewo + 1);

        for (int przerwa : przerwy) {
            for (int i = lewo + przerwa; i <= prawo; ++i) {
                T aktualny = dane[i];
                int j = i;

                while (j >= lewo + przerwa && dane[j - przerwa] > aktualny) {
                    dane[j] = dane[j - przerwa];
                    j -= przerwa;
                }
                dane[j] = aktualny;
            }
        }
    }

    template<typename T>
    static void sortuj(vector<T>& dane) {
        if (!dane.empty()) sortuj(dane, 0, dane.size() - 1);
    }

private:
    static vector<int> generujPrzerwy(int rozmiar) {
        vector<int> przerwy;

        switch(gapTyp) {
            case KLASYCZNA: {
                for (int gap = rozmiar/2; gap > 0; gap /= 2) {
                    przerwy.push_back(gap);
                }
                break;
            }
            case CIURA: {
                int ciuraGaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
                for (int gap : ciuraGaps) {
                    if (gap <= rozmiar) przerwy.push_back(gap);
                }
                break;
            }
        }

        return przerwy;
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_SHELLA_H
