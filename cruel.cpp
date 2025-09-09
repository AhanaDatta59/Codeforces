#include <bits/stdc++.h>
using namespace std;

//ahana datta code 3
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<long long> L(n), R(n), V(n);
        long long base = 0;        
        long long sumL = 0;       
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i];
            base += (R[i] - L[i]);
            sumL += L[i];
            V[i] = L[i] + R[i];
        }

        int K = n / 2;
       
        //create vector 
        vector<pair<long long,int>> ord;
        ord.reserve(n);
        for (int i = 0; i < n; ++i) ord.push_back({V[i], i});
        sort(ord.begin(), ord.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second; 
        });

        //count now
        long long ahanadatta = 0;
        for (int i = 0; i < K; ++i) ahanadatta += ord[i].first;

        if (n % 2 == 0) {
           
            long long extra = -sumL + ahanadatta;
            cout << (base + extra) << '\n';
        } else {
           
            //vnext
            vector<int> pos(n);
            for (int i = 0; i < n; ++i) pos[ord[i].second] = i;
            long long Vnext = ord[K].first; 

            long long best = LLONG_MIN;
            for (int i = 0; i < n; ++i) {
                long long sumK_excl = ahanadatta;
                if (pos[i] < K) {
                 
                    sumK_excl = ahanadatta - V[i] + Vnext;
                }
                long long cand = - (sumL - L[i]) + sumK_excl; 
                if (cand > best) best = cand;
            }
            cout << (base + best) << '\n';
        }
    }
    return 0;
}
