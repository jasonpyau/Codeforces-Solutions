// https://codeforces.com/problemset/problem/1933/E

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e5+1;

int search(int l, int u, vector<int>& sections_sum) {
    int low = l, mid, r = INF, high = sections_sum.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        ll curr_sections = sections_sum[mid]-sections_sum[mid-1];
        ll prev_sections = sections_sum[mid-1]-sections_sum[l-1];
        // Multiply by 2 to avoid floating point.
        // curr_sections*u-curr_sections*(the average subtraction).
        // First subtraction will be prev_sections.
        // Last subtraction will be prev_sections+curr_sections-1.
        ll delta = 2*u*curr_sections-curr_sections*(2*prev_sections+curr_sections-1);
        if (delta > 0) {
            r = mid;
            low = mid+1;
        } else {
            if (delta == 0) {
                r = min(r, mid);
            }
            high = mid-1;
        }
    }
    return (r == INF) ? l : r;
}

void solveCase() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int& a_i : a) {
        cin >> a_i;
    }
    cin >> q;
    vector<int> sections_sum(n+1);
    for (int i = 1; i <= n; ++i) {
        sections_sum[i] = sections_sum[i-1]+a[i-1];
    }
    for (int i = 0, l, u; i < q; ++i) {
        cin >> l >> u;
        cout << search(l, u, sections_sum) << " ";
    }
    cout << endl;
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
