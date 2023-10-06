// https://codeforces.com/problemset/problem/1862/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static inline ll sum(ll n) {
    // {1,2} -> 1
    // {1,2,3} -> 3
    // {1,2,3,4} -> 6...
    // 1+2+3+4+...+n-1
    --n;
    return (n*(1+n))>>1;
}

void solveCase() {
    ll n;
    cin >> n;
    ll low = 1, mid, curr, high = 2648956421;
    pair<ll, ll> ans;
    while (high >= low) {
        mid = (low+high)>>1;
        curr = sum(mid);
        if (curr <= n) {
            ans = make_pair(mid, curr);
            if (curr == n) {
                break;
            }
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    // {1,2,3,4} -> 6
    // {1,1,2,3,4} -> 7
    // {1,1,2,2,3,4} -> 8...
    // Do this until we can get the optimal n unique balls.
    ans.first += n-ans.second;
    cout << ans.first << endl;
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
