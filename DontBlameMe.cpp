// https://codeforces.com/contest/1829/problem/H

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;

int setBits(int n) {
    int res = 0;
    while (n) {
        if (n&1) {
            ++res;
        }
        n >>= 1;
    }
    return res;
}

void solveCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    vector<vector<int>> dp(2, vector<int>(64, 0));
    for (int i = 0; i < n; ++i) {
        fill(dp[1].begin(), dp[1].end(), 0);
        for (int j = 0; j < 64; ++j) {
            // Don't take a[i].
            dp[1][j] = (dp[1][j]+dp[0][j])%MOD;
            // Take a[i].
            dp[1][a[i]&j] = (dp[1][a[i]&j]+dp[0][j])%MOD;
        }
        // Take a[i] as the start of the subsequence.
        dp[1][a[i]] = (dp[1][a[i]]+1)%MOD;
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    for (int i = 0; i < 64; ++i) {
        if (setBits(i) == k) {
            ans = (ans+dp[0][i])%MOD;
        }
    }
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
