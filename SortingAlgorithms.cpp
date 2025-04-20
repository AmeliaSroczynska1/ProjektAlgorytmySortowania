#include "SortingAlgorithms.h"
#include <vector>
#include <iostream>

int sortAlgorithm() {
    std::vector<int> tab = {5, 2, 9, 1, 5, 6};
    quickSort(tab); // sortowanie całego wektora

    for (int x : tab)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
