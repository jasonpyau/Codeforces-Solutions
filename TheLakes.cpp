// https://codeforces.com/contest/1829/problem/E

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> grid;

int dY[4] = {0, 1, -1, 0};
int dX[4] = {1, 0, 0, -1};

int search(int r, int c) {
    if (r < 0 || r >= grid.size()) {
        return 0;
    } else if (c < 0 || c >= grid[0].size()) {
        return 0;
    } else if (!grid[r][c]) {
        return 0;
    }
    int sum = grid[r][c];
    grid[r][c] = 0;
    for (int i = 0; i < 4; ++i) {
        sum += search(r+dY[i], c+dX[i]);
    }
    return sum;
}

void solveCase() {
    int n, m;
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, search(i, j));
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
