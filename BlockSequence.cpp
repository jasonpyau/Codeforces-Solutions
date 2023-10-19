// https://codeforces.com/problemset/problem/1881/E

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INIT = -1, IMPOSSIBLE = 2e5+1;

// O(n).
int solve(int i, vector<int>& a, vector<int>& memo) {
    if (i >= a.size()) {
        return (i == a.size()) ? 0 : IMPOSSIBLE;
    } else if (memo[i] != INIT) {
        return memo[i];
    }
    int no_rm = solve(i+a[i]+1, a, memo);
    int rm = 1+solve(i+1, a, memo);
    return memo[i] = min(no_rm, rm);
}

void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n), memo(n, INIT);
    for (int& a_i : a) {
        cin >> a_i;
    }
    cout << solve(0, a, memo) << endl;
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
