#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm>

// Najpierw deklarujemy partition
template<typename T>
int partition(std::vector<T>& data, int left, int right) {
    T pivot = data[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

// Definiujemy quickSort
template<typename T>
void quickSort(std::vector<T>& data, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(data, left, right); // Teraz partition jest widoczne
        quickSort(data, left, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, right);
    }
}

template<typename T>
void quickSort(std::vector<T>& data) {
    if (!data.empty())
        quickSort(data, 0, data.size() - 1);
}

#endif // SORTING_ALGORITHMS_H
