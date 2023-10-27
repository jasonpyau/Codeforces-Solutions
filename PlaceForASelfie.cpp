// https://codeforces.com/problemset/problem/1805/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct quad {
    int a;
    int b;
    int c;
};

// If (b-k)^2-4ac < 0, it is good.
// -> 4ac > (b-k)^2
// -> k < b+sqrt(4ac), k > b-sqrt(4ac)
int search(quad& qd, vector<int>& l) {
    double lower = qd.b-sqrt(4ll*qd.a*qd.c);
    double upper = qd.b+sqrt(4ll*qd.a*qd.c);
    int low = 0, mid, high = l.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        if (l[mid] >= upper) {
            high = mid-1;
        } else if (l[mid] <= lower) {
            low = mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

// O(m*(log(n)+log(4ac))).
void solveCase() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    for (int& k : l) {
        cin >> k;
    }
    vector<quad> q(m);
    for (quad& qd : q) {
        cin >> qd.a >> qd.b >> qd.c;
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < m; ++i) {
        int ans = (q[i].c > 0) ? search(q[i], l) : -1;
        if (ans == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << l[ans] << endl;
        }
    }
    cout << endl;
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
