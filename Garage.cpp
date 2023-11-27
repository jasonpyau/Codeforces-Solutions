// https://codeforces.com/contest/1725/problem/G

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// We have a^2+x=b^2, a,b,x in Z+.
// -> x = b^2-a^2.
// We find that x must be a difference of squares.
// Every perfect square can be represented as (2n)^2 OR (2n+1)^2, where n in Z+.
// -> 4n^2 OR 4(n^2+n)+1. Thus, p%4 = 0 OR 1, where p is a perfect square.
// Thus, x%4 = 0 OR 1 OR 3. (0-0 OR 1-1), (1-0), (0-1).
// For x%4 = 1 OR 3, smallest possible is 2^1-1^2 = 3.
// For x%4 = 0, smallest possible is 3^2-1^2 = 8.
// Recap, for x >= 8, x is IMPOSSIBLE iff x%4 = 2.
void solveCase() {
    int n, x;
    cin >> n;
    if (n < 4) {
        x = n*2+1;
    } else {
        // n = 6 add one, n = 9 add one, n = 12 add one, ...
        x = 4+n+(n-3)/3;
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nC = 1;
    // cin >> nC;
    for (int i = 1; i <= nC; i++) {
        // cout << "\nTEST #" << i << ":\n";
        solveCase();
    }
    return 0;
}
