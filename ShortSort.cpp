// https://codeforces.com/problemset/problem/1873/A

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    string s;
    cin >> s;
    int diff = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] != 'a'+i) {
            ++diff;
        }
    }
    cout << ((diff < 3) ? "YES" : "NO") << endl; 
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
