#include <bits/stdc++.h>
using namespace std;

//ahana code hard
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; long long k;
        cin >> n >> k;

        vector<vector<int>> ch(n + 1);
        for (int i = 2; i <= n; ++i) {
            int p; cin >> p;
            ch[p].push_back(i);
        }

       //do the vec here
        vector<int> depth(n + 1, 0), post;
        post.reserve(n);
        {
            vector<pair<int,int>> st; st.reserve(n);
            st.emplace_back(1, 0);
            depth[1] = 1;
            while (!st.empty()) {
                auto &[u, it] = st.back();
                if (it < (int)ch[u].size()) {
                    int v = ch[u][it++];
                    depth[v] = depth[u] + 1;
                    st.emplace_back(v, 0);
                } else {
                    post.push_back(u);
                    st.pop_back();
                }
            }
        }

     //ahana
        int L = INT_MAX, maxd = 1;
        for (int u = 1; u <= n; ++u) {
            if (ch[u].empty()) L = min(L, depth[u]);
            maxd = max(maxd, depth[u]);
        }
        if (L == INT_MAX) L = 1;

        vector<int> cntDepth(L + 1, 0);
        for (int u = 1; u <= n; ++u) {
            if (depth[u] <= L) ++cntDepth[depth[u]];
        }
        vector<int> S(L + 1, 0); // prefix by depth
        for (int t = 1; t <= L; ++t) S[t] = S[t - 1] + cntDepth[t];

        vector<int> leafdist(n + 1, 0);
        for (int u : post) {
            if (ch[u].empty()) leafdist[u] = 1;
            else {
                int mn = INT_MAX;
                for (int v : ch[u]) mn = min(mn, leafdist[v]);
                leafdist[u] = 1 + mn;
            }
        }

        vector<int> cntB(L + 1, 0);
        for (int u = 1; u <= n; ++u) {
            int d = leafdist[u];
            if (d <= L) ++cntB[d];
        }
        vector<int> B(L + 1, 0); 
        for (int t = 1; t <= L; ++t) B[t] = B[t - 1] + cntB[t];

        auto X = [&](long long K) -> int {
          
            int t = upper_bound(S.begin(), S.end(), (int)K) - S.begin() - 1;
            return max(0, min(t, L));
        };
        auto Y = [&](long long K) -> int {
            int t = upper_bound(B.begin(), B.end(), (int)K) - B.begin() - 1;
            return max(0, min(t, L));
        };

        long long zeros = k, ones = n - k;

        int ans1 = min(L, X(zeros) + Y(ones)); 
        int ans2 = min(L, X(ones) + Y(zeros)); 
        cout << max(ans1, ans2) << '\n';
    }
    return 0;
    //end code 
}
