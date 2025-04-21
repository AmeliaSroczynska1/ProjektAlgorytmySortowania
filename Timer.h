#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::string nazwa;

public:
    Timer(const std::string& nazwa = "Sortowanie")
            : nazwa(nazwa), start(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "[Czas " << nazwa << "]: " << duration.count() << " μs\n";
    }
};

#endif // TIMER_H
