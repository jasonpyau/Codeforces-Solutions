// https://codeforces.com/problemset/problem/1833/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

bool tempCompareTo(pair<int, int>& lhs, pair<int, int>& rhs) {
    return (rhs.second > lhs.second);
}

void solveCase() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(make_pair(i, temp));
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), tempCompareTo);
    sort(b.begin(), b.end());
    vector<int> b_solved(n);
    for (int i = 0; i < n; i++) {
        b_solved[a[i].first] = b[i];
    }
    for (int ans : b_solved) {
        cout << ans << " ";
    }
    cout << "\n";
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
