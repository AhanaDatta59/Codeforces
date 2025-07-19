#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

//ahana datta
inline void addmod(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}


inline int mulmod(long long a, long long b) {
    return int((a*b) % MOD);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(2, vector<int>(n+1));
        for(int r=0;r<2;r++){
            for(int j=1;j<=n;j++){
                cin >> a[r][j];
            }
        }

        int D = 2*k;
        vector<int> w(D+1,0);
        for(int d = -k+1; d <= k-1; d++){
            int cnt = k - abs(d);
            if(cnt>0) w[d + k] = cnt; 
        }

       
        vector<vector<int>> dp(n+2, vector<int>(n+1,0)), ndp;
       
        dp[1][0] = 1;

      
        int lastNeg = 1;

        for(int i=1;i<=n-1;i++){
    
            ndp.assign(n+2, vector<int>(n+1, 0));
         
            vector<int> prefixMin(n+1, 0);
            prefixMin[0] = dp[i][0];
            for(int h=1; h<=n; h++){
                prefixMin[h] = dp[i][h];
                if(prefixMin[h] > prefixMin[h-1]) 
                    prefixMin[h] = prefixMin[h-1];
            }

            for(int d = -k+1; d <= k-1; d++){
                int ways = w[d + k];
                if(ways==0) continue;
                
                if(d < 0){
                  
                    int sumAll = 0;
                    for(int h=0;h<=n;h++){
                        addmod(sumAll, dp[i][h]);
                    }
                    ndp[i+2][0] = mulmod(sumAll, ways);
                } else {
                    
                    for(int oldh=0; oldh<=n; oldh++){
                        int cur = dp[i][oldh];
                        if(!cur) continue;
                        int newh = max(0, oldh + d);
                        addmod(ndp[i+1][newh], mulmod(cur, ways));
                    }
                }
            }

            dp.swap(ndp);
        }

       
        int total = dp[n+1][0]; 
       
        total = mulmod(total, k); 
        total = mulmod(total, k);  

        cout << total << "\n";
    }

    return 0;
}
