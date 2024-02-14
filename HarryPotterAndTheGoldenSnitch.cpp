// https://codeforces.com/problemset/problem/65/C

// First, find first point such that Harry Potter will reach on or before 
// snitch. Guaranteed i != 0, if Harry isn't originally on the first point.
// Then, just binary search between that point and the one before for the precise
// answer.

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

using ld = long double;
using point = array<ld, 3>;
const ld EP = 1e-12;
const int IMPOSSIBLE = -1;

// Takes two vectors in R^3.
// Returns ||b-a||.
inline ld dist(point& a, point& b) {
    ld x = b[0]-a[0], y = b[1]-a[1], z = b[2]-a[2];
    return sqrtl(x*x+y*y+z*z);
}

// Time to go to point a and b, or vice versa. D = RT.
inline ld time(point& a, point&b, int v) {
    return dist(a, b)/v;
}

bool same_point(point& a, point& b) {
    return (fabsl(b[0]-a[0]) <= EP && fabsl(b[1]-a[1]) <= EP && fabsl(b[2]-a[2]) <= EP);
}

// Point b is always our best valid point, so far.
point search(point& a, point& b, point& harry, ld total_time, int v_s, int v_p) {
    if (same_point(a, b)) {
        // Base case, we converged enough that a and b are considered "equal".
        return a;
    }
    point next_p = {(b[0]+a[0])/2.0L, (b[1]+a[1])/2.0L, (b[2]+a[2])/2.0L};
    ld new_snitch_time = total_time-time(next_p, b, v_s);
    ld new_harry_time = time(harry, next_p, v_p);
    if (new_snitch_time-new_harry_time+EP >= 0) {
        // Good point, try closer to point a!
        // Also, we need to update time from b!
        return search(a, next_p, harry, new_snitch_time, v_s, v_p);
    } else {
        // Gotta try closer to point b!
        return search(next_p, b, harry, total_time, v_s, v_p);
    }
}

// O(n*log(max(x_i^2+y_i^2+z_i^2)*(P_x^2+P_y^2+P_z^2))), with a decent constant factor.
void solveCase() {
    int n;
    cin >> n;
    vector<point> a(n+1);
    for (point& p : a) {
        cin >> p[0] >> p[1] >> p[2];
    }
    int v_p, v_s;
    point harry;
    cin >> v_p >> v_s >> harry[0] >> harry[1] >> harry[2];
    if (same_point(harry, a[0])) {
        cout << "YES" << endl;
        cout << 0.0L << endl;
        cout << harry[0] << " " << harry[1] << " " << harry[2] << endl;
        return;
    }
    int point_meet = IMPOSSIBLE;
    ld total_time = 0.0L;
    for (int i = 1; i <= n; ++i) {
        total_time += time(a[i-1], a[i], v_s);
        if (total_time-time(harry, a[i], v_p)+EP >= 0) {
            point_meet = i;
            break;
        }
    }
    if (point_meet == IMPOSSIBLE) {
        cout << "NO" << endl;
        return;
    }
    point& p_a = a[point_meet-1], &p_b = a[point_meet];
    point ans = search(p_a, p_b, harry, total_time, v_s, v_p);
    cout << "YES" << endl;
    cout << time(harry, ans, v_p) << endl;
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    int nC = 1;
    // cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
