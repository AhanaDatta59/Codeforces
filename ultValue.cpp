#include <bits/stdc++.h>
using namespace std;

//ahana code 3
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<long long> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        long long base = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) base += a[i];
            else base -= a[i];
        }

        long long best = (n % 2 ? n - 1 : n - 2); 

        //odd 
        long long ahanadatta = LLONG_MIN / 4;
        long long prefOdd = LLONG_MIN / 4;
        for (int k = 1; k <= n; ++k) {
            if (k & 1) {
                prefOdd = max(prefOdd, -2 * a[k] - (long long)k);
            } else {
                if (prefOdd > LLONG_MIN / 8) {
                    long long cand = (2 * a[k] + (long long)k) + prefOdd;
                    if (cand > ahanadatta) ahanadatta = cand;
                }
            }
        }

       //see here
        vector<long long> suffOdd(n + 3, LLONG_MIN / 4); 
        for (int k = n; k >= 1; --k) {
            suffOdd[k] = suffOdd[k + 1];
            if (k & 1) suffOdd[k] = max(suffOdd[k], -2 * a[k] + (long long)k);
        }
        for (int j = 2; j <= n; j += 2) { // even j
            long long candSrc = suffOdd[j + 1];
            if (candSrc > LLONG_MIN / 8) {
                long long cand = (2 * a[j] - (long long)j) + candSrc;
                if (cand > ahanadatta) ahanadatta = cand;
            }
        }

        if (ahanadatta > best) best = ahanadatta;
        if (best < 0) best = 0; 

        cout << base + best << '\n';
    }
    return 0;
}
