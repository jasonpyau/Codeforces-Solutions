// https://codeforces.com/problemset/problem/1891/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// In general, we can say g(x) is an increasing function.
// However, with flooring, we need to check the area around where x = 2^n.
// Ex: g(7) = 2, g(8) = 1 is a special case.
// It can be shown the max value for g(x) is 10 where x <= 10^18.

const int MOD = 1e9+7;

vector<pair<ll, ll>> specials(11, {-1, -1});
// intervals.first -> interval, intervals.second -> val.
vector<pair<pair<ll, ll>, int>> intervals;

// O(1).
void solveCase() {
    ll l, r;
    cin >> l >> r;
    int ans = 0, sum_special = 0;
    for (pair<pair<ll, ll>, int>& interval : intervals) {
        int dist = max(0ll, min(r, interval.first.second)-max(l, interval.first.first)+1)%MOD;
        ans = (ans+1ll*dist*interval.second)%MOD;
    }
    for (pair<ll, ll>& special : specials) {
        int dist = max(0ll, min(r, special.second)-max(l, special.first)+1)%MOD;
        sum_special = (sum_special+dist)%MOD;
    }
    if (sum_special > ans) {
        cout << MOD-sum_special+ans << endl;
    } else {
        cout << ans-sum_special << endl;
    }
}

int g(ll x) {
    __int128 temp = 2;
    ll log_2x = 0;
    // Find log_2(x).
    while (x >= temp) {
        temp <<= 1;
        ++log_2x;
    }
    int res = 0;
    temp = log_2x;
    // Find g.
    while (x >= temp) {
        temp *= log_2x;
        ++res;
    }
    return res;
}

bool in_specials(ll x, int val) {
    return (x >= specials[val].first && x <= specials[val].second);
}

ll search(ll l, ll h, ll target, bool upper) {
    ll low = l, res = low, mid, high = h;
    while (high >= low) {
        mid = low+(high-low)/2;
        int val = g(mid);
        if ((val == target && !in_specials(mid, target)) || in_specials(mid, target-1)) {
            res = mid;
            if (upper) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        } else if (val > target || in_specials(mid, target)) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return res;
}

void find_specials() {
    // 2^60 > 10^18.
    for (int i = 3; i <= 59; ++i) {
        ll sq = 1ll<<i, val = g(sq);
        if (g(sq-1) > val) {
            specials[val].first = sq;
            specials[val].second = search(sq, 1e18, val, true);
        }
    }
}

void setUp() {
    find_specials();
    for (int i = 2; i <= 9; ++i) {
        ll low = search(4, 1e18, i, false);
        ll high = search(4, 1e18, i, true);
        intervals.push_back(make_pair(make_pair(low, high), i));
    }
    intervals.push_back(make_pair(make_pair(intervals.back().first.second+1, 1e18), 10));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    setUp();
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
