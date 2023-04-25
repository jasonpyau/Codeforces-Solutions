// https://codeforces.com/problemset/problem/1820/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    string s;
    cin >> s;
    int end;
    for (end = s.size()-1; end >= 0; end--) {
        if (!(s[end]-'0'))
            break;
    }
    end++;
    int max_consec = s.size()-end;
    for (int i = 0, curr = max_consec; i < end; i++) {
        if (s[i]-'0')
            curr++;
        else
            curr = 0;
        max_consec = max(max_consec, curr);
    }
    ll ans;
    if (max_consec == s.size()) {
        ans = (ll)max_consec*max_consec;
    } else {
        // Ex 5 in row: 5*1, 4*2, 3*3, 2*2, 1*1: 3*3 greatest
        // Ex 6 in row 6*1, 5*2, 4*3, 3*4, 2*5, 1*6, 4*3 greatest
        ll a = (max_consec & 1) ? (max_consec+1)>>1 : ((max_consec+1)>>1)+1;
        ll b = (max_consec+1)>>1;
        ans = a*b;
    }
    cout << ans << "\n";
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
