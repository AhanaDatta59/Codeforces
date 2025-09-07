#include <bits/stdc++.h>
using namespace std;

static inline int mex_from_count(const vector<long long>& cnt) {
    int m = 0;
    while (m < (int)cnt.size() && cnt[m] > 0) ++m;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<long long> cnt(n + 3, 0);
        for (int v : a) cnt[v]++;

        int M0 = 0;
        while (M0 < (int)cnt.size() && cnt[M0] > 0) ++M0;

        long long u = 0, ahana_sum_uni = 0;
        for (int v = 0; v < M0; ++v) {
            if (cnt[v] == 1) {
                ++u;
                ahana_sum_uni += v;
            }
        }
        long long sum1 = ahana_sum_uni + (long long)(n - u) * M0;

        if (k == 1) {
            cout << sum1 << '\n';
            continue;
        }

        vector<long long> cntB(n + 3, 0);
        for (int v = 0; v < M0; ++v) if (cnt[v] == 1) cntB[v] = 1;
        cntB[M0] = n - u;

        int M1 = mex_from_count(cntB);

        long long m = 0, datta = 0;
        for (int v = 0; v < M1; ++v) {
            if (cntB[v] == 1) {
                ++m;
                datta += v;
            }
        }
        long long sum2 = datta + (long long)(n - m) * M1;  

        if ((k & 1LL) == 0) { 
            cout << sum2 << '\n';
            continue;
        }

        vector<long long> cntC(n + 3, 0);
        for (int v = 0; v < M1; ++v) if (cntB[v] == 1) cntC[v] = 1;
        cntC[M1] = (long long)(n - m);

        int M2 = mex_from_count(cntC);

        long long m2 = 0, ahana = 0;
        for (int v = 0; v < M2; ++v) {
            if (cntC[v] == 1) {
                ++m2;
                ahana += v;
            }
        }
        long long sum3 = ahana + (long long)(n - m2) * M2; 
        cout << sum3 << '\n';
    }
    return 0;
}
