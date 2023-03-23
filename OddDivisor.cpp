// https://codeforces.com/contest/1475/problem/A

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
        u64 n = 0;
        bool ans = false;
        cin >> n;
        while (n > 1 && !ans) {
            if (n % 2 == 1)
                ans = true;
            n /= 2;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
