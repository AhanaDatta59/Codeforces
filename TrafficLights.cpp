#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> deg(n+1), pos(n+1);
        for (int u = 1; u <= n; u++)
            deg[u] = (int)adj[u].size();
       
        pos[1] = 0;
        for (int u = 2; u <= n; u++)
            pos[u] = pos[u-1] + deg[u-1];
        int S = pos[n] + deg[n];  // total # of states

        vector<int> sss(S), state_r(S);
        for (int u = 1; u <= n; u++) {
            for (int r = 0; r < deg[u]; r++) {
                int s = pos[u] + r;
                sss[s] = u;
                state_r[s] = r;
            }
        }

        vector<int> datta(S, -1);
        deque<int> Q;
        int start = pos[1] + 0;
        datta[start] = 0;
        Q.push_back(start);

        int ahana = -1;
        while (!Q.empty()) {
            int s = Q.front(); 
            Q.pop_front();
            int d = datta[s];
            int u = sss[s];
           
            if (u == n) {
                ahana = d;
                break;
            }
          
            {
                int r2 = (d+1) % deg[u];
                int s2 = pos[u] + r2;
                if (datta[s2] == -1) {
                    datta[s2] = d+1;
                    Q.push_back(s2);
                }
            }
           
            {
                int r = state_r[s];
                int v = adj[u][r];
                int r2 = (d+1) % deg[v];
                int s2 = pos[v] + r2;
                if (datta[s2] == -1) {
                    datta[s2] = d+1;
                    Q.push_back(s2);
                }
            }
        }

        vector<int> cnt(ahana+1, 0);
        int total_states = 0;
        for (int s = 0; s < S; s++) {
            if (datta[s] != -1) {
                cnt[datta[s]]++;
                total_states++;
            }
        }
       
        vector<int> posb(ahana+2, 0);
        for (int d = 1; d <= ahana; d++)
            posb[d] = posb[d-1] + cnt[d-1];
        posb[ahana+1] = posb[ahana] + cnt[ahana];

        vector<int> nextPos = posb; 
        vector<int> order(total_states);
        for (int s = 0; s < S; s++) {
            int d = datta[s];
            if (d >= 0) {
                order[nextPos[d]++] = s;
            }
        }

        const int INF = 1e9;
        vector<int> dp(S, INF);
        dp[start] = 0;

        for (int idx = 0; idx < total_states; idx++) {
            int s = order[idx];
            int d = datta[s];
            if (d == ahana) 
                continue;   // no out‐edges used beyond ahana
            int u = sss[s];
            int r = state_r[s];

            {
                int r2 = (d+1) % deg[u];
                int s2 = pos[u] + r2;
                if (datta[s2] == d+1)
                    dp[s2] = min(dp[s2], dp[s] + 1);
            }
           
            {
                int v  = adj[u][r];
                int r2 = (d+1) % deg[v];
                int s2 = pos[v] + r2;
                if (datta[s2] == d+1)
                    dp[s2] = min(dp[s2], dp[s]);
            }
        }

        int stId = posb[ahana];
        int howw = cnt[ahana];
        int bestW = INF;
        for (int i = stId; i < stId + howw; i++) {
            int s = order[i];
            if (sss[s] == n) 
                bestW = min(bestW, dp[s]);
        }

        cout << ahana << " " << bestW << "\n";
    }
    return 0;
}
