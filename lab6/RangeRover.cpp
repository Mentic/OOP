//
// Created by Andrei Vacariu on 28.03.2026.
//

#include "RangeRover.h"

int RangeRover::getSpeed(Weather w) {
    if (w == Weather::Rain) {
        return 95;
    } else if (w == Weather::Snow) {
        return 75;
    } else if (w == Weather::Sunny) {
        return 115;
    }
}
double RangeRover::getFuelCapacity() {
    return 70;
}
double RangeRover::getFuelConsumption(Weather w) {
    if (w == Weather::Rain) {
        return 10;
    } else if (w == Weather::Snow) {
        return 11;
    } else if (w == Weather::Sunny) {
        return 8;
    }
}