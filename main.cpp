#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include <iostream>
#include "Sort.h"
using namespace std;
int main() {

    Sort sort5({1,4,7,4,8,10});
    sort5.Print();
    sort5.BubbleSort();
    sort5.Print();
    int a[5] = { 8, 3, 6, 12, 0 };
    Sort sort2(5, a);
    sort2.BubbleSort(true);
    sort2.Print();
    char c[]="10,2,4,3,5";
    Sort sort(c);
    sort.Print();
    sort.BubbleSort(true);
    sort.Print();
    sort.BubbleSort(false);

    Sort sort3(4, 1, 12, 5 , 9);
    sort3.Print();
    sort3.BubbleSort();
    sort3.Print();
    Sort sort4(6, 2, 23);
    sort4.Print();
    sort4.BubbleSort(true);
    sort4.Print();
return 0;

}