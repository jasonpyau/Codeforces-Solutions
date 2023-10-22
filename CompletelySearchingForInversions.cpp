// https://codeforces.com/problemset/problem/1866/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 998244353;

void dfs(int vertex, vector<vector<pair<int, bool>>>& graph, vector<vector<int>>& memo, vector<bool>& vis) {
    vis[vertex] = true;
    for (int i = graph[vertex].size()-1; i >= 0; --i) {
        int l = graph[vertex][i].first;
        bool s = graph[vertex][i].second;
        if (!vis[l]) {
            dfs(l, graph, memo, vis);
        }
        // Hold number of pairs.
        memo[vertex][2] = (memo[vertex][2]+1ll*s*(memo[vertex][0]+memo[l][0])+1ll*memo[l][1]*memo[vertex][0]+memo[l][2])%MOD;
        // Hold number of zeros.
        memo[vertex][0] = (memo[vertex][0]+!s+memo[l][0])%MOD;
        // Hold number of ones.
        memo[vertex][1] = (memo[vertex][1]+s+memo[l][1])%MOD;
    }
    // cout << vertex+1 << " " << memo[vertex][0] << " " << memo[vertex][1] << " " << memo[vertex][2] << endl;
}

// O(n*s).
void solveCase() {
    int n;
    cin >> n;
    vector<vector<pair<int, bool>>> graph(n);
    vector<vector<int>> memo(n, vector<int>(3, 0));
    vector<bool> vis(n);
    for (int i = 0, s; i < n; ++i) {
        cin >> s;
        for (int j = 0, l, w; j < s; ++j) {
            cin >> l >> w;
            graph[i].push_back(make_pair(l-1, w));
        }
    }
    dfs(0, graph, memo, vis);
    cout << memo[0][2] << endl;
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
