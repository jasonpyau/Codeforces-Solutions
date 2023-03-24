// https://codeforces.com/problemset/problem/1780/A

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
        vector<int> even;
        vector<int> odd;
        bool ans = false;
        int ind[3] = {0};
        for (int i = 0; i < len; i++) {
            int input = 0;
            cin >> input;
            if (input % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
                
            if (odd.size() >= 3) {
                for (int j = 0; j < 3; j++)
                    ind[j] = odd[j];
                ans = true;
            } else if (odd.size() >= 1 && even.size() >= 2) {
                ind[0] = even[0];
                ind[1] = even[1];
                ind[2] = odd[0];
                ans = true;
            }
        }
        cout << (ans? "YES\n" : "NO");
        for (int j = 0; j < 3 && ans; j++)
            cout << ind[j]+1 << ' ';
        cout << '\n';
    }
    
    return 0;
}
