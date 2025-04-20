#include <iostream>
#include "SortingAlgorithms.h"
#include "DataHandler.h"

using namespace std;

int main() {
    // Generowanie danych testowych
    vector<int> data = DataHandler::generateRandomData<int>(10);

    // Wyświetlanie danych przed sortowaniem
    cout << "Dane przed sortowaniem:\n";
    DataHandler::printData(data);

    // Sortowanie
    quickSort(data);

    // Wyświetlanie danych po sortowaniu
    cout << "\nDane po sortowaniu:\n";
    DataHandler::printData(data);

    return 0;
}
