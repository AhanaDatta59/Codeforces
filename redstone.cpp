#include <bits/stdc++.h>
using namespace std;

// ahana code 1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    
    //loop 
    while (t--) {
        int n; 
        cin >> n;
        bool ok = false;
        vector<int> ahana(101, 0); 
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (++ahana[x] >= 2) ok = true;  
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
