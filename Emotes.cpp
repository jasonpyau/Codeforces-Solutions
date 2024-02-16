// https://codeforces.com/contest/1117/problem/B

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> best(3);
    for (int i = 0; i < n; ++i) {
        cin >> best[2];
        sort(best.rbegin(), best.rend());
    }
    ++k;
    cout << (m-m/k)*best[0]+(m/k)*best[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    // cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
