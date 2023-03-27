// https://codeforces.com/problemset/problem/1807/D

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
        int len, lenq;
        cin >> len >> lenq;
        ll a[len];
        ll sum[len];
        ll s = 0;
        for (int i = 0; i < len; i++) {
            int input;
            cin >> input;
            a[i] = input;
            s += input;
            sum[i] = s;
        }
        for (int q = 0; q < lenq; q++) {
            ll l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            ll s = sum[len-1]-sum[r]+sum[l]-a[l];
            bool ans = ((s+k*(r-l+1))%2 == 1);
            cout << ((ans) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
