// https://codeforces.com/contest/1763/problem/A

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
    int len;
    cin >> len;
    int a[len];
    for (int i = 0; i < len; i++) {
        int input;
        cin >> input;
        a[i] = input;
    }
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < len; i++) {
        max |= a[i];
        min &= a[i];
    }
    cout << max-min << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    while (nC--) {
        solveCase();
    }
    return 0;
}
