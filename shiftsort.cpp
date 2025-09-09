#include <bits/stdc++.h>
using namespace std;

//ahana datta code 1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; string s;
        cin >> n >> s;

        int z = count(s.begin(), s.end(), '0');   
        int ans = 0;
        for (int i = 0; i < z; ++i) if (s[i] == '1') ++ans; 
        cout << ans << '\n';
    }
    return 0;
}
