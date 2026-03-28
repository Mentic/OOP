//
// Created by Andrei Vacariu on 27.03.2026.
//
#pragma once
#ifndef LAB6_CAR_H
#define LAB6_CAR_H
#include "Weather.h"
#include <iostream>
using namespace std;

class Car {
public:
    virtual int getSpeed(Weather w) = 0;
    virtual double getFuelCapacity() = 0;
    virtual double getFuelConsumption(Weather w) = 0;
private:
    int speed;
    double fuelCapacity;
    double fuelConsumption;
};


#endif //LAB6_CAR_H