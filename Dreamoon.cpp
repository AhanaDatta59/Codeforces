#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;

    if (n == m)
    {
        cout << n << nline;
        return;
    }

    ll ans = m;
    bool hasAns = false;

    ll low = 0, high = n;

    if (n & 1)
        low = (n + 1) / 2;
    else
        low = n / 2;

    while (ans < n)
    {
        if (ans >= low and ans <= high)
        {
            hasAns = true;
            break;
        }

        ans += m;
    }

    if (hasAns)
        cout << ans << nline;
    else
        cout << -1 << nline;
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