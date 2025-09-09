#include <bits/stdc++.h>
using namespace std;

//ahana code 2  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end(), greater<long long>());
        int k = (int)min<long long>(n, m);

        __int128 ahaana = 0;
        for (int j = 0; j < k; ++j) {
            ahaana += (__int128)a[j] * (m - j);
        }

        long long out = (long long)ahaana;
        cout << out << '\n';
    }
    return 0;
}
