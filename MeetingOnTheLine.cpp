// https://codeforces.com/problemset/problem/1730/B

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const double EP = 1e-6;

double solve(double low, double high, vector<pair<int, int>>& p) {
    double mid = (low+high)/2.0;
    if (high-low < EP) {
        return mid;
    }
    int i;
    double l_max = -1, r_max = -1;
    for (i = 0; i < p.size() && p[i].first < mid; ++i) {
        l_max = max(l_max, mid-p[i].first+p[i].second);
    }
    for (; i < p.size(); ++i) {
        r_max = max(r_max, 0.0+p[i].first-mid+p[i].second);
    }
    if (l_max > r_max) {
        return solve(low, mid, p);
    } else {
        return solve(mid, high, p);
    }
}

void solveCase() {
    int n;
    cin >> n;
    // first: x, second: t.
    vector<pair<int, int>> p(n);
    for (pair<int, int>& p_i : p) {
        cin >> p_i.first;
    }
    for (pair<int, int>& p_i : p) {
        cin >> p_i.second;
    }
    sort(p.begin(), p.end());
    cout << solve(p[0].first, p.back().first, p) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    cout << fixed << setprecision(7);
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
