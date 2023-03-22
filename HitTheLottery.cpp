// https://codeforces.com/problemset/problem/996/A

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    int denoms[] = {100, 20, 10, 5, 1};
    
    int ans = 0;
    for (; n > 0; ans++) {
        for (int denom : denoms) {
            if (n % denom == 0) {
                n -= denom;
                break;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}
