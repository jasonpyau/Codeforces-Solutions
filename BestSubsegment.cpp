// https://codeforces.com/contest/1117/problem/A

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Doesn't make sense to take anything less than the max value!
void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    int max_val = 0;
    for (int a_i : a) {
        max_val = max(max_val, a_i);
    }
    int ans = 1;
    for (int i = 1, curr = 1; i < n; ++i) {
        if (a[i] == max_val && a[i-1] == a[i]) {
            ans = max(ans, ++curr);
        } else {
            curr = 1;
        }
    }
    cout << ans << endl;
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
