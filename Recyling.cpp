#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> ahana;
        ahana.reserve(n);
        for (auto x : a) {
            long long w = x;
            int k = 0;
            while (w <= c) {
                w <<= 1;
                k++;
            }
          
            ahana.push_back(k);
        }

        sort(ahana.begin(), ahana.end());

        int datta = 0;
        for (auto d : ahana) {
            if (datta + 1 <= d) {
                datta++;
            }
        }

        cout << (n - datta) << "\n";
    }

    return 0;
}
