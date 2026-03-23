#include "Number.h"
#include <iostream>
#include <string.h>

int Number::val_to_int() const {
    int res = 0;
    for (int i = 0; val[i] != '\0'; i++) {
        int d = 0;
        if (val[i] >= '0' && val[i] <= '9') d = val[i] - '0';
        else if (val[i] >= 'A' && val[i] <= 'F') d = val[i] - 'A' + 10;
        else if (val[i] >= 'a' && val[i] <= 'f') d = val[i] - 'a' + 10;

        res = res * base + d;
    }
    return res;
}

void Number::int_to_val(int v, int b) {
    if (val) delete[] val;
    base = b;

    if (v == 0) {
        val = new char[2];
        strcpy(val, "0");
        return;
    }

    char buf[100];
    int idx = 0;
    while (v > 0) {
        int r = v % b;
        if (r < 10) buf[idx++] = r + '0';
        else buf[idx++] = r - 10 + 'A';
        v /= b;
    }
    buf[idx] = '\0';

    val = new char[idx + 1];
    for (int i = 0; i < idx; i++) {
        val[i] = buf[idx - i - 1];
    }
    val[idx] = '\0';
}

Number::Number(const char* value, int b) {
    base = b;
    val = new char[strlen(value) + 1];
    strcpy(val, value);
}

Number::Number(int value) {
    val = nullptr;
    int_to_val(value, 10);
}

Number::Number(const Number& n) {
    base = n.base;
    val = new char[strlen(n.val) + 1];
    strcpy(val, n.val);
}

Number::~Number() {
    delete[] val;
}

Number& Number::operator=(const Number& n) {
    if (this != &n) {
        delete[] val;
        base = n.base;
        val = new char[strlen(n.val) + 1];
        strcpy(val, n.val);
    }
    return *this;
}

Number& Number::operator=(int v) {
    int_to_val(v, this->base);
    return *this;
}

Number& Number::operator=(const char* s) {
    delete[] val;
    val = new char[strlen(s) + 1];
    strcpy(val, s);
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base;
    int sum = n1.val_to_int() + n2.val_to_int();

    Number res(0);
    res.int_to_val(sum, maxBase);
    return res;
}

Number operator-(const Number& n1, const Number& n2) {
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base;
    int diff = n1.val_to_int() - n2.val_to_int();

    Number res(0);
    res.int_to_val(diff, maxBase);
    return res;
}

Number& Number::operator+=(const Number& n) {
    int sum = this->val_to_int() + n.val_to_int();
    int_to_val(sum, this->base);
    return *this;
}

bool Number::operator>(const Number& n) const {
    return this->val_to_int() > n.val_to_int();
}

char Number::operator[](int index) const {
    return val[index];
}

Number& Number::operator--() {
    if (strlen(val) > 0) {
        strcpy(val, val + 1);
    }
    return *this;
}

Number Number::operator--(int) {
    Number copie(*this);
    int len = strlen(val);
    if (len > 0) {
        val[len - 1] = '\0';
    }
    return copie;
}

void Number::SwitchBase(int newBase) {
    int v = val_to_int();
    int_to_val(v, newBase);
}

void Number::Print() const {
    std::cout << val << "\n";
}

int Number::GetDigitsCount() const {
    return strlen(val);
}

int Number::GetBase() const {
    return base;
}