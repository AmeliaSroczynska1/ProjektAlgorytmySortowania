#ifndef PROJEKTALGORYTMYSORTOWANIA_TEST_H
#define PROJEKTALGORYTMYSORTOWANIA_TEST_H

class Test {
public:
    template<typename T>
    static void testSortowanie(const vector<T>& tablica) {
        int licznik = 0;
        for (int i = 0; i < tablica.size() - 1; ++i) {
            if (tablica[i] > tablica[i + 1]) {
                licznik++;
            }
        }
        if (licznik > 0) {
            cout << "Tablica nie jest posortowana" << endl;
        }
        else {
            cout << "Tablica jest posortowana" << endl;
        }
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_TEST_H
