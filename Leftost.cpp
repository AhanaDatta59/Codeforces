#include <bits/stdc++.h>
using namespace std;

// ahana datta 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long datta = b[0];
        bool yesyes = true;

        for (int i = 1; i < n; i++) {
            long long ahana = (b[i] + 2) / 2;
            if (ahana > datta) {
                yesyes = false;
                break;
            }
            datta = min(datta, b[i]);
        }

        cout << (yesyes ? "YES\n" : "NO\n");
    }
    return 0;
}
