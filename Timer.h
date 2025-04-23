#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

using namespace std;

class Timer {
private:
    chrono::time_point<chrono::high_resolution_clock> start;
    string nazwa;
    long long czas = 0;

public:
    Timer(const string& nazwa = "Sortowanie")
            : nazwa(nazwa), start(chrono::high_resolution_clock::now()) {}

    void zatrzymaj() {
        auto end = chrono::high_resolution_clock::now();
        czas = chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    long long pobierzCzas() const {
        return czas;
    }

};

#endif // TIMER_H
