#include <bits/stdc++.h>
using namespace std;

//ahana datta code 6
static const int MOD = 1'000'000'007;

inline int addmod(int a, int b) { int s = a + b; if (s >= MOD) s -= MOD; return s; }
inline int submod(int a, int b) { int s = a - b; if (s < 0) s += MOD; return s; }
inline int mulmod(long long a, long long b) { return int((a * b) % MOD); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m; 
        cin >> n >> m;
        int k; 
        cin >> k;
        vector<int> good(k);
        for (int i = 0; i < k; ++i) cin >> good[i]; // 1-based, sorted, c1=1

        vector<uint8_t> ahanadatta(2, 0), dp_cur;
        ahanadatta[1] = 1;

        //ahana vector
        vector<int> allowed; allowed.reserve(k);
        int gi = 0;
        if (gi < k && good[gi] == 1) { allowed.push_back(1); ++gi; }

        for (int p = 2; p <= n; ++p) {
            if (gi < k && good[gi] == p) { allowed.push_back(p); ++gi; }

            const bool aliceTurn = ((n - p) % 2 == 0);
            const int S = 1 << p;
            dp_cur.assign(S, 0);

            uint32_t lowmsss[21] = {0};
            for (int idx : allowed) {
                lowmsss[idx] = (idx >= 2) ? ((1u << (idx - 1)) - 1u) : 0u;
            }

            //use bit mask
            for (int mask = 0; mask < S; ++mask) {
                if (aliceTurn) {
                   
                    uint8_t v = 0;
                    for (int i : allowed) {
                        uint32_t msk = (uint32_t)mask;
                      
                        uint32_t nm = (msk & lowmsss[i]) | ((msk >> i) << (i - 1));
                        if (ahanadatta[nm]) { v = 1; break; }
                    }
                    dp_cur[mask] = v;
                } else {
                    
                    uint8_t v = 1;
                    for (int i : allowed) {
                        uint32_t msk = (uint32_t)mask;
                        uint32_t nm = (msk & lowmsss[i]) | ((msk >> i) << (i - 1));
                        if (!ahanadatta[nm]) { v = 0; break; }
                    }
                    dp_cur[mask] = v;
                }
            }
            ahanadatta.swap(dp_cur);
        }
       
        const int N = 1 << n;
        vector<int> f(N, 0); 
        for (int mask = 1; mask < N; ++mask) {
            if (!ahanadatta[mask]) continue;
            bool minimal = true;
            int msk = mask;
            while (msk) {
                int b = msk & -msk;
                int sub = mask ^ b;
                if (ahanadatta[sub]) { minimal = false; break; }
                msk ^= b;
            }
            if (minimal) f[mask] = 1;
        }

        //good here
        vector<int> cnt = f; 
        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < N; ++mask) {
                if (mask & (1 << i)) {
                    cnt[mask] += cnt[mask ^ (1 << i)];
                }
            }
        }

        vector<int> g(N, 0);
        for (int mask = 0; mask < N; ++mask) g[mask] = (cnt[mask] > 0) ? 1 : 0;

        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < N; ++mask) {
                if (mask & (1 << i)) {
                    g[mask] = submod(g[mask], g[mask ^ (1 << i)]);
                }
            }
        }
    
        vector<int> S(n + 1, 0); // we use S[1..n]
        for (int h = 1; h <= m; ++h) {
            int cur = h % MOD;
            for (int kpow = 1; kpow <= n; ++kpow) {
                S[kpow] = addmod(S[kpow], cur);
                cur = mulmod(cur, h);
            }
        }

      
        vector<int> powM(n + 1, 1);
        for (int e = 1; e <= n; ++e) powM[e] = mulmod(powM[e - 1], m);

        long long ans = 0;
        for (int mask = 1; mask < N; ++mask) {
            int coeff = g[mask];
            if (!coeff) continue;
            int kbits = __builtin_popcount((unsigned)mask);
            int term = mulmod(coeff, mulmod(powM[n - kbits], S[kbits]));
            ans += term;
            if (ans >= MOD) ans -= MOD;
        }
        cout << (int)ans << '\n';
    }
    return 0;
}
