    #include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll p;
        cin >> p;
     
        for (int i = 0; i < p; i++)
        {
            ll t;
            cin >> t;
     
            arr[t - 1] = 1;
        }
     
        ll q;
        cin >> q;
     
        for (int i = 0; i < q; i++)
        {
            ll t;
            cin >> t;
            arr[t - 1] = 1;
        }
     
        bool haveWon = true;
     
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                haveWon = false;
                break;
            }
        }
     
        if (haveWon)
            cout << "I become the guy.\n";
        else
            cout << "Oh, my keyboard!\n";
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