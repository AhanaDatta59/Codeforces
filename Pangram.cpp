    #include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        ll n;
        cin >> n;
     
        string s;
        cin >> s;
     
        unordered_set<char> hMap;
        for (int i = 0; i < n; i++)
        {
            hMap.insert(tolower(s[i]));
        }
     
        if (hMap.size() == 26)
            cout << "YES\n";
        else
            cout << "NO\n";
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