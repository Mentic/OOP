#pragma once

class Number {
private:
    char* val;
    int base;
    int val_to_int() const;
    void int_to_val(int v, int b);

public:
    Number(const char* value, int base);
    Number(int value);
    Number(const Number& n);
    ~Number();
    Number& operator=(const Number& n);
    Number& operator=(int v);
    Number& operator=(const char* s);
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& n);
    bool operator>(const Number& n) const;
    char operator[](int index) const;
    Number& operator--();
    Number operator--(int);
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};