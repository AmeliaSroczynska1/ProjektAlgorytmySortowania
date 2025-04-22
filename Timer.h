#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::string nazwa;
    long long czas = 0;

public:
    Timer(const std::string& nazwa = "Sortowanie")
            : nazwa(nazwa), start(std::chrono::high_resolution_clock::now()) {}

    void zatrzymaj() {
        auto end = std::chrono::high_resolution_clock::now();
        czas = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    long long pobierzCzas() const {
        return czas;
    }

};

#endif // TIMER_H
