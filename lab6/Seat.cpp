//
// Created by Andrei Vacariu on 28.03.2026.
//

#include"Seat.h"

int Seat::getSpeed(Weather w) {
    if (w == Weather::Rain) {
        return 90;
    } else if (w == Weather::Snow) {
        return 70;
    } else if (w == Weather::Sunny) {
        return 110;
    }
}
double Seat::getFuelCapacity() {
    return 50;
}
double Seat::getFuelConsumption(Weather w) {
    if (w == Weather::Rain) {
        return 7.5;
    } else if (w == Weather::Snow) {
        return 8.5;
    } else if (w == Weather::Sunny) {
        return 6;
    }
}