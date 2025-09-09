#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;
//ahana code easy
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

        //vector
        vector<int> depth(n + 1, 0), order;
        order.reserve(n);
       
        {
            vector<int> st; st.reserve(n);
            st.push_back(1);
            depth[1] = 1;
            vector<int> it(n + 1, 0);
            while (!st.empty()) {
                int u = st.back();
                if (it[u] < (int)ch[u].size()) {
                    int v = ch[u][it[u]++];
                    depth[v] = depth[u] + 1;
                    st.push_back(v);
                } else {
                    order.push_back(u);
                    st.pop_back();
                }
            }
        }

        int minLeafDepth = INT_MAX, maxDepth = 1;
        vector<int> isLeaf(n + 1, 0);
        for (int u = 1; u <= n; ++u) {
            if (ch[u].empty()) {
                isLeaf[u] = 1;
                minLeafDepth = min(minLeafDepth, depth[u]);
            }
            maxDepth = max(maxDepth, depth[u]);
        }

        //do dfs
        vector<int> cntDepth(maxDepth + 2, 0);
        for (int u = 1; u <= n; ++u) ++cntDepth[depth[u]];
        vector<int> prefCnt(maxDepth + 2, 0);
        for (int d = 1; d <= maxDepth; ++d) prefCnt[d] = prefCnt[d - 1] + cntDepth[d];

        auto solve_for_budget = [&](long long K)->long long {
            long long best = 0;
          
            for (int d = 0; d <= minLeafDepth; ++d) {
                int usable = (d == 0 ? 0 : prefCnt[d]);
                if (usable < K) continue; 
                int Tmx = d;                    
                if (Tmx > minLeafDepth) Tmx = minLeafDepth;

                static vector<int> emptyVec; // dummy
                vector<vector<int>> DP(n + 1);
                for (int u : order) {
                    if (d == 0 || depth[u] > d) {
                        DP[u].assign(Tmx + 1, INF);
                        DP[u][0] = 0;
                        continue;
                    }
                    if (ch[u].empty()) {
                        DP[u].assign(Tmx + 1, INF);
                        DP[u][0] = 0;
                        if (Tmx >= 1) DP[u][1] = 1;
                        continue;
                    }
                  
                    vector<int> sumT(Tmx + 1, 0), sumTm1(Tmx + 1, 0);
                    for (int v : ch[u]) {
                        const vector<int> &dv = DP[v];
                        for (int t = 0; t <= Tmx; ++t) {
                            int addT = (t < (int)dv.size() ? dv[t] : INF);
                            if (addT >= INF || sumT[t] >= INF) sumT[t] = INF;
                            else {
                                sumT[t] += addT;
                                if (sumT[t] >= INF) sumT[t] = INF;
                            }
                            if (t >= 1) {
                                int addP = (t - 1 < (int)dv.size() ? dv[t - 1] : INF);
                                if (addP >= INF || sumTm1[t] >= INF) sumTm1[t] = INF;
                                else {
                                    sumTm1[t] += addP;
                                    if (sumTm1[t] >= INF) sumTm1[t] = INF;
                                }
                            }
                        }
                    }
                    DP[u].assign(Tmx + 1, INF);
                    DP[u][0] = 0;
                    for (int t = 1; t <= Tmx; ++t) {
                        int notPick = sumT[t];
                        int pick    = (sumTm1[t] >= INF - 1 ? INF : 1 + sumTm1[t]);
                        DP[u][t] = min(pick, notPick);
                    }
                }
              
                int x = 0;
                for (int t = Tmx; t >= 0; --t) {
                    if (DP[1][t] <= K) { x = t; break; }
                }
                long long suffix = max(0, minLeafDepth - d); 
                best = max(best, (long long)x + suffix);
            }
            return best;
        };

        long long ans = 0;
        ans = max(ans, solve_for_budget(k));
        ans = max(ans, solve_for_budget(n - k));

        cout << ans << '\n';
    }
    return 0;
    //end 
}
