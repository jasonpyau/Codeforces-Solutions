// https://codeforces.com/problemset/problem/1806/A

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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ydif = y2-y1;
        int ans = (x1+ydif >= x2 && ydif >= 0) ? x1+ydif*2-x2 : -1;
        cout << ans << '\n';
    }
    
    return 0;
}
