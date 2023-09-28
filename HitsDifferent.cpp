// https://codeforces.com/problemset/problem/1829/G

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>> pyramid;

#define square(a) ((ll)a*a)

void createPyramid() {
    pyramid.reserve(2023);
    for (int i = 0, j = 1; i < 2023; ++i) {
        pyramid.push_back(vector<ll>(i+1));
        for (int k = 0; k <= i; ++k) {
            pyramid[i][k] = square(j);
            ++j;
        }
    }
}

ll go_left(int r, int c) {
    if (r < 0 || c < 0) {
        return 0;
    }
    return pyramid[r][c]+go_left(r-1, c-1);
}

ll go(int r, int c) {
    if (r < 0 || c >= pyramid[r].size()) {
        return 0;
    }
    return go_left(r, c)+go(r-1, c);
}

void solveCase() {
    int n, r, c, sum;
    cin >> n;
    for (r = 0, sum = 0; r < pyramid.size(); ++r) {
        sum += pyramid[r].size();
        if (sum >= n) {
            break;
        }
    }
    for (c = pyramid[r].size()-1; sum > n; --c, --sum);
    cout << go(r, c) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    cin >> nC;
    createPyramid();
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
