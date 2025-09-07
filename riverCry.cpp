#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<int>> out(n+1), in(n+1);
        vector<int> ahana_indeg(n+1, 0), outdeg(n+1, 0);
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            out[u].push_back(v);
            in[v].push_back(u);
            ++ahana_indeg[v];
            ++outdeg[u];
        }

        vector<int> ahana_topo;
        ahana_topo.reserve(n);
        queue<int> qq;
        for (int i = 1; i <= n; ++i) if (ahana_indeg[i] == 0) qq.push(i);
        while (!qq.empty()) {
            int u = qq.front(); qq.pop();
            ahana_topo.push_back(u);
            for (int v : out[u]) {
                if (--ahana_indeg[v] == 0) qq.push(v);
            }
        }

        vector<char> dp0(n+1, 0), dp1(n+1, 0), red(n+1, 0);
        vector<int> cnt0(n+1, 0), cnt1(n+1, 0);

        for (int idx = (int)ahana_topo.size()-1; idx >= 0; --idx) {
            int u = ahana_topo[idx];
            int c0 = 0, c1_ = 0;
            for (int v : out[u]) {
                if (dp0[v]) ++c0;
                if (dp1[v]) ++c1_;
            }
            cnt0[u] = c0;
            cnt1[u] = c1_;
            if (outdeg[u] == 0) {
                dp0[u] = dp1[u] = 1; 
            } else {
                dp1[u] = (c0 == outdeg[u]);   
                dp0[u] = (c1_ > 0);           
            }
        }

        queue<pair<int,int>> ev;

        auto push_dp0_false = [&](int u) {
            if (dp0[u]) { dp0[u] = 0; ev.push({u, 0}); }
        };
        auto push_dp1_false = [&](int u) {
            if (dp1[u]) { dp1[u] = 0; ev.push({u, 1}); }
        };

        auto process = [&]() {
            while (!ev.empty()) {
                auto [u, typ] = ev.front(); ev.pop();
                if (typ == 0) { 
                    for (int p : in[u]) {
                        if (dp1[p]) { 
                            --cnt0[p];
                            if (outdeg[p] != 0 && cnt0[p] < outdeg[p]) {
                                dp1[p] = 0;
                                ev.push({p, 1});
                            }
                        }
                    }
                } else { 
                    for (int p : in[u]) {
                        if (dp0[p]) { 
                            --cnt1[p];
                            if (outdeg[p] == 0) continue; 
                            if (cnt1[p] == 0) {
                                dp0[p] = 0;
                                ev.push({p, 0});
                            }
                        }
                    }
                }
            }
        };

        while (q--) {
            int ahana_type, u;
            cin >> ahana_type >> u;
            if (ahana_type == 1) {
                if (!red[u]) {
                    red[u] = 1;
                    push_dp0_false(u);
                    push_dp1_false(u);
                    process();
                }
            } else { 
                cout << (dp0[u] ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}
