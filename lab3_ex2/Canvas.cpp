#include "Canvas.h"
#include <iostream>
#include <cmath>
using namespace std;
Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    canvas = new char*[height];
    for (int i = 0; i < height; ++i) {
        canvas[i] = new char[width];
    }

    Clear();
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] canvas[i];
    }
    delete[] canvas;
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        canvas[y][x] = ch;
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << canvas[i][j];
        }
        std::cout <<std::endl;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx;
    int sy;
    if (x1<x2) {
        sx=1;
    }
    else {
        sx=-1;
    }
    if (y1<y2) {
        sy=1;
    }
    else {
        sy=-1;
    }
    int er = dx - dy;

    while (true) {
        SetPoint(x1, y1, ch);

        if (x1==x2&&y1==y2) {
            break;
        }

        int e2=2*er;
        if (e2>-dy) {
            er-=dy;
        }
        if (e2 < dx) {
            er += dx;
            y1 += sy;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int y = top; y <= bottom; ++y) {
        for (int x = left; x <= right; ++x) {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::DrawCircle(int xc, int yc, int ray, char ch) {
    int x = 0;
    int y = ray;
    int d = 3 - 2 * ray;

    while (y >= x) {
        SetPoint(xc + x, yc + y, ch);
        SetPoint(xc - x, yc + y, ch);
        SetPoint(xc + x, yc - y, ch);
        SetPoint(xc - x, yc - y, ch);
        SetPoint(xc + y, yc + x, ch);
        SetPoint(xc - y, yc + x, ch);
        SetPoint(xc + y, yc - x, ch);
        SetPoint(xc - y, yc - x, ch);

        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void Canvas::FillCircle(int xc, int yc, int ray, char ch) {
    for (int y = yc - ray; y <= yc + ray; ++y) {
        for (int x = xc - ray; x <= xc + ray; ++x) {
            if ((x - xc) * (x - xc) + (y - yc) * (y - yc) <= ray * ray) {
                SetPoint(x, y, ch);
            }
        }
    }
}