//
// Created by Andrei Vacariu on 11.03.2026.
//

#include "Sort.h"
#include <iostream>
#include <random>
using namespace std;

Sort::Sort(initializer_list<int> list) {
    this->n = list.size();
    this->vector = new int[this->n];
    int i = 0;
    for (int element : list) {
        this->vector[i] = element;
        i++;
    }
}

Sort::Sort(int n, int a[])
{
    this->n = n;
    this->vector = new int[n];
    for (int i = 0; i < n; i++)
        this->vector[i] = a[i];
}

Sort::Sort(int n, int min, int max) {
    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<int> distribution(min, max);
    this->n = n;
    this->vector = new int[n];
    for (int i = 0; i < n; i++)
        this->vector[i] = distribution(generator);

}

Sort::Sort(int const n, ...) {
    va_list arguments;
    va_start(arguments, n);
    this->n = n;
    this->vector = new int[n];
    for (int i = 0; i < n; i++)
        this->vector[i] = va_arg(arguments, int);
    va_end(arguments);
}

Sort::Sort(char c[]) {
    int size = 0;
    for (int i = 0;i<strlen(c);i++)
        if (c[i]==',')
            size++;
    this->n = size+1;
    this->vector = new int[this->n];
    int number = 0;
    int k = 0;
    for (int i = 0;i<=strlen(c);i++) {
        if (isdigit(c[i])) {
            number = number * 10 + (c[i]- '0');
        }else if (c[i] == ','|| c[i]==NULL) {
            this->vector[k] = number;
            k++;
            number = 0;
        }
    }
}

void Sort::BubbleSort(bool ascendent) {
    if (ascendent) {
        for (int i =0 ; i< this->n ; i++)
            for (int j = 0; j < this->n - i - 1; j++)
                if (this->vector[j] > this->vector[j + 1])
                    swap(this->vector[j], this->vector[j + 1]);
    }else {
        for (int i =0 ; i< this->n ; i++)
            for (int j = 0; j < this->n - i - 1; j++)
                if (this->vector[j] < this->vector[j + 1])
                    swap(this->vector[j], this->vector[j + 1]);
    }

}
void Sort::Print() {
    for (int i = 0; i < this->n; i++)
        cout << this->vector[i] << " ";
    cout << endl;
}

int Sort::GetElementFromIndex(int index) {
    return this->vector[index];
}
int Sort::GetElementsCount() {
    return this->n;
}
void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < n; i++) {
        int key = vector[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? (vector[j] > key) : (vector[j] < key))) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}
int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = vector[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        if (ascendent) {
            do { i++; } while (vector[i] < pivot);
            do { j--; } while (vector[j] > pivot);
        } else {
            do { i++; } while (vector[i] > pivot);
            do { j--; } while (vector[j] < pivot);
        }

        if (i >= j) return j;

        // Swap elements
        int temp = vector[i];
        vector[i] = vector[j];
        vector[j] = temp;
    }
}



void Sort::QuickSortRecursive(int low, int high, bool ascendent) {
    if (low < high) {
        int p = Partition(low, high, ascendent);
        QuickSortRecursive(low, p, ascendent);
        QuickSortRecursive(p + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    if (n > 0) {
        QuickSortRecursive(0, n - 1, ascendent);
    }
}


