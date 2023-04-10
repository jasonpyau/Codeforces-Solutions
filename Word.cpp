// https://codeforces.com/problemset/problem/59/A

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
    string s;
    cin >> s;
    int freq[2];
    freq[0] = 0;
    freq[1] = 0;
    for (int i = 0; i < s.length(); i++) {
        freq[s[i]/'a']++;
    }
    if (freq[0] > freq[1]) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = (s[i] >= 97) ? s[i]-32 : s[i];
        }
    } else {
        for (int i = 0; i < s.length(); i++) {
            s[i] = (s[i] >= 97) ? s[i] : s[i]+32;
        }
    }
    cout << s << "\n";
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
