// https://codeforces.com/problemset/problem/1821/A

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    string s;
    int ans = 1;
    cin >> s;
    int i = 0;
    for (; i < s.size(), s[i] == '0'; i++);
    if (i) {
        cout << "0\n"; 
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?')
            ans *= (i == 0) ? 9 : 10;
    }
    cout << ans << '\n';
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
