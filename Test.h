#ifndef PROJEKTALGORYTMYSORTOWANIA_TEST_H
#define PROJEKTALGORYTMYSORTOWANIA_TEST_H

class Test {
public:
    template<typename T>
    static int testSortowanie(const vector<T>& tablica) {
        int licznik = 0;
        for (int i = 0; i < tablica.size() - 1; ++i) {
            if (tablica[i] > tablica[i + 1]) {
                licznik++;
            }
        }
        return licznik;
    }
};

#endif //PROJEKTALGORYTMYSORTOWANIA_TEST_H
