#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

ll getBottles(vector<ll> &arr, ll m)
{
    ll n = arr.size();
    ll low = 0, high = n - 1;
    ll ans = 0;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] <= m) {
            ans = mid + 1;
            low = mid + 1;
        }
        else if (arr[mid] > m)
            high = mid - 1;
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll q;
    cin >> q;

    while (q--)
    {
        ll m;
        cin >> m;
        cout << getBottles(arr, m) << nline;
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