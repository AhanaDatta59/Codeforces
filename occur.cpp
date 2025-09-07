#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ahana code 3
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        //case ahana
        vector<vector<int>> ahana(n + 1);
        for (int i = 0; i < n; ++i) {
            if (b[i] < 1 || b[i] > n) {
                cout << -1 << '\n';
                goto next_case; 
            }
            ahana[b[i]].push_back(i);
        }

        //vector analysis 
        {
            vector<int> a(n, 0);
            int datta = 0;
            bool ok = true;

            for (int k = 1; k <= n && ok; ++k) {
                int m = (int)ahana[k].size();
                if (m % k != 0) {
                    cout << -1 << '\n';
                    ok = false;
                    break;
                }
                for (int i = 0; i < m; i += k) {
                    ++datta; 
                    for (int j = 0; j < k; ++j) {
                        a[ahana[k][i + j]] = datta;
                    }
                }
            }

            //output 
            if (ok) {
                for (int i = 0; i < n; ++i) {
                    if (i) cout << ' ';
                    cout << a[i];
                }
                cout << '\n';
            }
        }

        continue;
    next_case:
        ;
    }
    return 0;
}
