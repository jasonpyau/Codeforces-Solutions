// https://codeforces.com/contest/1782/problem/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Idea is check every pair (a_i, a_j).
// a_i+x = n_1^2, a_j+x = n_2^2, where n_1, n_2 in Z+, n_2 > n_1.
// -> (n_2+n_1)(n_2-n_1) = a_j-a_i.
// -> (n_2-n_1)|(a_j-a_i).
// Let n_2-n_1 = d.
// -> 2n_2 = (a_j-a_i)/d+d.
// -> 2n_1 = (a_j-a_i)/d-d.

ll sqrt_floor(ll n) {
    ll low = 0, mid, res = 0, high = 1e9;
    while (high >= low) {
        mid = (low+high)>>1;
        if (mid*mid > n) {
            high = mid-1;
        } else {
            low = mid+1;
            res = mid;
        }
    }
    return res;
}

bool good(ll n) {
    ll sq = sqrt_floor(n);
    return (sq*sq == n);
}

// O(n^3*sqrt(max(a_i))).
void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<ll> seen;
    for (int& a_i : a) {
        cin >> a_i;
    }
    vector<ll> candidates;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int diff = a[j]-a[i];
            for (int d = 1; d*d <= diff; ++d) {
                if (diff%d) {
                    continue;
                } else if ((diff/d-d)%2 || (diff/d+d)%2) {
                    continue;
                }
                int n_2 = (diff/d+d)>>1;
                ll x = 1ll*n_2*n_2-a[j];
                if (x >= 0 && !seen.count(x)) {
                    candidates.push_back(x);
                }
                seen.insert(x);
            }
        }
    }
    int ans = 1;
    for (ll candidate : candidates) {
        for (int i = 0, freq = 0; i < n; ++i) {
            if (good(a[i]+candidate)) {
                if (++freq > ans) {
                    ans = freq;
                }
            }
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
