#ifndef PROJEKTALGORYTMYSORTOWANIA_PRZEZKOPCOWANIE_H
#define PROJEKTALGORYTMYSORTOWANIA_PRZEZKOPCOWANIE_H

#include <vector>
#include <algorithm>

using namespace std;

class PrzezKopcowanie {
private:
    template<typename T>
    static void kopcowanie(vector<T>& dane, int rozmiar, int korzen) {
        int najwiekszy = korzen;
        int lewy = 2 * korzen + 1;
        int prawy = 2 * korzen + 2;

        if (lewy < rozmiar && dane[lewy] > dane[najwiekszy])
            najwiekszy = lewy;

        if (prawy < rozmiar && dane[prawy] > dane[najwiekszy])
            najwiekszy = prawy;

        if (najwiekszy != korzen) {
            swap(dane[korzen], dane[najwiekszy]);
            kopcowanie(dane, rozmiar, najwiekszy);
        }
    }

    template<typename T>
    static void budujKopiec(vector<T>& dane, int rozmiar) {
        for (int i = rozmiar / 2 - 1; i >= 0; i--)
            kopcowanie(dane, rozmiar, i);
    }

public:
    template<typename T>
    static void sortuj(vector<T>& dane, int lewo, int prawo) {
        int rozmiar = prawo - lewo + 1;
        vector<T> podtablica(dane.begin() + lewo, dane.begin() + prawo + 1);

        budujKopiec(podtablica, rozmiar);

        for (int i = rozmiar - 1; i > 0; i--) {
            swap(podtablica[0], podtablica[i]);
            kopcowanie(podtablica, i, 0);
        }

        copy(podtablica.begin(), podtablica.end(), dane.begin() + lewo);
    }

    template<typename T>
    static void sortuj(vector<T>& dane) {
        if (!dane.empty())
            sortuj(dane, 0, dane.size() - 1);
    }
};

#endif // PRZEZ_KOPCOWANIE_H
