// https://codeforces.com/contest/1873/problem/E

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll low = 1, mid, ans, high = 2e9;
    while (low <= high) {
        mid = (low+high)>>1;
        int total_water = x;
        for (int i = 0; i < n && mid > a[i]; ++i) {
            total_water -= mid-a[i];
            if (total_water < 0) {
                break;
            }
        }
        if (total_water >= 0) {
            ans = mid;
            low = mid+1;
            if (!total_water) {
                break;
            }
        } else {
            high = mid-1;
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
