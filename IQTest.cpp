// https://codeforces.com/problemset/problem/25/A

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
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    int freq[2];
    freq[0] = 0;
    freq[1] = 0;
    for (int i = 0; i < 3; i++) {
        freq[arr[i]%2]++;
    }
    bool checkEven = (freq[0] > freq[1]);
    for (int i = 0; i < len; i++) {
        if (checkEven && arr[i] % 2 == 1) {
            cout << i+1 << '\n';
            break;
        } else if (!checkEven && arr[i] % 2 == 0) {
            cout << i+1 << '\n';
            break;
        }
    }
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
