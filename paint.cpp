#include <bits/stdc++.h>
using namespace std;

//ahana code 1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        if ((n & 1LL) != (b & 1LL)) {
            cout << "NO\n";
            continue;
        }

        if (a <= b || ((n & 1LL) == (a & 1LL))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
