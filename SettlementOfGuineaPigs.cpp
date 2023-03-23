// https://codeforces.com/problemset/problem/1802/B

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
        vector<int> days;
        for (int i = 0; i < len; i++) {
            int input;
            cin >> input;
            days.push_back(input);
        }
        int upigs = 0, gpigs = 0, cages = 0, cages_needed = 0;
        for (int day : days) {
            if (day == 1) {
                upigs++;
                cages_needed++;
                
            } else if (day == 2) {
                gpigs += upigs;
                upigs = 0;
                cages_needed = (gpigs == 0) ? 0 : gpigs/2+1;
            }
            if (cages_needed > cages)
                cages = cages_needed;
        }
        cout << cages << '\n';
    }
    
    return 0;
}
