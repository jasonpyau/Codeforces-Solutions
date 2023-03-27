// https://codeforces.com/problemset/problem/1807/B

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
        int m = 0, b = 0;
        for (int i = 0; i < len; i++) {
            int input = 0;
                cin >> input;
            if (input % 2 == 0)
                m += input;
            else
                b += input;
        }
        cout << ((m > b) ? "YES" : "NO") << '\n';

    }

    return 0;
}
