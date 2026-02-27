//
// Created by Andrei Vacariu on 25.02.2026.
//

#include "Student.h"

void Student::setName(char name[]) {
    for (int i = 0; i < 30; i++) {
        this->name[i] = name[i];
    }
}

char *Student::getName() {
    return this->name;
}

void Student::setNotaIstorie(int notaIstorie) {
    if (notaIstorie <0 || notaIstorie > 10) {
        this->nota_istorie = 0;
    }else {
        this->nota_istorie = notaIstorie;
    }

}
void Student::setNotaMatematica(int notaMatematica) {
    if (notaMatematica <0 || notaMatematica> 10) {
        this->nota_matematica= 0;
    }else {
        this->nota_matematica = notaMatematica;
    }
}
void Student::setNotaEngleza(int notaEngleza) {
    if (notaEngleza <0 || notaEngleza > 10) {
        this->nota_istorie = 0;
    }else {
        this->nota_engleza = notaEngleza;
    }
}
int Student::getNotaMatematica() {
    return this->nota_matematica;
}
int Student::getNotaEngleza() {
    return this->nota_engleza;
}
int Student::getNotaIstorie() {
    return this->nota_istorie;
}

float Student::notaMedie() {
    return (this->nota_matematica + this->nota_istorie + this->nota_engleza) / 3;
}


