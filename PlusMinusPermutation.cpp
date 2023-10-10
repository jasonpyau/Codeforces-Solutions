// https://codeforces.com/problemset/problem/1872/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll common = n/lcm(x,y);
    ll n_x = n/x-common, a_1x = n-n_x+1, a_nx = n;
    ll n_y = n/y-common, a_1y = 1, a_ny = n_y;
    ll ans = ((n_x*(0ll+a_1x+a_nx))>>1)-((n_y*(0ll+a_1y+a_ny))>>1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
