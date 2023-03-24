// https://codeforces.com/problemset/problem/1791/C

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
        char s[2001];
        cin >> s;
        
        int ans = len;
        for (int i = 0; i < len/2; i++) {
            if (s[i]+s[len-i-1]-2*'0' != 1)
                break;
            else
                ans -= 2;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
