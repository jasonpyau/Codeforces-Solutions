// https://codeforces.com/problemset/problem/131/A

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
    string str;
    cin >> str;
    bool capOn = true;
    for (int i = 1; i < str.length(); i++)
        if (str[i] >= 'a' && str[i] <= 'z') {
            capOn = false;
            break;
        }
    if (capOn) {
        str[0] = (str[0] >= 'A' && str[0] <= 'Z') ? str[0]-'A'+'a' : str[0]-'a'+'A';
        for (int i = 1; i < str.length(); i++)
            str[i] = str[i]-'A'+'a';
    }
    cout << str << '\n';
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
