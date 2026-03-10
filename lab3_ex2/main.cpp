#include "Canvas.h"
#include <iostream>

int main() {
    Canvas canvas(60, 30);
    canvas.DrawRect(2, 2, 15, 8, '*');
    canvas.FillRect(4, 4, 13, 6, '*');
    canvas.DrawLine(20, 2, 40, 10, '*');
    canvas.SetPoint(30, 6, 'X');
    canvas.DrawCircle(15, 20, 6, '*');
    canvas.FillCircle(40, 20, 5, '*');
    canvas.Print();
    canvas.Clear();


    return 0;
}