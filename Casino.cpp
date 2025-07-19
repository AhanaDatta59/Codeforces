#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i];
        }

        int ans = 0;
        int i = 1;
      
        while (i <= n - k + 1) {
          
            if (p[i + k - 1] - p[i - 1] == 0) {
                ans++;
              
                i += k + 1;
            } else {
                i++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
