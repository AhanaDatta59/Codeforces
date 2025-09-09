#include <bits/stdc++.h>
using namespace std;

//ahanadatta code 1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        long long a, b; 
        cin >> a >> b;
        if (a == b) {
            cout << 0 << '\n';
        } else {
            long long x = min(a, b), y = max(a, b);
            cout << (y % x == 0 ? 1 : 2) << '\n';
        }
    }
    return 0;
}
