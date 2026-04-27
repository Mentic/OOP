#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;
ifstream fin ("text.txt");

struct Sortare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    }
};

int main() {
    string sentece="";
    string word;

    while (getline(fin,word)) {
        sentece +=word + " ";
    }
    map<string, int> wordCount;
    string currentWord = "";
    for (char c : sentece) {
        if (c == ' ' || c == '\n' || c == '?' || c == '!' || c == '.' ) {
            if (!currentWord.empty()) {
                wordCount[currentWord]++;
                currentWord = "";
            }
        } else {
            currentWord += tolower(c);
        }
    }
    if (currentWord != "") {
        wordCount[currentWord]++;
    }
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Sortate:" << endl;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Sortare> Coada;
    for (const auto& pair : wordCount) {
        Coada.push(pair);
    }
    while (!Coada.empty()) {
        cout << Coada.top().first << "=> " << Coada.top().second << endl;
        Coada.pop();
    }



    return 0;
}
