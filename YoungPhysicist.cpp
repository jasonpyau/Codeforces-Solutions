// https://codeforces.com/problemset/problem/69/A

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
    
    int nets[3] {0};
    for (int c = 0; c < nC; c++) {
        int f[3] = {0};
        cin >> f[0] >> f[1] >> f[2];
        for (int i = 0; i < 3; i++)
            nets[i] += f[i];
    }
    bool ans = true;
    for (int net : nets) {
        if (net != 0)
            ans = false;
    }
    cout << (ans ? "YES" : "NO") << '\n';    
    return 0;
}
