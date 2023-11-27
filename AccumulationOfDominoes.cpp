// https://codeforces.com/contest/1725/problem/A

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n-1 << endl;
    } else {
        cout << 1ll*(m-1)*n << endl;
    }
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
