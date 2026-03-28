//
// Created by Andrei Vacariu on 27.03.2026.
//
#pragma once
#ifndef LAB6_VOLVO_H
#define LAB6_VOLVO_H
#include "Car.h"

class Volvo : public Car{
public:
    int getSpeed(Weather w) override;
    double getFuelCapacity() override;
    double getFuelConsumption(Weather w) override;


};


#endif //LAB6_VOLVO_H