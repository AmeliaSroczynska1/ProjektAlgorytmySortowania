#ifndef OBSLUGA_PLIKU_H
#define OBSLUGA_PLIKU_H

#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ObslugaPliku {
private:
    ifstream plik;
public:
    // Przechowuje wczytane dane
    vector<int> dane;
    int rozmiar = 0;

    bool otworzPlik(const std::string& nazwaPliku);
    bool wczytajRozmiar();
    bool wczytajWyniki();
    void zamknijPlik();
    static void zapiszCzas(const string& nazwaAlgorytmu, float czas, int rozmiar);

    void otworz(const string& nazwaPliku); // Nowa metoda
};

#endif // OBSLUGA_PLIKU_H
