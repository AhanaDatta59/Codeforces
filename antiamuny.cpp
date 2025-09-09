#include <bits/stdc++.h>
using namespace std;

//ahana code 4
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

    
        vector<int> pref(max(1, n - 1) + 1, 0); 
        for (int i = 1; i + 2 <= n; ++i) {
            pref[i] = pref[i - 1] + (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
        }

        while (q--) {
            int l, r; 
            cin >> l >> r;
            if (r - l + 1 < 3) {
                cout << "YES\n";
                continue;
            }
    
            int cnt = pref[r - 2] - pref[l - 1];
            cout << (cnt == 0 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
