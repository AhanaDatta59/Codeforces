#include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        ll n;
        cin >> n;
        ll sumX = 0, sumY = 0, sumZ = 0;
     
        for (int i = 0; i < n; i++) 
        {
            ll x, y, z;
            cin >> x >> y >> z;
     
            sumX += x;
            sumY += y;
            sumZ += z;
        }
        if (sumX == 0 && sumY == 0 && sumZ == 0)
            cout << "YES" << nline;
        else
            cout << "NO" << nline;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll T = 1;
        while (T--) 
        {
            solve();
        }
    }