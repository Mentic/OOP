//
// Created by Andrei Vacariu on 11.03.2026.
//
#include <iostream>
#ifndef LAB4_TEMA_SORT_H
#define LAB4_TEMA_SORT_H
using namespace std;
class Sort      {
    int n;
    int* vector;

public:

    Sort(int n, int a[]);
    Sort(int n,int min, int max);
    Sort(int const, ...);
    Sort(char c[]);
    Sort(initializer_list<int> list);
    void InsertSort(bool ascendent=false);

    int Partition(int low, int high, bool ascendent);

    void QuickSortRecursive(int low, int high, bool ascendent);

    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

#endif //LAB4_TEMA_SORT_H