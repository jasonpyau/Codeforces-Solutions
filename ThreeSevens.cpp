// https://codeforces.com/problemset/problem/1798/B

#include <bits/stdc++.h>
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define i64 int64_t
using namespace std;

void solveCase() {
    int m;
    cin >> m;
    vector<vector<int>> days(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        vector<int> parts(n);
        for (int j = 0; j < n; j++) {
            cin >> parts[j];
        }
        days[i] = parts;
    }
    deque<int> ans;
    bool has_ans = true;
    unordered_set<int> poss_winners;
    for (int i = m-1; i >= 0 && has_ans; i--) {
        bool found_winner = false;
        for (int j = 0; j < days[i].size(); j++) {
            int p = days[i][j];
            // Not found in set
            if (poss_winners.find(p) == poss_winners.end()) {
                poss_winners.insert(p);
                if (!found_winner)
                    ans.push_front(p);
                found_winner = true;
            }
        }
        has_ans = found_winner;
    }
    if (has_ans) {
        for (int p : ans) {
            cout << p << " ";
        }
    } else {
        cout << -1;
    }
    cout << "\n";
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
