#include "Number.h"
#include <iostream>
#include <cstring>

void Number::CopyString(const char* str) {
    if (str) {
        value = new char[strlen(str) + 1];
        strcpy(value, str);
    } else {
        value = new char[1];
        value[0] = '\0';
    }
}

int Number::ToBase10() const {
    int suma = 0;
    int long putere = 1;
    int len = strlen(value);

    for (int i = len - 1; i >= 0; --i) {
        int digit = 0;
        if (value[i] >= '0' && value[i] <= '9') {
            digit = value[i] - '0';
        } else if (value[i] >= 'A' && value[i] <= 'F') {
            digit = value[i] - 'A' + 10;
        } else if (value[i] >= 'a' && value[i] <= 'f') {
            digit = value[i] - 'a' + 10;
        }
        suma = suma+  digit * putere;
        putere = putere * baza;
    }
    return suma;
}
void Number::FromBase10(int val, int newBase) {
    if (value) delete[] value;
    baza = newBase;
    if (val == 0) {
        CopyString("0");
        return;
    }

    char buffer[64];
    int idx = 0;
    bool negativ = false;

    if (val < 0) {
        negativ = true;
        val = -val;
    }
    while (val > 0) {
        int rem = val % baza;
        if (rem < 10) buffer[idx++] = '0' + rem;
        else buffer[idx++] = 'A' + (rem - 10);
        val /= newBase;
    }

    if (negativ) buffer[idx++] = '-';
    buffer[idx] = '\0';
    for (int i = 0; i < idx / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[idx - 1 - i];
        buffer[idx - 1 - i] = temp;
    }
    CopyString(buffer);
}

Number::Number(const char* value, int base) : baza(base) {
    CopyString(value);
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) : baza(other.baza) {
    CopyString(other.value);
}

Number::Number(Number&& other) noexcept : value(other.value), baza(other.baza) {
    other.value = nullptr;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        baza = other.baza;
        CopyString(other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        baza = other.baza;
        other.value = nullptr;
    }
    return *this;
}

char Number::operator[](int index) const {
    int len = strlen(value);
    if (index < 0 || index >= len) throw std::out_of_range("Index out of range");
    return value[index];
}

bool Number::operator>(const Number& other) const {
    return ToBase10() > other.ToBase10();
}

bool Number::operator<(const Number& other) const {
    return ToBase10() < other.ToBase10();
}

bool Number::operator>=(const Number& other) const {
    return ToBase10() >= other.ToBase10();
}

bool Number::operator<=(const Number& other) const {
    return ToBase10() <= other.ToBase10();
}

bool Number::operator==(const Number& other) const {
    return ToBase10() == other.ToBase10();
}

bool Number::operator!=(const Number& other) const {
    return ToBase10() != other.ToBase10();
}

Number& Number::operator--() {
    int val = ToBase10();
    --val;
    FromBase10(val, baza);
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    --(*this);
    return temp;
}

void Number::SwitchBase(int newBase) {
    int val = ToBase10();
    FromBase10(val, newBase);
}

void Number::Print() const {
    std::cout << value << " (base " << baza << ")\n";
}

int Number::GetDigitsCount() const {
    return strlen(value);
}

int Number::GetBase() const {
    return baza;
}


