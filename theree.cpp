#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// ahana 3

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll S0 = 0;
        for (int i = 0; i < n; i++) {
            S0 += llabs(a[i] - b[i]);
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int i, int j){
                 if (a[i] != a[j]) return a[i] < a[j];
                 return b[i] < b[j];
             });

      
        bool ahana = true;
        for (int t = 0; t+1 < n; t++) {
            if (b[p[t]] > b[p[t+1]]) {
                ahana = false;
                break;
            }
        }
        if (!ahana) {
          
            cout << S0 << "\n";
            continue;
        }

        ll datta = LLONG_MAX;
        for (int t = 0; t+1 < n; t++) {
            int i = p[t], j = p[t+1];
            ll ai = a[i], aj = a[j];
            ll bi = b[i], bj = b[j];
           
            ll a_min = min(ai, aj);
            ll a_max = max(ai, aj);
            ll b_min = min(bi, bj);
            ll b_max = max(bi, bj);
            ll cross = llabs(a_min - b_max)
                     + llabs(a_max - b_min);
            ll orig  = llabs(ai - bi)
                     + llabs(aj - bj);
            datta = min(datta, cross - orig);
        }

       
        cout << (S0 + datta) << "\n";
    }

    return 0;
}
