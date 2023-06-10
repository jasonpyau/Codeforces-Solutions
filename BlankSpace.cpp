// https://codeforces.com/problemset/problem/1829/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0, curr = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        if (a_i == 0) {
            curr++;
            ans = max(ans, curr);
        } else {
            curr = 0;
        }
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
