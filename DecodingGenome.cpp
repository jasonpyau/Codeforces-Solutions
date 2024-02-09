// https://codeforces.com/contest/222/problem/E

// n = 2, m = 3, no a->b.
// aa, ac, ba, bb, bc, ca, cb, cc.
// For n = 3, all good, but can't add b to those starting with a.
// One solution: dp[n][m]. However, n <= 10^15.
// Let's consider a linear system of the linear recurrence:
// a_n = a_(n-1)+b_(n-1)+c_(n-1).
// b_n = b_(n-1)+c(n-1).
// c_n = a_(n-1)+b_(n-1)+c_(n-1).
// Now, just use Ax = b. Also, when n = 1, each letter always has 1.
// We have:
// | 1 1 1 |^(n-1)     | 1 |   | a_n |
// | 0 1 1 |         * | 1 | = | b_n |
// | 1 1 1 |           | 1 |   | c_n |
// We can easily generalize this.

// O(log(n)*m^3).
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;

inline int add(int a, int b) {
    if (a+b >= MOD) {
        return a+b-MOD;
    }
    return a+b;
}

inline int mult(int a, int b) {
    return int(1ll*a*b%MOD);
}

vector<vector<int>> mat_identity(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    return res;
}

vector<vector<int>> mat_mult(vector<vector<int>> a, vector<vector<int>> b) {
    assert(a[0].size() == b.size());
    int m = a.size(), n = a[0].size(), p = b[0].size();
    vector<vector<int>> res(m, vector<int>(p, 0));
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < p; ++c) {
            for (int i = 0; i < n; ++i) {
                res[r][c] = add(res[r][c], mult(a[r][i], b[i][c]));
            }
        }
    }
    return res;
}

vector<vector<int>> mat_pow(vector<vector<int>> a, ll e) {
    assert(a.size() == a[0].size());
    assert(e >= 0);
    vector<vector<int>> res = mat_identity(a.size());
    while (e) {
        if (e&1) {
            res = mat_mult(res, a);
        }
        a = mat_mult(a, a);
        e >>= 1;
    }
    return res;
}

inline int map_A(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch-'a';
    }
    return ch-'A'+26;
}

void solveCase() {
    ll n;
    int m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(m, vector<int>(m, 1)), x(m, vector<int>(1, 1));
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        char u = s[0], v = s[1];
        A[map_A(v)][map_A(u)] = 0;
    }
    vector<vector<int>> b = mat_mult(mat_pow(A, n-1), x);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = add(ans, b[i][0]);
    }
    cout << ans << endl;
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
