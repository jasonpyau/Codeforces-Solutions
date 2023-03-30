// https://codeforces.com/contest/579/problem/A

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
    int n, ans = 0;
    cin >> n;
    while (n) {
        ans += n%2;
        n >>= 1;
    }
    cout << ans << '\n';
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
