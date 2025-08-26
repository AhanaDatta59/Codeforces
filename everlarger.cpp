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
        vector<long long> a(n + 1); 
        for (int i = 1; i <= n; ++i) cin >> a[i];

        long long ans = 0;

        long long ahana = a[2];                  
        long long x1 = min(a[1], ahana);         
        ans += (a[1] - x1);
        ahana -= x1;

        for (int i = 3; i <= n; i += 2) {      
            long long capRight = (i + 1 <= n) ? a[i + 1] : (long long)4e18;
            long long xi = min({a[i], ahana, capRight});
            ans += (a[i] - xi);
            if (i + 1 <= n) ahana = a[i + 1] - xi;   
        }

        cout << ans << '\n';
    }
    return 0;
}
