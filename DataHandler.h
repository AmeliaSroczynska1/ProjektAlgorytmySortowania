#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <random>
#include <iostream>

class DataHandler {
public:
    template<typename T>
    static std::vector<T> generateRandomData(int size) {
        std::vector<T> data(size);
        std::random_device rd;
        std::mt19937 gen(rd());

        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> dist(1, 100);
            for (auto& element : data)
                element = dist(gen);
        } else {
            std::uniform_real_distribution<T> dist(0.0, 100.0);
            for (auto& element : data)
                element = dist(gen);
        }
        return data;
    }

    template<typename T>
    static void printData(const std::vector<T>& data) {
        for (const auto& element : data)
            std::cout << element << " ";
        std::cout << "\n";
    }
};

#endif // DATA_HANDLER_H
