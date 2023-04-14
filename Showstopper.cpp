// https://codeforces.com/problemset/problem/1798/A

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
    vector<int> a(len);
    vector<int> b(len);
    for (int i = 0; i < len; i++)
        cin >> a[i];
    for (int i = 0; i < len; i++)
        cin >> b[i];
    int max = std::max(a[len-1], b[len-1]);
    int min = std::min(a[len-1], b[len-1]);
    bool ans = true;
    for (int i = 0; i < len-1 && ans; i++) {
        if (std::max(a[i], b[i]) <= max && std::min(a[i], b[i]) <= min) {
            continue;
        }
        ans = false;
    }
    cout << ((ans) ? "Yes" : "No") << "\n";
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
