// https://codeforces.com/contest/1829/problem/F

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1));
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }
    int x = 0, y = 0;
    for (int i = 1, edges; i <= n; ++i) {
        edges = 0;
        for (int j = 1; j <= n; ++j) {
            edges += graph[i][j];
        }
        if (edges == 1) {
            ++y;
        } else {
            ++x;
        }
    }
    --x;
    y /= x;
    cout << x << " " << y << endl;
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
