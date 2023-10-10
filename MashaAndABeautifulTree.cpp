// https://codeforces.com/problemset/problem/1741/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> p;
int ans;

bool sort(int start, int n) {
    if (n == 1) {
        return true;
    }
    int mid = n>>1, min = INT_MAX, max = 0;
    for (int i = 0; i < mid; ++i) {
        min = std::min(min, p[start+i]);
        max = std::max(max, p[start+i]);
    }
    if (min == start+1 && max == start+mid) {
        // Good, no need to do anything
    } else if (min == start+mid+1 && max == start+n) {
        ++ans;
        for (int i = 0; i < mid; ++i) {
            swap(p[start+i], p[start+mid+i]);
        }
    } else {
        ans = -1;
        return false;
    }
    return (sort(start, mid) && sort(start+mid, mid));
}

void solveCase() {
    int m;
    cin >> m;
    ans = 0;
    p.clear();
    p = vector<int>(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    sort(0, m);
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
