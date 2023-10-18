// https://codeforces.com/problemset/problem/1886/B

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const double EP = 1e-6;

int p_x, p_y, a_x, a_y, b_x, b_y;

static inline double distance(int x_1, int y_1, int x_2, int y_2) {
    double a = x_2-x_1, b = y_2-y_1, c = sqrt(a*a+b*b);
    return c;
}

static inline bool inside(int x, int y, int c_x, int c_y, double r) {
    return (r >= distance(c_x, c_y, x, y));
}

double solve(double low, double high) {
    double r = (low+high)/2.0;
    if (high-low < EP) {
        return r;
    }
    bool home_in_a = inside(0, 0, a_x, a_y, r), home_in_b = inside(0, 0, b_x, b_y, r);
    bool p_in_a = inside(p_x, p_y, a_x, a_y, r), p_in_b = inside(p_x, p_y, b_x, b_y, r);
    bool valid = false;
    valid |= (home_in_a && p_in_a);
    valid |= (home_in_b && p_in_b);
    valid |= (home_in_a|home_in_b && p_in_a|p_in_b && inside(a_x, a_y, b_x, b_y, 2.0*r));
    if (valid) {
        return solve(low, r);
    } else {
        return solve(r, high);
    }
}

void solveCase() {
    cin >> p_x >> p_y >> a_x >> a_y >> b_x >> b_y;
    cout << solve(EP, 1e7) << endl;
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
