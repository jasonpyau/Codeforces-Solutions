// https://codeforces.com/problemset/problem/1878/E

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int f(int l, int r, vector<int>& a, vector<vector<int>>& prefix_bc) {
    int res = 0;
    for (int i = 0; i < 30; ++i) {
        if ((a[l]>>i)&1 && prefix_bc[r][i]-prefix_bc[l][i] == r-l) {
            res += 1<<i;
        }
    }
    return res;
}

int search(int l, int k, vector<int>& a, vector<vector<int>>& prefix_bc) {
    int low = l, mid, res = -1, high = a.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        if (f(l, mid, a, prefix_bc) >= k) {
            // Query is one indexed.
            res = low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return res;
}

// O(q*log(n)).
void solveCase() {
    int n, q, l, k;
    cin >> n;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    // 2^30 > 10^9.
    vector<vector<int>> prefix_bc(n, vector<int>(30, 0));
    for (int i = 0; i < 30; ++i) {
        prefix_bc[0][i] = (a[0]>>i)&1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            prefix_bc[i][j] = ((a[i]>>j)&1)+prefix_bc[i-1][j];
        }
    }
    cin >> q;
    for (int q_i = 0; q_i < q; ++q_i) {
        cin >> l >> k;
        // Query is one indexed.
        cout << search(--l, k, a, prefix_bc) << " ";
    }
    cout << endl;
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
