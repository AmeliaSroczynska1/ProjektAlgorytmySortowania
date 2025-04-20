cmake_minimum_required(VERSION 3.25)
project(ProjektAlgorytmySortowania)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProjektAlgorytmySortowania
        main.cpp
        cmake-build-debug/algorytmy.h
        SortingAlgorithms.cpp SortingAlgorithms.h
        DataHandler.cpp DataHandler.h
        TestUtils.cpp TestUtils.h
        Timer.cpp Timer.h
        ResultsLogger.cpp ResultsLogger.h
        Menu.cpp Menu.h)
