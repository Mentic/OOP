//
// Created by Andrei Vacariu on 28.03.2026.
//

#include "Fiat.h"

int Fiat::getSpeed(Weather w) {
    if (w == Weather::Rain) {
        return 80;
    } else if (w == Weather::Snow) {
        return 60;
    } else if (w == Weather::Sunny) {
        return 100;
    }
}
double Fiat::getFuelCapacity() {
    return 45;
}
double Fiat::getFuelConsumption(Weather w) {
    if (w == Weather::Rain) {
        return 6.5;
    } else if (w == Weather::Snow) {
        return 7.5;
    } else if (w == Weather::Sunny) {
        return 5;
    }
}