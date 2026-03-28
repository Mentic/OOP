//
// Created by Andrei Vacariu on 27.03.2026.
//

#ifndef LAB6_BMW_H
#define LAB6_BMW_H
#include "Car.h"

class Bmw : public Car{
public:
    int getSpeed(Weather w) override;
    double getFuelCapacity() override;
    double getFuelConsumption(Weather w) override;
};



#endif //LAB6_BMW_H