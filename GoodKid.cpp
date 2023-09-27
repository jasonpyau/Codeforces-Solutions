// https://codeforces.com/problemset/problem/1873/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min = std::min(min, a[i]);
    }
    for (int& a_i : a) {
        if (a_i == min) {
            ++a_i;
            break;
        }
    }
    int ans = 1;
    for (int a_i : a) {
        ans *= a_i;
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
