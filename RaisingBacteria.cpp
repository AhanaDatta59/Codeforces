#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll countOf1 = 0;

    while (n > 0)
    {
        if (n & 1)
            countOf1++;
        n = n >> 1;
    }
    cout << countOf1 << nline;
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