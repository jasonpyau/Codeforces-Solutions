// https://codeforces.com/contest/1117/problem/D

// f(7, 3):
// [1,1,1,1,1,1,1] -> nCr(7, 0) = 1.
// [1,1,1,1,1] -> nCr(5,1) = 5.
// [1,1,1] -> nCr(3,2) = 3.
// f(9, 3):
// nCr(9,0)+nCr(7,1)+nCr(5,2)+nCr(3,3) = 325.
// However, can’t compute this faster than O(N+M), where N <= 10^18!

// We can use dp. Take the last, add a magic gem and don't split -> f(n-1, m).
// Can split that newly added magic gem -> f(n-m, m).

// f(n, m) = f(n-1, m)+f(n-m, m)
// f(n-1, m) = f(n-1, m)
// …
// f(n-m, m) = f(n-m, m)

// f(m, m) = 1
// f(m-1, m) = 1
// …
// f(0, m) = 0
// Set up the recurrence relation and solve Ax = b.

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

// O(m^3*log(n-m)).
void solveCase() {
    ll n;
    int m;
    cin >> n >> m;
    if (n-m+1 < 0) {
        cout << 1 << endl;
        return;
    }
    vector<vector<int>> A(m+1, vector<int>(m+1, 0));
    A[0][0] = A[0][m-1] = 1;
    for (int i = 0; i < m; ++i) {
        A[i+1][i] = 1;
    }
    vector<vector<int>> x(m+1, vector<int>(1, 1));
    x[0][m] = 0;
    vector<vector<int>> b = mat_mult(mat_pow(A, n-m+1), x);
    cout << b[0][0] << endl;
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
