#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
    
        for (int i = 0; i < n; i++) {
            cout << p[i] << (i+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
