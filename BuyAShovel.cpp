#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll k, r;
    cin >> k >> r;

    ll ans = 1;

    for (int i = 1; i <= 9; i++)
    {
        if ((k * i) % 10 == r)
        {
            ans = i;
            break;
        }
        if ((k * i) % 10 == 0)
        {
            ans = i;
            break;
        }
    }

    cout << ans << nline;
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