// https://codeforces.com/problemset/problem/1809/B

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
        ll input;
        cin >> input;
        int min = 0, max = (int)1e9;
        while (max >= min) {
            ll mid = (max+min)/2;
            ll sq = (mid+1)*(mid+1);
            if (sq < input)
                min = mid+1;
            else
                max = mid-1;
        }
        cout << min << '\n';

    }

    return 0;
}
