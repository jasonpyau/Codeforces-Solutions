// https://codeforces.com/contest/1462/problem/E2

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 2e5;
const int MOD = 1e9+7;
int fact[MAX_N+1], inv_fact[MAX_N+1];

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

// O(MAX_N).
void setUp() {
    // Pre calculate factorials. 
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = mult(fact[i-1], i);
    }
    inv_fact[MAX_N] = inv(fact[MAX_N]);
    for (int i = MAX_N-1; i >= 0; --i) {
        inv_fact[i] = mult(inv_fact[i+1], i+1);
    }
}

// Returns the maximum r such that a[r]-a[l] <= k.
int search(int l, vector<int>& a, int k) {
    int low = l, mid, res = l, high = a.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        if (a[mid]-a[l] <= k) {
            res = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return res;
}

// O(n*log(n)).
void solveCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int l = 0, r, last_r; l < n; ++l) {
        r = search(l, a, k);
        // Add up all possible combinations from [l,r].
        ans = add(ans, nCr(r-l+1, m));
        // Subtract out all previously added combinations.
        if (l) {
            ans = sub(ans, nCr(last_r-l+1, m));
        }
        last_r = r;
    }
    cout << ans << endl;
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
