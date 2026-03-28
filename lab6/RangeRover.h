//
// Created by Andrei Vacariu on 28.03.2026.
//

#ifndef LAB6_RANGEROVER_H
#define LAB6_RANGEROVER_H
#include "Car.h"


class RangeRover : public Car{
public:
    int getSpeed(Weather w) override;
    double getFuelCapacity() override;
    double getFuelConsumption(Weather w) override;
};


#endif //LAB6_RANGEROVER_H