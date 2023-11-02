// https://codeforces.com/problemset/problem/1879/D

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 998244353;

// O(n).
void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    int ans = 0;
    // 2^30 > 10^9.
    for (int i = 0; i < 30; ++i) {
        int delta_i[2] = {0}, delta_s[2] = {0};
        for (int j = 0; j < n; ++j) {
            bool bit = (a[j]>>i)&1;
            // All newly generated intervals will be XORed (flipped) from the prev.
            if (bit) {
                swap(delta_i[0], delta_i[1]);
                swap(delta_s[0], delta_s[1]);
            }
            // One extra interval will be generated each time.
            ++delta_i[bit];
            // Each newly generated interval will be of length of the prev
            // newly generated interval+1. (ex: {(1,2),(2,2)} -> {(1,3),(2,3),(3,3)}).
            delta_s[0] = (delta_s[0]+delta_i[0])%MOD;
            delta_s[1] = (delta_s[1]+delta_i[1])%MOD;
            // Update answer with the sum of lengths of the newly generated intervals 
            // whose XOR is 1.
            ans = (ans+1ll*(delta_s[1])*(1<<i))%MOD;
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
