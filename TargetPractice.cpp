// https://codeforces.com/contest/1873/problem/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> grid(10, vector<int>(10));

void fill_grid(int val, int u, int d, int l, int r) {
    if (u > d || l > r) {
        return;
    }
    for (int i = l; i <= r; ++i) {
        grid[u][i] = val;
    }
    for (int i = l; i <= r; ++i) {
        grid[d][i] = val;
    }
    for (int i = u; i <= d; ++i) {
        grid[i][l] = val;
    }
    for (int i = u; i <= d; ++i) {
        grid[i][r] = val;
    }
    fill_grid(val+1, u+1, d-1, l+1, r-1);
}

void solveCase() {
    string in[10];
    for (int i = 0; i < 10; ++i) {
        cin >> in[i];
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (in[i][j] == 'X') {
                ans += grid[i][j];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    fill_grid(1, 0, grid.size()-1, 0, grid[0].size()-1);
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
