#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ahana datta code 2 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b > d) {
                ans += a + (b - d);
            } else {
                ans += max(0LL, a - c);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
