#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

//ahana 3
int64 ahana(int64 x) {
    static const int prm[4] = {2, 3, 5, 7};
    __int128 sum = x;  
    for (int j = 1; j < (1 << 4); ++j) {
        __int128 pp = 1;
        int bits = __builtin_popcount(j);
        for (int i = 0; i < 4; ++i) {
            if (j & (1 << i)) {
                pp *= prm[i];
            }
        }
        if (pp > x) continue;
        if (bits & 1) {
            sum -= x / pp;
        } else {
            sum += x / pp;
        }
    }
    return (int64)sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int64 l, r;
        cin >> l >> r;
        int64 ans = ahana(r) - ahana(l - 1);
        cout << ans << "\n";
    }
    return 0;
}
