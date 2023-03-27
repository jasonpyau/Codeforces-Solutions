// https://codeforces.com/problemset/problem/1807/C

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
        string s;
        cin >> s;
        int cmap[26];
        for (int i = 0; i < 26; i++)
            cmap[i] = -1;
        bool ans = true;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            int j = ch-'a';
            if (cmap[j] == -1) {
                cmap[j] = (last == 0) ? 1 : 0;
                last = cmap[j];
                continue;
            }
            if (last == 0) {
                if (cmap[j] != 1) {
                    ans = false;
                    break;
                }
                last = 1;
            } else {
                if (cmap[j] != 0) {
                    ans = false;
                    break;
                }
                last = 0;
            }
        }

        cout << ((ans) ? "YES" : "NO") << '\n';

    }

    return 0;
}
