
#include "NumberList.h"
#include <iostream>
void NumberList::Init() {
    this->count = 0;
}

bool NumberList::Add(int x) {
    if (this->count > 10) {
        return false;
    }
    this->numbers[this->count] = x;
    this->count++;
    return true;
}
void NumberList::Print() {
    for (int i = 0; i < this->count; i++) {
        std::cout << this->numbers[i] << " ";
    }
    std::cout << std::endl;
}
void NumberList::Sort() {

    for (int i = 1; i< this->count; i++) {
        int ultim = this->numbers[i];
        int j = i - 1;
        while (j >= 0 && this->numbers[j] > ultim) {
            this->numbers[j + 1] = this->numbers[j];
            j = j - 1;
        }
        this->numbers[j + 1] = ultim;
    }


}
