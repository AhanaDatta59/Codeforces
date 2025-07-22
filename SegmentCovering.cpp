#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;


//ahana 4
ll mdp(ll a, ll e = MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> ahana(m+1);
    ll B = 1;  

    for(int i = 0; i < n; i++){
        int l, r;
        ll p, q;
        cin >> l >> r >> p >> q;

        ll beta = (q - p + MOD) % MOD * mdp(q) % MOD;
        B = B * beta % MOD;

        ll den = (q - p + MOD) % MOD;
        ll w = p % MOD * mdp(den) % MOD;

        ahana[r].emplace_back(l - 1, w);
    }

    vector<ll> dp(m+1);
    dp[0] = 1;
    for(int j = 1; j <= m; j++){
        ll sum = 0;
        for(auto &pr : ahana[j]){
            int lprev = pr.first;
            ll w = pr.second;
            sum = (sum + dp[lprev] * w) % MOD;
        }
        dp[j] = sum;
    }

    cout << (dp[m] * B) % MOD << "\n";
    return 0;
}
