// https://codeforces.com/contest/1725/problem/M

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 2e5*1e9+1;

void solveCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1), graph_rev(n+1);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph_rev[v].push_back(make_pair(u, w));
    }
    vector<ll> ans(n+1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    ans[1] = 0ll;
    pq.push(make_pair(0ll, 1));
    // Move left hand.
    while (!pq.empty()) {
        auto [curr_time, curr_vertex] = pq.top();
        pq.pop();
        if (curr_time != ans[curr_vertex]) {
            continue;
        }
        for (auto [next_vertex, w] : graph[curr_vertex]) {
            if (curr_time+w < ans[next_vertex]) {
                ans[next_vertex] = curr_time+w;
                pq.push(make_pair(ans[next_vertex], next_vertex));
            }
        }
    }
    // Ending vertex for right hand.
    // Basically, left hand has to meet right hand.
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != INF) {
            pq.push(make_pair(ans[i], i));
        }
    }
    // Move right hand using reversed graph.
    while (!pq.empty()) {
        auto [curr_time, curr_vertex] = pq.top();
        pq.pop();
        if (curr_time != ans[curr_vertex]) {
            continue;
        }
        for (auto [next_vertex, w] : graph_rev[curr_vertex]) {
            if (curr_time+w < ans[next_vertex]) {
                ans[next_vertex] = curr_time+w;
                pq.push(make_pair(ans[next_vertex], next_vertex));
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << ((ans[i] == INF) ? -1 : ans[i]) << " ";
    }
    cout << endl;
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
