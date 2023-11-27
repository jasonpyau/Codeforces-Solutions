// https://codeforces.com/contest/1725/problem/B

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (int& p_i : p) {
        cin >> p_i;
    }
    sort(p.begin(), p.end());
    int l = 0, r = n-1, ans = 0;
    // while (r >= 0 && p[r] > d) {
    //     --r, ++ans;
    // }
    while (r >= l) {
        // Overflow impossible for all p_sum.
        int p_sum = p[r];
        while (r > l && p_sum <= d) {
            p_sum += p[r];
            ++l;
        }
        --r;
        ans += (p_sum > d);
    }
    cout << ans;
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
