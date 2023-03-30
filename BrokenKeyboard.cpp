// https://codeforces.com/problemset/problem/1765/B

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
    char str[len+1];
    cin >> str;
    bool ans = false;
    for (int i = 0, curr = 0; ; i++, curr++) {
        if (str[curr] == '\0') {
            ans = true;
            break;
        }
        if (i%2 == 1) {
            if (curr == len || str[curr] != str[++curr])
                break;
        }
    }
    cout << ((ans) ? "YES" : "NO") << '\n';
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
