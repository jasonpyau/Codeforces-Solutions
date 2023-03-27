// https://codeforces.com/problemset/problem/1807/A

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
        int a, b, t;
        cin >> a >> b >> t;
        cout << ((a+b == t) ? '+' : '-') << '\n';

    }

    return 0;
}
