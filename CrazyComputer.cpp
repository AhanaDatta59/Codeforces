    #include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        ll n, c;
        cin >> n >> c;
        ll arr[n];
     
        for (int i = 0; i < n; i++)
            cin >> arr[i];
     
        ll res = 0;
     
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] <= c)
                res++;
            else
                res = 0;
        }
        cout << res + 1 << nline;
     
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