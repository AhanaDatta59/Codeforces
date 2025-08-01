#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll maxSub = 0, currCount = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] >= arr[i])
        {
            currCount++;
        }
        else
        {
            maxSub = max(maxSub, currCount);
            currCount = 1;
        }
    }

    maxSub = max(maxSub, currCount);
    cout << maxSub << nline;
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