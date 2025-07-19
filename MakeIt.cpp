#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        ll h0 = h[k - 1];
        vector<ll> vals = h;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        ll global_max = vals.back();

        if (h0 == global_max) {
            cout << "YES\n";
            continue;
        }

        ll re = h0;
        while (re < global_max) {
            ll thresh = re + h0;
           
            auto it = upper_bound(vals.begin(), vals.end(), thresh);
            if (it == vals.begin()) {
               
                break;
            }
          
            ll can = *(it - 1);
            if (can == re) {
                break;
            }
            re = can;
        }

        cout << (re >= global_max ? "YES\n" : "NO\n");
    }
    return 0;
}
