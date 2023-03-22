// https://codeforces.com/problemset/problem/1360/B

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nC = 0;
    cin >> nC;
    
    for (int c = 0; c < nC; c++) {
        int n = 0;
        cin >> n;
        vector<int> aths;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            aths.push_back(s);
        }
        sort(aths.begin(), aths.end());
        int last = aths[0];
        int min = INT_MAX;
        for (int i = 1; i < aths.size(); i++) {
            if (aths[i]-last < min)
                min = aths[i]-last;
            last = aths[i];
        }
        cout << min << '\n';
    }
    
    return 0;
}
