// https://codeforces.com/problemset/problem/1842/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 2e5+1;

void solveCase() {
    int n;
    cin >> n;
    // dp[i] will hold number of balls not removed at a[i-1].
    // dp[n+1] will be INF.
    // last will init to n+2 since we will always access last-1 for the dp.
    vector<int> a(n), dp(n+2, 0), last(n+1, n+2);
    dp[n+1] = INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i-1]+1, dp[last[a[i-1]]-1]);
        if (dp[i-1] < dp[last[a[i-1]]-1]) {
            last[a[i-1]] = i;
        }
    }
    cout << n-dp[n] << endl;
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
