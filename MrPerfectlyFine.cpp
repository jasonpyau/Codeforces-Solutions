// https://codeforces.com/problemset/problem/1829/C

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

const int MAX_M = 2e5+1;
void solveCase() {
    int n;
    cin >> n;
    int min_01 = MAX_M, min_10 = MAX_M, min_11 = MAX_M;
    for (int i = 0; i < n; i++) {
        int m;
        string s;
        cin >> m >> s;
        if (s == "01") {
            min_01 = min(m, min_01);
        } else if (s == "10") {
            min_10 = min(m, min_10);
        } else if (s == "11") {
            min_11 = min(m, min_11);
        }
    }
    int ans;
    if (min_01 == MAX_M || min_10 == MAX_M) {
        if (min_11 == MAX_M) {
            ans = -1;
        } else {
            ans = min_11;
        }
    } else if (min_11 == MAX_M) {
        ans = min_01+min_10;
    } else {
        ans = min(min_01+min_10, min_11);
    }
    cout << ans << "\n";
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
