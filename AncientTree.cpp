#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll INF = (1LL<<60);

int n, k;
vector<ll> w;
vector<int> c;
vector<vector<int>> adj;
vector<int> ahanadatta;
vector<ll> dp;  

set<int>* dfs(int v, int p) {
   
    ll sumCost = 0;
    vector< set<int>* > childdd;
    childdd.reserve(adj[v].size());
    
 
    for (int u : adj[v]) if (u != p) {
        set<int>* st = dfs(u, v);
        sumCost += dp[u];
        childdd.push_back(st);
    }
    
  
    if (childdd.empty()) {
     
        ll localCost = 0;
        int chosen = c[v] ? c[v] : 1; 
        ahanadatta[v] = chosen;
        auto *mySet = new set<int>();
        mySet->insert(chosen);
        dp[v] = localCost;
        return mySet;
    }
    
    sort(childdd.begin(), childdd.end(),
         [&](auto *a, auto *b){ return a->size() > b->size(); });
    
    auto *big = childdd[0];
    unordered_map<int,int> seen;
    seen.reserve(big->size()*2);
    ll dattaaha = 0;
    
    for (int col : *big) {
        seen[col] = 1;
    }
  
    for (int i = 1; i < (int)childdd.size(); i++) {
        auto *small = childdd[i];
        for (int col : *small) {
            int &cnt = seen[col];
            cnt++;
            if (cnt == 2) {
                dattaaha++;
            }
        }
       
        for (int col : *small) {
            big->insert(col);
        }
        delete small;  
    }
    
    ll localCost = 0;
    int collllll = c[v];
    if (collllll != 0) {
        if (dattaaha > 0) localCost = w[v];
    } else {
     
        if (dattaaha == 0) {
            localCost = 0;
            collllll = 1; 
        } else if (dattaaha == 1) {
           
            for (auto &kv : seen) {
                if (kv.second >= 2) {
                    collllll = kv.first;
                    break;
                }
            }
        } else {
          
            localCost = w[v];
            for (auto &kv : seen) {
                if (kv.second >= 2) {
                    collllll = kv.first;
                    break;
                }
            }
        }
    }
    
    ahanadatta[v] = collllll;
    dp[v] = sumCost + localCost;
    
    big->insert(collllll);
    
    return big;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        cin >> n >> k;
        w.assign(n, 0);
        c.assign(n, 0);
        adj.assign(n, {});
        for(int i=0;i<n;i++) cin >> w[i];
        for(int i=0;i<n;i++) cin >> c[i];
        for(int i=0,u,v;i<n-1;i++){
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ahanadatta.assign(n,0);
        dp.assign(n,0);

        set<int>* topSet = dfs(0, -1);
        delete topSet;  // free

        cout << dp[0] << "\n";
        for(int i=0;i<n;i++){
            cout << ahanadatta[i] << (i+1<n?' ':'\n');
        }
    }
    return 0;
}
