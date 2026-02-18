#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("text.txt");
int main() {

    if (!fin.is_open()) {
        cout << "dawda";
        return 0;
    }
    int x;
    int sum = 0;
    while(fin>>x)
        sum +=x;
    cout<<sum;
    fin.close();
    return 0;


}

