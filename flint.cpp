#include <bits/stdc++.h>
using namespace std;
//ahana datta 6
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> e(n + 1);
        for (int i = 1; i <= n; ++i) cin >> e[i];

        auto L = [&](int i) -> long long { return (long long)i - (long long)e[i] + 1; };
        auto R = [&](int i) -> long long { return (long long)i + (long long)e[i] - 1; };

        long long pos = 1;         
        int p = 1;                  
        
        priority_queue<pair<long long,int>> pq;
        vector<int> ans;

        bool ok = true;
        while (pos <= n) {
           
            while (p <= n && L(p) <= pos) {
                if (e[p] > 0) {
                    pq.emplace(R(p), p);
                }
                ++p;
            }

            while (!pq.empty() && pq.top().second < pos) pq.pop();
            if (pq.empty()) { ok = false; break; }

            auto [bestR, idx] = pq.top(); pq.pop();
        
            ans.push_back(idx);
            pos = bestR + 1; 
        }

        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << (int)ans.size() << '\n';
            for (int i = 0; i < (int)ans.size(); ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
