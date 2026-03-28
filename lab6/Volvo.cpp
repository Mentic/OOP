//
// Created by Andrei Vacariu on 27.03.2026.
//

#include "Volvo.h"

int Volvo::getSpeed(Weather w) {
    if (w == Weather::Rain) {
        return 100;
    } else if (w == Weather::Snow) {
        return 80;
    } else if (w == Weather::Sunny) {
        return 120;
    }
}
double Volvo::getFuelCapacity() {
    return 60;
}
double Volvo::getFuelConsumption(Weather w) {
    if (w == Weather::Rain) {
        return 8;
    } else if (w == Weather::Snow) {
        return 9;
    } else if (w == Weather::Sunny) {
        return 6.5;
    }
}