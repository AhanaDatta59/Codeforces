#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n=0): n(n), f(n+1,0) {}
    void reset(int n_) { n=n_; f.assign(n+1,0); }
    void add(int i,int v){ for(; i<=n; i+=i&-i) f[i]+=v; }
    int sum(int i) const { int s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
    
    int find_kth(int k) const {
        int idx = 0;
        int bit = 1;
        while ((bit<<1) <= n) bit <<= 1;
        for (int d = bit; d; d >>= 1) {
            int nxt = idx + d;
            if (nxt <= n && f[nxt] < k) {
                k -= f[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<int> L1(n+1, 0);
        vector<int> st; st.reserve(n);
        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
            L1[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }

        int maxVal = 0;
        for (int i = 1; i <= n; ++i) maxVal = max(maxVal, a[i]);
        vector<vector<int>> posByVal(maxVal+1);
        for (int i = 1; i <= n; ++i) posByVal[a[i]].push_back(i);

        vector<pair<int,int>> qry; qry.reserve(n);
        for (int i = 1; i <= n; ++i) qry.emplace_back(b[i], i);
        sort(qry.begin(), qry.end(), [](auto &x, auto &y){
            if (x.first != y.first) return x.first > y.first; 
            return x.second < y.second;
        });

        Fenwick ft(n);
        int val_ptr = maxVal;
        vector<int> L2(n+1, 0);
        for (auto [need, idx] : qry) {
            while (val_ptr >= need) {
                for (int p : posByVal[val_ptr]) ft.add(p, 1);
                --val_ptr;
            }
            int cnt = ft.sum(idx);
            if (cnt == 0) L2[idx] = 0;
            else L2[idx] = ft.find_kth(cnt); 
        }

        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            long long s_i = (long long)min(L1[i], L2[i]) + (long long)(i - L1[i]) * (a[i] == b[i] ? 1 : 0);
            ans += s_i * (long long)(n - i + 1);
        }

        cout << ans << '\n';
    }
    return 0;
}
