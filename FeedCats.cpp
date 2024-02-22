// https://codeforces.com/problemset/problem/1932/F

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// https://codeforces.com/blog/entry/18051
// Modified Segment/Interval tree.
// Find the next start point if we take a given point.
struct tree1 {
    vector<int> tree;
    int n;
    
    tree1(int n) {
        this->tree = vector<int>(2*n);
        this->n = n;
    }
    
    // [l, r).
    void modify(int l, int r, int value) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) tree[l] = max(tree[l], value), ++l;
            if (r&1) --r, tree[r] = max(tree[r], value);
        }
    }
    
    int query(int p) {
        int res = 0;
        for (p += n; p > 0; p >>= 1) {
            res = max(res, tree[p]);
        }
        return res;
    }
};

// Num of intervals containing a given point (assuming value always = 1).
struct tree2 {
    vector<int> tree;
    int n;
    
    tree2(int n) {
        this->tree = vector<int>(2*n);
        this->n = n;
    }
    
    // [l, r).
    void modify(int l, int r, int value = 1) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) tree[l++] += value;
            if (r&1) tree[--r] += value;
        }
    }
    
    int query(int p) {
        int res = 0;
        for (p += n; p > 0; p >>= 1) {
            res += tree[p];
        }
        return res;
    }
};

// O((m+n)*log(n)).
void solveCase() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cats(m);
    for (pair<int, int>& cat : cats) {
        cin >> cat.first >> cat.second;
    }
    tree1 next_start(n+1);
    tree2 num_interval(n+1);
    for (pair<int, int>& cat : cats) {
        next_start.modify(cat.first, cat.second+1, cat.second+1);
        num_interval.modify(cat.first, cat.second+1);
    }
    vector<int> dp(n+2, 0);
    for (int i = n; i >= 1; --i) {
        int take = 0;
        if (num_interval.query(i) > 0) {
            take = num_interval.query(i)+dp[next_start.query(i)];
        }
        int notake = dp[i+1];
        dp[i] = max(take, notake);
    }
    cout << dp[1] << endl;
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
