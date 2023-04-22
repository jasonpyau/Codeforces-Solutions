// https://codeforces.com/problemset/problem/1821/B

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
    vector<int> a_p(len);
    for (int i = 0; i < len; i++)
        cin >> a[i];
    for (int i = 0; i < len; i++)
        cin >> a_p[i];
    int l_ans = 0, r_ans = 0;
    bool has_diff = (a_p[0] != a[0]);
    for (int i = 1, l = 0, r = 0; i < len; i++) {
        if (a_p[i-1] <= a_p[i]) {
            r = i;
            if (a_p[i] != a[i])
                has_diff = true;
            if (r-l > r_ans-l_ans && has_diff) {
                l_ans = l;
                r_ans = r;
            }
        } else {
            has_diff = false;
            l = i;
            r = i;
        }
    }
    cout << l_ans+1 << " " << r_ans+1 << "\n";
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
