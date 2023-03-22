// https://codeforces.com/problemset/problem/1030/A

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nC = 0;
    cin >> nC;
    
    for (int i = 0; i < nC; i++) {
        int input = 0;
        cin >> input;
        if (input == 1) {
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}
