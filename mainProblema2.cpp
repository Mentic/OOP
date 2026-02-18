#include <cstdio>
#include <iostream>
using namespace std;
 char text[100];
char copie[100][100];


int main() {

    scanf(" %99[^\n]", text);
    int i=0;
    int k=0;
    int j=0;
    int words = 0;
    for (i=0;i<strlen(text);i++) {

        if (text[i]==' ') {
                j++;
                k=0;
                words++;
        }else {
            copie[j][k]=text[i];
            k++;
        }
    }

    for (int i = 0; i<=words;i++)
        {
        int ultim = words-1;
        while (ultim > 0)
            {
             int n = ultim - 1;
             ultim = 0;
            for (j=0;j<=words;j++) {
                if (strlen(copie[j])<strlen(copie[j+1])) {
                    swap(copie[j], copie[j+1]);
                    ultim = j;
                }
            }
        }
    }
    for (int i = 0; i<=words;i++) {
        cout<<copie[i]<<endl;
    }

    return 0;
}
