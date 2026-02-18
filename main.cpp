#include <iostream>
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    int v[5]= {6 ,3 ,8 ,5, 9};
    int ultim = 4;
    while (ultim > 0)
    {
        int n = ultim-1;
        ultim=0;
        for (int i = 0; i <= n; i++) {
            if (v[i]>v[i+1]) {
                swap(v[i], v[i+1]);
                ultim = i;
            }

        }

    }
    for (int i = 0; i < 5; i++) {
        int
    }


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}