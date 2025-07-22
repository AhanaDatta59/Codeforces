#include <bits/stdc++.h>
using namespace std;
using int64 = long long;


//ahana 2
inline __int128 ceil_div(__int128 a, __int128 b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int64 a, b, k;
        cin >> a >> b >> k;

        int64 g = std::gcd(a, b);
        __int128 nX = ceil_div((__int128)a, (__int128)k);
        __int128 nY = ceil_div((__int128)b, (__int128)k);

        if ((__int128)g >= max(nX, nY)) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }

    return 0;
}
