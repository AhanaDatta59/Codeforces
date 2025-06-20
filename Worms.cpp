#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline endl

ll getUpperBound(ll *arr, ll n, ll x)
{
    ll low = 0, high = n - 1;
    ll UB = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            UB = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return UB;
}
void solve()
{
    ll n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        if (i == 0)
            arr[i] = temp;
        else
            arr[i] = arr[i - 1] + temp;
    }

    ll k;
    cin >> k;
    while (k--)
    {
        ll q;
        cin >> q;

        ll uppBound = getUpperBound(arr, n, q);
        cout << uppBound + 1 << nline;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    while (t--)
    {
        solve();
    }
}