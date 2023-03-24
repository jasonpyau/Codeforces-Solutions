// https://codeforces.com/problemset/problem/1791/A

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
    bool map[26] = {false};
    char s[] = "codeforces";
    for (char ch : s)
        map[ch-'a'] = true;
    int nC = 0;
    cin >> nC;
    
    for (int c = 0; c < nC; c++) {
        char ch;
        cin >> ch;
        cout << (map[ch-'a'] ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
