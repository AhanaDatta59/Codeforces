#include <bits/stdc++.h>
using namespace std;

//ahana code last
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        long long sum = 0;
        long long fff = -1;
        bool aleqq = true;

        if (n == 1) { // come back here
            long long x; cin >> x;
            cout << x << '\n';
            continue;
        }

        if (n == 2) {
            long long x, y; cin >> x >> y;
            sum = x + y;
            cout << (sum - (sum & 1LL)) << '\n';
            continue;
        }

        for (int i = 0; i < n; ++i) {
            long long x; cin >> x;
            sum += x;
            if (i == 0) fff = x;
            else if (x != fff) aleqq = false;
        }

        if (aleqq) cout << sum << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
