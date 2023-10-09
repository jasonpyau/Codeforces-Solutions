// https://codeforces.com/problemset/problem/1869/B

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static inline ll cost(pair<int, int>& a, pair<int, int>& b) {
    return llabs(b.first-a.first)+llabs(b.second-a.second);
}

void solveCase() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    --a, --b;
    vector<pair<int, int>> cities(n);
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        cities[i] = make_pair(x, y);
    }
    ll ans = cost(cities[a], cities[b]), major_a = 4e9, major_b = 4e9;
    for (int i = 0; i < k; ++i) {
        major_a = min(major_a, cost(cities[a], cities[i]));
        major_b = min(major_b, cost(cities[b], cities[i]));
    }
    ans = min(ans, major_a+major_b);
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
