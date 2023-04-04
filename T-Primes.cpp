// https://codeforces.com/problemset/problem/230/B

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

bool perf(ll sq, ll num) {
    return (sq*sq == num);
}

void solveCase() {
    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        ll num;
        cin >> num;
        bool ans = false;
        ll sq = sqrt(num);
        ans = perf(sq, num);
        if (ans) {
            ll sqsq = sqrt(sq);
            if (num == 1)
                ans = false;
            for (ll i = 2; i <= sqsq; i++) {
                if (sq % i == 0) {
                    ans = false;
                    break;
                }
            }
        }
        cout << ((ans) ? "YES" : "NO") << '\n';
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
