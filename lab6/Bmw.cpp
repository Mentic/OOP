//
// Created by Andrei Vacariu on 27.03.2026.
//

#include "Bmw.h"

int Bmw::getSpeed(Weather w) {
    if (w == Weather::Rain) {
        return 110;
    } else if (w == Weather::Snow) {
        return 90;
    } else if (w == Weather::Sunny) {
        return 130;
    }
}
double Bmw::getFuelCapacity() {
    return 55;
}
double Bmw::getFuelConsumption(Weather w) {
    if (w == Weather::Rain) {
        return 9.3;
    } else if (w == Weather::Snow) {
        return 10;
    } else if (w == Weather::Sunny) {
        return 7.5;
    }
}