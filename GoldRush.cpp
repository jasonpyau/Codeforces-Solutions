// https://codeforces.com/problemset/problem/1829/D

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

bool search(int n, int m) {
    if (n == m) {
        return true;
    } else if (n%3 || !n) {
        return false;
    }
    return (search(n*2/3, m) || search(n/3, m));
}

void solveCase() {
    int n, m;
    cin >> n >> m;
    cout << ((search(n, m)) ? "YES" : "NO") << endl;
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
