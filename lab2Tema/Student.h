//
// Created by Andrei Vacariu on 25.02.2026.
//

#ifndef LAB2TEMA_STUDENT_H
#define LAB2TEMA_STUDENT_H


class Student {
    char name[30];
    int nota_matematica;
    int nota_istorie;
    int nota_engleza;

public:
    void setName(char name[]);
    void setNotaMatematica(int notaMatematica);
    void setNotaIstorie(int notaIstorie);
    void setNotaEngleza(int notaEngleza);
    char* getName();
    int getNotaMatematica();
    int getNotaIstorie();
    int getNotaEngleza();
    float notaMedie();

};


#endif //LAB2TEMA_STUDENT_H