//
// Created by Andrei Vacariu on 27.03.2026.
//

#include "Circuit.h"
#include <iostream>
#include <typeinfo>
using namespace std;

void Circuit::setLength(double length) {
    this->length = length;
}

void Circuit::setWeather(Weather weather) {
    this->weather = weather;
}
void Circuit::setCapacity(int capacity) {
    this->capacity = capacity;
}
void Circuit::addCar(Car* car) {
    if (numberOfCars < capacity) {
        cars[numberOfCars] = car;
        numberOfCars++;
    } else {
        cout << "Circuit is full!" << endl;
    }
}
Car* Circuit::getCar(int position) {
    if (position < numberOfCars) {
        return cars[position];
    }
    return nullptr;
}
void Circuit::startRace() {
    this->numberOfFinishedCars = 0;
    this->numberOfNoFinishedCars = 0;
    for (int i = 0; i < numberOfCars; i++) {
        double fuel = cars[i]->getFuelConsumption(weather) /100.0 * length;
        if (fuel <= cars[i]->getFuelCapacity()) {
            finishedCars[numberOfFinishedCars] = cars[i];
            numberOfFinishedCars++;
        }else {
            noFinishedCars[numberOfNoFinishedCars] = cars[i];
            numberOfNoFinishedCars++;
        }
        for (int i = 0; i < numberOfFinishedCars - 1; i++) {
            for (int j = 0; j < numberOfFinishedCars - i - 1; j++) {

                if (finishedCars[j] != nullptr && finishedCars[j+1] != nullptr) {
                    double time1 = (double)length / finishedCars[j]->getSpeed(weather);
                    double time2 = (double)length / finishedCars[j+1]->getSpeed(weather);
                    if (time1 > time2) {
                        Car* temp = finishedCars[j];
                        finishedCars[j] = finishedCars[j+1];
                        finishedCars[j+1] = temp;
                    }
                }
            }
        }
    }

}



void Circuit::showFinalResults() {
    for (int i = 0; i < numberOfFinishedCars; i++) {
        if (finishedCars[i] != nullptr) {
            // Calculăm timpul din nou pentru afișare
            double time = (double)length / finishedCars[i]->getSpeed(weather);

            cout << "Position " << i + 1 << ": "<< typeid(*finishedCars[i]).name()<< " - Time: " << time << " hours" << std::endl;
        }
    }
}
void Circuit::showWhoDidNotFinish() {
    cout << "Cars that did not finish:" << endl;
    for (int i = 0; i < numberOfNoFinishedCars; i++) {
        cout<< typeid(*noFinishedCars[i]).name() << endl;
    }
}