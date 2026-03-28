#include <stdio.h>
#include "Circuit.h"
#include "Car.h"
#include "Bmw.h"
#include "Volvo.h"
#include <iostream>
#include "Weather.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
using namespace std;

int main()
{
    Circuit c;
    c.setLength(100);
    c.setCapacity(8);
    c.setWeather(Weather::Rain);
    c.addCar(new Volvo());
    c.addCar(new Bmw());
    c.addCar(new Seat());
    c.addCar(new Fiat());
    c.addCar(new RangeRover());
    c.startRace();
    c.showFinalResults(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    c.showWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    return 0;
}
