#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;
using ll = long long;

// ahana datta
ll modpow(ll a, ll e=MOD-2){
    ll r=1;
    while(e){
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
   
    int MAXF = 400000;
    vector<ll> fact(MAXF+1,1), ifact(MAXF+1,1), inv2(MAXF+1,1);
    for(int i=1;i<=MAXF;i++){
        fact[i] = fact[i-1]*i % MOD;
    }
    ifact[MAXF] = modpow(fact[MAXF]);
    for(int i=MAXF;i>0;i--){
        ifact[i-1] = ifact[i]*i % MOD;
    }
  
    ll i2 = modpow(2);
    for(int i=1;i<=MAXF;i++){
        inv2[i] = inv2[i-1]*i2 % MOD;
    }

    while(T--){
        int n,k;
        cin >> n >> k;
        ll M = fact[2*n] * inv2[n] % MOD;

     
        if(k < 1 || k >= n){
            cout << 0 << "\n";
            continue;
        }
        ll A = fact[n-1] * ifact[k] % MOD * ifact[n-1-k] % MOD;

       
        int NK = n - k;
        ll B = 0;
        for(int i = 0; i <= NK; i++){
            ll ways = fact[NK] * ifact[i] % MOD * ifact[NK-i] % MOD;   // C(n-k,i)
            ll pw = (i==0 && n-2==0 ? 1 : modpow(i, n-2));
            ll term = ways * pw % MOD;
            if((NK - i) & 1)    // if exponent of -1 is odd
                term = (MOD - term);
            B = (B + term) % MOD;
        }

        ll ans = M;
        ans = ans * A % MOD;
        ans = ans * B % MOD;
        cout << ans << "\n";
    }
    return 0;
}
