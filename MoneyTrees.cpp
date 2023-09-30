// https://codeforces.com/contest/1873/problem/F

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), h(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int curr_fruits = a[0], ans = (curr_fruits <= k);
    for (int l = 0, r = 1; r < n; ++r) {
        if (h[r-1]%h[r]) {
            curr_fruits = 0;
            l = r;
        }
        curr_fruits += a[r];
        if (curr_fruits > k) {
            while (r >= l && curr_fruits > k) {
                curr_fruits -= a[l++];
            }
        }
        ans = max(ans, r-l+1);
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
