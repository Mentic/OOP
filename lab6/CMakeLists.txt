cmake_minimum_required(VERSION 4.1)
project(lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab6 main.cpp
        Weather.cpp
        Weather.h
        Car.cpp
        Car.h
        Volvo.cpp
        Volvo.h
        Bmw.cpp
        Bmw.h
        Circuit.cpp
        Circuit.h
        Seat.cpp
        Seat.h
        Fiat.cpp
        Fiat.h
        RangeRover.cpp
        RangeRover.h)
