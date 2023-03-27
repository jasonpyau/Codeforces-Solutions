// https://codeforces.com/problemset/problem/1809/A

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
        int clrs[10] = {0};
        string input;
        cin >> input;

        for (int i = 0; i < input.size(); i++) {
            clrs[input[i]-'0']++;
        }
        int distr[5] = {0};
        for (int clr : clrs)
            distr[clr]++;

        if (distr[3] == 1)
            cout << "6\n";
        else if (distr[4] == 1)
            cout << "-1\n";
        else
            cout << "4\n";
    }

    return 0;
}
