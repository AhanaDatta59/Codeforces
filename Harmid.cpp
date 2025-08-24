#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ahana code 2

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
     
        int pos = x - 1;

        const int INF = n + 5;
        int ahanaL = INF, ahanaR = INF;

        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] == '#') {
                ahanaL = pos - i;
                break;
            }
        }
     
        for (int i = pos + 1; i < n; ++i) {
            if (s[i] == '#') {
                ahanaR = i - pos;
                break;
            }
        }

        if (ahanaL == INF || ahanaR == INF) {
            cout << 1 << "\n";
        } else {
            int d = min(ahanaL, ahanaR);
            
            cout << (2 * d + 1) << "\n";
        }
    }

    return 0;
}
