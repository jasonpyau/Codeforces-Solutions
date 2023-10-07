// https://codeforces.com/problemset/problem/1861/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solveCase() {
    string s;
    cin >> s;
    int sorted = 0, unsorted = 0;
    vector<bool> bad;
    bad.reserve(s.size());
    bool ans = true;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch == '+') {
            bad.push_back(false);
        } else if (ch == '-') {
            if (bad.back()) {
                --unsorted;
            }
            bad.pop_back();
            sorted = min(sorted, (int)bad.size());
        } else if (ch == '1') {
            if (unsorted) {
                ans = false;
                break;
            }
            sorted = bad.size();
        } else if (ch == '0') {
            if (sorted == bad.size() || bad.size() <= 1) {
                ans = false;
                break;
            }
            if (!bad.back()) {
                bad[bad.size()-1] = true;
                ++unsorted;
            }
        }
    }
    cout << ((ans) ? "YES" : "NO") << endl;
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
