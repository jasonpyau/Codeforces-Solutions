// https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int nC = 0;
    cin >> nC;
    for (int c = 0; c < nC; c++) {
        string ans;   
        string input;
        cin >> input;
        int len = input.length();
        if (len > 10)
            ans = input[0] + to_string(len-2) + input[len-1];
        else 
            ans = input;
        cout << ans << '\n';
    }
    return 0;
}
