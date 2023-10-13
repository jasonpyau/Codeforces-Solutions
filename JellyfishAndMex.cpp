// https://codeforces.com/problemset/problem/1875/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INIT = -1, MAX = 5e3;
vector<int> freq(MAX+1), memo(MAX+1, INIT);

// O(n^2), max you can fill memo is n times, each time does n work.
int solve(int mex) {
    if (memo[mex] != INIT) {
        return memo[mex];
    }
    int best = INT_MAX;
    for (int i = 0; i < mex; ++i) {
        int cost = max(0, freq[i]-1)*mex+i;
        best = min(best, cost+solve(i));
    }
    return memo[mex] = best;
}

void solveCase() {
    int n;
    cin >> n;
    fill(freq.begin(), freq.end(), 0);
    fill(memo.begin(), memo.end(), INIT);
    memo[0] = 0;
    for (int i = 0, a_i; i < n; ++i) {
        cin >> a_i;
        if (a_i <= MAX) {
            ++freq[a_i];
        }
    }
    int mex;
    for (int i = 0; i < freq.size(); ++i) {
        if (!freq[i]) {
            mex = i;
            break;
        }
    }
    cout << solve(mex) << endl;
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
