#include <bits/stdc++.h>
using namespace std;

//ahana 1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> fr(26, 0);
        for (char c : s) 
            fr[c - 'A']++;

        string ans;
        ans.reserve(s.size());

        ans.append(fr['T' - 'A'], 'T');
        
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (c == 'T' || c == 'F' || c == 'N') continue;
            ans.append(fr[c - 'A'], c);
        }
        
        ans.append(fr['F' - 'A'], 'F');
        ans.append(fr['N' - 'A'], 'N');

        cout << ans << "\n";
    }

    return 0;
}
