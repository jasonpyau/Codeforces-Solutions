// https://codeforces.com/problemset/problem/1791/E

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
        vector<ll> a;
        for (int i = 0; i < len; i++) {
            ll input;
            cin >> input;
            a.push_back(input);
        }
        ll min = LLONG_MAX, ans = 0;
        int negs = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] <= 0)
                negs++;
            if (abs(a[i]) < min)
                min = abs(a[i]);
            ans += abs(a[i]);
        }
        ans -= (negs % 2 == 1) ? min*2 : 0;
            
        cout << ans << '\n';
    }
    
    return 0;
}
