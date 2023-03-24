// https://codeforces.com/problemset/problem/1791/B

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <cstdint>
#define ll long long
#define u64 uint64_t
#define i64 int64_t
using namespace std;
 
int main() {
    int nC = 0;
    cin >> nC;
    
    for (int c = 0; c < nC; c++) {
        int len = 0;
        cin >> len;
        string s;
        cin >> s;
        int x = 0, y = 0;
        bool ans = false;
        for (char ch : s) {
            if (ch == 'L')
                x--;
            else if (ch == 'R')
                x++;
            else if (ch == 'U')
                y++;
            else if (ch == 'D')
                y--;
            if (x == 1 && y == 1) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
