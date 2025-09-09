#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

//ahana code 5
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

        if (m == 1) {                
            cout << 1 << '\n';
            continue;
        }

        //vector make it
        vector<uint8_t> dp_prev(2);
        dp_prev[0] = 1; dp_prev[1] = 2;

        vector<int> allowed; allowed.reserve(k);
        int gi = 0;
        if (gi < k && good[gi] == 1) { allowed.push_back(1); ++gi; } // p=1

        vector<uint8_t> dp_cur;
        for (int p = 2; p <= n; ++p) {
           
            if (gi < k && good[gi] == p) { allowed.push_back(p); ++gi; }

            //ahana
            const bool aliceTurn = ((n - p) % 2 == 0);
            const int S = 1 << p;
            dp_cur.assign(S, 0);

            uint32_t lowerMask[21] = {0};
            for (int idx : allowed) {
                lowerMask[idx] = (idx >= 2) ? ((1u << (idx - 1)) - 1u) : 0u;
            }

            for (int mask = 0; mask < S; ++mask) {
                uint8_t v = aliceTurn ? 1 : 2; 
               
                if (aliceTurn) {
                    for (int i : allowed) {
                     
                        uint32_t m = (uint32_t)mask;
                        uint32_t nm = (m & lowerMask[i]) | ((m >> i) << (i - 1));
                        if (dp_prev[nm] == 2) { v = 2; break; }
                    }
                } else {
                    for (int i : allowed) {
                        uint32_t m = (uint32_t)mask;
                        uint32_t nm = (m & lowerMask[i]) | ((m >> i) << (i - 1));
                        if (dp_prev[nm] == 1) { v = 1; break; }
                    }
                }
                dp_cur[mask] = v;
            }

            dp_prev.swap(dp_cur);
        }

        //dp ends here
        long long ans = 0;
        if (n == 1) {
            ans = (dp_prev[0] + dp_prev[1]) % MOD;
        } else {
            long long sum = 0;
            for (uint8_t v : dp_prev) sum += v;
            ans = sum % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
