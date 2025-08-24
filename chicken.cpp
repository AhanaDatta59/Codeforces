#include <bits/stdc++.h>
using namespace std;

//ahana 4
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<long long> h(n + 1);
        for (int i = 1; i <= n; ++i) cin >> h[i];

        long long sumH = 0;
        for (int i = 1; i <= n; ++i) sumH += h[i];

        long long ahana = 0;      
        long long datta = 0;    

        for (int j = n; j >= 2; --j) {
            long long capHere = min(h[j], (long long)(j - 1));        
            long long abcdef = (long long)(j - 1) - ahana;        
            if (abcdef < 0) abcdef = 0;
            long long takeHere = min(capHere, abcdef);               
            datta += takeHere;
            ahana = takeHere;                                      
        }

        long long ans = sumH - datta;
        cout << ans << '\n';
    }
    return 0;
}
