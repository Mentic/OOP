//
// Created by Andrei Vacariu on 28.03.2026.
//

#ifndef LAB6_SEAT_H
#define LAB6_SEAT_H
#include "Car.h"

class Seat : public Car{
public:
    int getSpeed(Weather w) override;
    double getFuelCapacity() override;
    double getFuelConsumption(Weather w) override;

};


#endif //LAB6_SEAT_H