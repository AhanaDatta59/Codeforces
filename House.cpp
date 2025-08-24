#include <bits/stdc++.h>
using namespace std;

//ahana code 4
using ll = long long;
static const int MOD = 1'000'000'007;


ll modpow(ll a, ll e=MOD-2) {
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

//maybe 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxmax = 200000;
    vector<ll> fact(maxmax+1,1);
    for(int i=1;i<=maxmax;i++)
        fact[i] = fact[i-1]*i % MOD;

    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ahana(n, -1);
        queue<int> q;
        bool ok = true;
        ahana[0] = 0;
        q.push(0);
        while(!q.empty() && ok){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                if(ahana[v]==-1){
                    ahana[v] = ahana[u]^1;
                    q.push(v);
                }
                else if(ahana[v] == ahana[u]){
                    ok = false;
                    break;
                }
            }
        }

        //come here again
        if(!ok){
            cout << 0 << "\n";
            continue;
        }

        auto datta = [&](int side_ahana,
                                vector<ll> & out_class_prod,
                                int & out_blocks)
                              -> bool
        {
           
            vector<pair<vector<int>,int>> L;
            L.reserve(n);
            for(int u=0;u<n;u++){
                if(ahana[u]!=side_ahana) continue;
                vector<int> nb;
                nb.reserve(adj[u].size());
                for(int v:adj[u]){
                    if(ahana[v]!=(side_ahana^1)) continue;
                    nb.push_back(v);
                }
                sort(nb.begin(), nb.end());
                L.emplace_back(move(nb), u);
            }
            // Group by identical neighbor-lists
            sort(L.begin(), L.end(),
                 [&](auto &a, auto &b){
                     return a.first < b.first;
                 });
            vector<vector<int>> uniq;       
            vector<int>        cccc;      
            for(auto &pr: L){
                if(uniq.empty() || pr.first != uniq.back()){
                    uniq.push_back(pr.first);
                    cccc.push_back(1);
                } else {
                    cccc.back()++;
                }
            }
        
            sort(uniq.begin(), uniq.end(),
                 [&](auto &A, auto &B){
                     return A.size() < B.size();
                 });
            for(int i=0;i+1<(int)uniq.size();i++){
                auto &small = uniq[i];
                auto &big   = uniq[i+1];
                // is 'small' ⊆ 'big' ?
                int p=0, q=0;
                while(p<(int)small.size() && q<(int)big.size()){
                    if(small[p]==big[q]){
                        p++; q++;
                    } else if(small[p]>big[q]){
                        q++;
                    } else {
                        return false;
                    }
                }
                if(p < (int)small.size())
                    return false;
            }
           
            ll prod = 1;
            for(int c: cccc){
                prod = (prod * fact[c]) % MOD;
            }
            out_class_prod = prod;
            out_blocks     = (int)cccc.size();
            return true;
        };

        ll prodA;  int blocksA;
        if(!datta(0, prodA, blocksA)){
            cout << 0 << "\n";
            continue;
        }
        ll prodB;  int blocksB;
        if(!datta(1, prodB, blocksB)){
            cout << 0 << "\n";
            continue;
        }

        ll ans = 2;  
        if(blocksA>1 && blocksB>1) 
            ans = (ans * 2) % MOD;

        ans = (ans * prodA) % MOD;
        ans = (ans * prodB) % MOD;

        cout << ans << "\n";
    }

    return 0;
}
