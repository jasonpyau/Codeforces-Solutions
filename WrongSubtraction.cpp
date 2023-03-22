// https://codeforces.com/problemset/problem/977/A

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, nC = 0;
    cin >> n >> nC;

    for (int i = 0; i < nC; i++) {
        if (n % 10 == 0)
            n /= 10;
        else 
            n--;
    }
    cout << n;
    
    return 0;
}
