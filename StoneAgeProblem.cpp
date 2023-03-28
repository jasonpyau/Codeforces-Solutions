// https://codeforces.com/problemset/problem/1679/B

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <cstdint>
#include <map>
#include <unordered_map>
#define ll long long
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    int len, lenq;
    cin >> len >> lenq;
    ll sum = 0;
    int a[len];
    bool def[len];
    for (int i = 0; i < len; i++) {
        int input;
        cin >> input;
        a[i] = input;
        sum += input;
    }
    unordered_map<int, bool> vis;
    int r_all = 0;
    for (int q = 0; q < lenq; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            sum += (vis[i] || !r_all) ? x-a[i] : x-r_all;
            a[i]= x;
            vis[i] = true;
        } else {
            cin >> r_all;
            sum = (ll)len*r_all;
            vis.clear();
        }
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    // cin >> nC;
    while (nC--) {
        solveCase();
    }
    return 0;
}
