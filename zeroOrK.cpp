#include <bits/stdc++.h>
using namespace std;


//ahana code 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long ahana = k + 1;  
        for (int i = 0; i < n; ++i) {
            long long r = a[i] % ahana;                
            __int128 val = (__int128)a[i] + (__int128)k * r; 
            cout << (long long)val << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
