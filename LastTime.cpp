#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;

        struct Casino { ll l, r, real; };
        vector<Casino> a(n);
        vector<ll> vals;
        vals.reserve(n + 1);
        vals.push_back(k);

        for (int i = 0; i < n; i++) {
            cin >> a[i].l >> a[i].r >> a[i].real;
            vals.push_back(a[i].real);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = (int)vals.size();

        vector<int> idx_real(n);
        for (int i = 0; i < n; i++){
            idx_real[i] = int(lower_bound(vals.begin(), vals.end(), a[i].real) - vals.begin());
        }
       
        int idx_k = int(lower_bound(vals.begin(), vals.end(), k) - vals.begin());

        vector<vector<int>> seg(4 * m);

        auto add_interval = [&](auto &self, int node, int l, int r, int L, int R, int ci) -> void {
            if (R < l || r < L) return;
            if (L <= l && r <= R) {
                seg[node].push_back(ci);
                return;
            }
            int mid = (l + r) >> 1;
            self(self, node*2,     l,    mid, L, R, ci);
            self(self, node*2 + 1, mid+1, r,   L, R, ci);
        };

        for (int i = 0; i < n; i++) {
           
            auto itL = lower_bound(vals.begin(), vals.end(), a[i].l);
            auto itR = upper_bound(vals.begin(), vals.end(), a[i].r);
            if (itL == vals.end() || itL >= itR) continue;
            int L = int(itL - vals.begin());
            int R = int(itR - vals.begin()) - 1;
            add_interval(add_interval, 1, 0, m-1, L, R, i);
        }

        vector<char> vis(m, 0);
        queue<int> q;
        vis[idx_k] = 1;
        q.push(idx_k);

        ll ans = 0;
        vector<int> buffer;
        buffer.reserve(16);

        function<void(int,int,int,int)> collect = [&](int node, int l, int r, int pos){
            for (int ci : seg[node]) {
                buffer.push_back(ci);
            }
            seg[node].clear();
            if (l == r) return;
            int mid = (l + r) >> 1;
            if (pos <= mid)
                collect(node*2,     l,    mid, pos);
            else
                collect(node*2 + 1, mid+1, r,   pos);
        };

        while (!q.empty()) {
            int u = q.front(); q.pop();
            ll coins = vals[u];
            ans = max(ans, coins);

            buffer.clear();
            collect(1, 0, m-1, u);

            for (int ci : buffer) {
                int v = idx_real[ci];
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
