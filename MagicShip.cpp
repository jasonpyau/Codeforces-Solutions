// https://codeforces.com/contest/1117/problem/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// You can always cancel out the wind; thus it's monotonic.
inline bool valid(ll day, int dx, int dy, vector<int>& x_sum, vector<int>& y_sum, int n) {
    ll required_moves = 0;
    ll wind_x = 1ll*x_sum[n]*(day/n)+x_sum[day%n];
    ll wind_y = 1ll*y_sum[n]*(day/n)+y_sum[day%n];
    // Ex: if dx is 5, and wind_x is 5, you don't need to do anything!
    required_moves += llabs(wind_x-dx);
    required_moves += llabs(wind_y-dy);
    return (day >= required_moves);
}

ll search(int dx, int dy, vector<int>& x_sum, vector<int>& y_sum, int n) {
    // Each n days you advance one spot, worst case, if it's possible.
    ll l = 1, day, res = -1, r = n*1e9*2;
    while (r >= l) {
        day = (l+r)>>1;
        if (valid(day, dx, dy, x_sum, y_sum, n)) {
            res = day;
            // Try a earlier day.
            r = day-1;
        } else {
            l = day+1;
        }
    }
    return res;
}

inline int dx(char ch) {
    if (ch == 'L') {
        return -1;
    } else if (ch == 'R') {
        return 1;
    }
    return 0;
}

inline int dy(char ch) {
    if (ch == 'D') {
        return -1;
    } else if (ch == 'U') {
        return 1;
    }
    return 0;
}

void solveCase() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    string s;
    cin >> s;
    vector<int> x_sum(n+1), y_sum(n+1);
    for (int i = 1; i <= n; ++i) {
        x_sum[i] = x_sum[i-1]+dx(s[i-1]);
        y_sum[i] = y_sum[i-1]+dy(s[i-1]);
    }
    cout << search(x2-x1, y2-y1, x_sum, y_sum, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    // cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
