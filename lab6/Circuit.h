//
// Created by Andrei Vacariu on 27.03.2026.
//

#ifndef LAB6_CIRCUIT_H
#define LAB6_CIRCUIT_H
#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    int capacity;
    double length;
    Weather weather;
    Car *cars[100];
    int numberOfCars = 0;
    Car *finishedCars[100] = {nullptr};
    int numberOfFinishedCars = 0;
    Car *noFinishedCars[100] = {nullptr};
        int numberOfNoFinishedCars = 0;
public:
    Car* getCar(int position);
    void setCapacity(int capacity);
   void setLength(double length);
   void setWeather(Weather weather);
    void addCar(Car* car);
    void startRace();
    void showFinalResults();
    void showWhoDidNotFinish();


};


#endif //LAB6_CIRCUIT_H