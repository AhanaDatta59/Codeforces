#include <bits/stdc++.h>
using namespace std;

//ahana code 3
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        long long a, b;
        cin >> a >> b;

        if (b & 1LL) { 
            if ((a & 1LL) == 0) {
                cout << -1 << '\n';
            } else {
                __int128 ahana = (__int128)a * b + 1;
                cout << (long long)ahana << '\n';
            }
        } else {
            if ((b % 4 == 2) && (a % 2 == 1)) {
                cout << -1 << '\n';
            } else {
                __int128 ahana = (__int128)a * (b / 2) + 2;
                cout << (long long)ahana << '\n';
            }
        }
    }
    return 0;
}
