// https://codeforces.com/problemset/problem/1870/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int search(vector<int>& values, int val) {
    int low = 0, mid, ans, high = values.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        if (values[mid] >= val) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}

int search_rev(vector<int>& values, int val) {
    int low = 0, mid, ans, high = values.size()-1;
    while (high >= low) {
        mid = (low+high)>>1;
        if (values[mid] >= val) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}

void solveCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<bool> freq(k+1, false);
    for (int i = 0; i < n; ++i) {
        freq[a[i]] = true;
    }
    vector<int> max(n);
    vector<int> max_rev(n);
    for (int i = 0, curr_max = 0; i < n; ++i) {
        curr_max = std::max(curr_max, a[i]);
        max[i] = curr_max;
    }
    for (int i = n-1, curr_max = 0; i >= 0; --i) {
        curr_max = std::max(curr_max, a[i]);
        max_rev[i] = curr_max;
    }
    vector<int> ans(k+1);
    for (int i = 1; i <= k; ++i) {
        if (!freq[i]) {
            ans[i] = 0;
        } else {
            ans[i] = (search_rev(max_rev, i)-search(max, i)+1)*2;
        }
    }
    for (int i = 1; i <= k; ++i) {
        cout << ans[i] << " ";
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
