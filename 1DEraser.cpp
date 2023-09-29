// https://codeforces.com/contest/1873/problem/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i < n;) {
        if (s[i] == 'B') {
            ++ans;
            i += k;
        } else {
            ++i;
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
