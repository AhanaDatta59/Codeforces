#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    string s = to_string(n);

    for (int i = s.size() - 1; i >= 0; i--)
    {
        int sOfI = int(s[i] - 48);
        if (sOfI >= 5 and sOfI <= 9 and i != 0)
        {
            sOfI = 9 - sOfI;
        }
        if (i == 0 and sOfI < 9 and sOfI >= 5)
        {
            sOfI = 9 - sOfI;
        }
        s[i] = char(sOfI + 48);
    }

    cout << s << nline;
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