// https://codeforces.com/problemset/problem/1925/D

// Derivation of solution: https://www.overleaf.com/read/vfrhbtcyjcjh#d7c59e

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

using friend_pair = array<int, 3>;
const int MAX_FACT = 2e5;
const int MOD = 1e9+7;
int fact[MAX_FACT+1], inv_fact[MAX_FACT+1];
 
int add(int a, int b) {
    if (a+b >= MOD) {
        return a+b-MOD;
    }
    return a+b;
}
 
int sub(int a, int b) {
    if (b > a) {
        return a-b+MOD;
    }
    return a-b;
}
 
int mult(int a, int b) {
    return 1ll*a*b%MOD;
}
 
int pow(int n, int e) {
    if (!e) {
        return 1;
    } else if (e&1) {
        return mult(n, pow(n, e-1));
    } else {
        int srt = pow(n, e>>1);
        return mult(srt, srt);
    }
}
 
int inv(int n) {
    // Fermat's little theorem for prime modulo.
    return pow(n, MOD-2);
}
 
int nCr(int n, int r) {
    if (n-r < 0) {
        return 0;
    }
    return mult(fact[n], mult(inv_fact[r], inv_fact[n-r]));
}

int binompdf(int n, int p, int x) {
    return mult(nCr(n, x), mult(pow(p, x), pow(sub(1, p), sub(n, x))));
}

const int INV_2 = inv(2);

int arith_series(int a_1, int a_n, int n) {
    return mult(mult(n, add(a_1, a_n)), INV_2);
}
 
// O(MAX_N).
void setUp() {
    // Pre calculate factorials. 
    fact[0] = 1;
    for (int i = 1; i <= MAX_FACT; ++i) {
        fact[i] = mult(fact[i-1], i);
    }
    inv_fact[MAX_FACT] = inv(fact[MAX_FACT]);
    for (int i = MAX_FACT-1; i >= 0; --i) {
        inv_fact[i] = mult(inv_fact[i+1], i+1);
    }
}

// O(m+k*log(k)).
void solveCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<friend_pair> friend_pairs(m);
    for (friend_pair& f : friend_pairs) {
        cin >> f[0] >> f[1] >> f[2];
    }
    int e_1 = 0, p = inv(arith_series(n-1, 0, n));
    for (friend_pair& f : friend_pairs) {
        e_1 = add(e_1, f[2]);
    }
    e_1 = mult(e_1, mult(k, p));
    int d = 0;
    for (int i = 0; i < k; ++i) {
        d = add(d, mult(arith_series(0, i, i+1), binompdf(k, p, i+1)));
    }
    int e_2 = mult(m, d);
    int e = add(e_1, e_2);
    cout << e << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setUp();
    int nC = 1;
    cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
