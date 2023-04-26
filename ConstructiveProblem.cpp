// https://codeforces.com/problemset/problem/1819/A

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

int get_mex(vector<int> a) {
    int mex = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        if (a[i] == mex)
            mex++;
    return mex;
}

void solveCase() {
    int len;
    cin >> len;
    vector<int> a(len);
    for (int i = 0; i < len; i++)
        cin >> a[i];
    int mex = get_mex(a);
    int new_mex = mex+1;
    int l = 0, r = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == new_mex) {
            l = i;
            break;
        }
    }
    for (int i = l; i < len; i++) {
        if (a[i] == new_mex)
            r = i;
    }
    // cout << "DEBUG: "<< mex << " "<<l<<" "<<r<<"\n";
    if (l == r) {
        cout << (mex != a.size() ? "Yes" : "No") << "\n";
        return;
    }
    vector<bool> contains(mex+1, false);
    for (int i = 0; i < l; i++) {
        int ai = a[i];
        if (ai <= mex)
            contains[ai] = true;
    }
    for (int i = r+1; i < a.size(); i++) {
        int ai = a[i];
        if (ai <= mex)
            contains[ai] = true;
    }
    // cout << "DEBUG: BOOL ARR: ";
    // for (bool b : contains)
    //     cout << b << " ";
    // cout << "\n";
    int num_missing = 0;
    for (int i = 0; i < contains.size() && num_missing < 2; i++)
        if (!contains[i])
            num_missing++;
    cout << ((num_missing < 2) ? "Yes" : "No") << "\n";
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
