#include <bits/stdc++.h>
using namespace std;

//ahana code 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << (n + 1 - p[i]);
        }
        cout << '\n';
    }
    return 0;
}
