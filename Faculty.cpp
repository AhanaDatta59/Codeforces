#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int T = 1000; // threshold for small divisors
    vector<ll> bestMod(T + 1, 0LL);
    set<ll> seen;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        seen.clear();
        fill(bestMod.begin(), bestMod.end(), 0);
        ll ans = 0;
        ll maxSoFar = 0;

        for (int i = 0; i < n; i++) {
            ll v = a[i];
            ll A = 0, B = 0;

            if (!seen.empty()) {
                // Check for x < v
                auto it = seen.lower_bound(v);
                if (it != seen.begin()) {
                    auto prevIt = prev(it);
                    if (*prevIt * 2 > v) {
                        A = v;
                    }
                }
                if (A < v) {
                    // Brute force small x
                    for (int x = 1; x <= T && x < v; x++) {
                        if (seen.count(x)) {
                            A = max(A, x + (v % x));
                        }
                    }

                    // Division blocks for large x
                    for (ll k = 1; ; k++) {
                        ll r = v / k;
                        if (r <= T) break;
                        ll l = v / (k + 1) + 1;
                        if (l > r) continue;
                        auto itl = seen.lower_bound(l);
                        if (itl != seen.end() && *itl <= r) {
                            A = max(A, *itl + (v % *itl));
                        }
                    }
                }

                // Check for x > v
                if (v <= T) {
                    B = v + bestMod[v];
                } else {
                    ll maxK = maxSoFar / v;
                    for (ll k = 1; k <= maxK; k++) {
                        ll hi = k * v + v - 1;
                        auto it2 = seen.upper_bound(hi);
                        if (it2 == seen.begin()) continue;
                        --it2;
                        ll x = *it2;
                        if (x >= k * v) {
                            B = max(B, v + (x % v));
                        }
                    }
                }
            }

            ans = max(ans, max(A, B));
            cout << ans << (i + 1 == n ? '\n' : ' ');

            // Update structures
            seen.insert(v);
            maxSoFar = max(maxSoFar, v);
            for (int d = 1; d <= T; d++) {
                bestMod[d] = max(bestMod[d], v % d);
            }
        }
    }

    return 0;
}
