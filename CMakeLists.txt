cmake_minimum_required(VERSION 3.25)
project(ProjektAlgorytmySortowania)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProjektAlgorytmySortowania
        main.cpp
        AlgorytmySortowania/QuickSort.cpp AlgorytmySortowania/QuickSort.h
        ObslugaDanych.cpp ObslugaDanych.h
        Test.cpp Test.h
        Timer.cpp Timer.h
        ResultsLogger.cpp ResultsLogger.h
        Menu.cpp Menu.h AlgorytmySortowania/PrzezWstawianie.cpp AlgorytmySortowania/PrzezWstawianie.h AlgorytmySortowania/PrzezKopcowanie.cpp AlgorytmySortowania/PrzezKopcowanie.h AlgorytmySortowania/Shella.cpp AlgorytmySortowania/Shella.h)
