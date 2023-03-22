// https://codeforces.com/problemset/problem/1353/B

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int nC = 0;
    cin >> nC;
    for (int c = 0; c < nC; c++) {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> a1;
        vector<int> a2;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            a1.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            a2.push_back(input);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), greater<int>()); 
        for (int i = 0; i < k; i++)
            if (a2[i] > a1[i])
                a1[i] = a2[i];
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += a1[i];
        cout << ans << '\n';
    }
    return 0;
}
