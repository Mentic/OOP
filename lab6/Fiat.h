//
// Created by Andrei Vacariu on 28.03.2026.
//
#pragma once
#ifndef LAB6_FIAT_H
#define LAB6_FIAT_H
#include "Car.h"


class Fiat : public Car{
public:
    int getSpeed(Weather w) override;
    double getFuelCapacity() override;
    double getFuelConsumption(Weather w) override;
};


#endif //LAB6_FIAT_H