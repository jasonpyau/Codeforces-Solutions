// https://codeforces.com/contest/1872/problem/F

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n;
    cin >> n;
    ++n;
    vector<int> a(n), c(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> depend(n);
    for (int i = 1; i < n; ++i) {
        depend[a[i]] += c[i];
    }
    set<pair<ll, int>> s;
    vector<bool> used(n, false);
    for (int i = 1; i < n; ++i) {
        s.insert(make_pair(depend[i], i));
    }
    vector<int> ans;
    for (int i = 1; i < n; ++i) {
        pair<ll, int> min_animal = *s.begin();
        int scared_ind = a[min_animal.second];
        ll& scared_cost = depend[scared_ind];
        if (!used[scared_ind]) {
            s.erase(make_pair(scared_cost, scared_ind));
            scared_cost -= c[min_animal.second];
            s.insert(make_pair(scared_cost, scared_ind));
        }
        ans.push_back(min_animal.second);
        used[min_animal.second] = true;
        s.erase(min_animal);
    }
    for (int an : ans) {
        cout << an << " ";
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
