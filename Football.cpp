    #include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        string s;
        getline(cin, s);
        int count = 0, i = 0;
        bool flag = false;
        if (s.size() < 7)
            cout << "NO" << nline;
        else
        {
            while (s[i] != '\0')
            {
                if (s[i] == '1') {
     
                    while (s[i] == '1')
                    {
                        count++;
                        i++;
                    }
                }
                else {
                    while (s[i] == '0')
                    {
                        count++;
                        i++;
                    }
                }
     
                if (count >= 7)
                {
                    flag = true;
                    break;
                }
                count = 0;
            }
     
            if (flag)
                cout << "YES" << nline;
            else
                cout << "NO" << nline;
        }
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