#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ahana 2
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];

        sort(g.begin(), g.end(), greater<long long>());

        long long ahana = 0;
        for (int i = 0; i < n; i += 2) ahana += g[i];

        cout << ahana << '\n';
    }
    return 0;
}
