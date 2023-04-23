// https://codeforces.com/problemset/problem/1501/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    int len;
    cin >> len;
    vector<int> a(len);
    vector<bool> ans(len, false);
    for (int i = 0; i < len; i++)
        cin >> a[i];
    for (int i = 0; i < len; i++) {
        if (a[i] != 0) {
            ans[i] = true;
            int back = a[i]-2;
            for (int j = i-1; j >= 0 && back >= 0; j--, back--) {
                ans[j] = true;
                if (a[j]) {
                    back -= a[j]-1;
                    j -= a[j]-1;
                }
            }
        }
    }
    for (bool an : ans)
        cout << an << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    while (nC--) {
        solveCase();
    }
    return 0;
}
