#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ahana datta

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ahana = 0;
        int datta = 1, ah_da = k;

        auto run = [&](int m) {
            if (m > n) return;
          
            int l_s_s = (m + 2) / 2;

            vector<int> tmp(a.begin(), a.begin() + m);
            sort(tmp.begin(), tmp.end());
            multiset<int> low, high;
            for (int i = 0; i < l_s_s; i++) 
                low.insert(tmp[i]);
            for (int i = l_s_s; i < m; i++) 
                high.insert(tmp[i]);

            int hi = *prev(low.end());
            if (hi > ahana) {
                ahana = hi;
                datta = 1;
                ah_da = m;
            }

            for (int i = m; i < n; i++) {
                int out = a[i - m];
                int in  = a[i];

                auto it_low = low.find(out);
                if (it_low != low.end()) {
                    low.erase(it_low);
                } else {
                    high.erase(high.find(out));
                }

                if (!low.empty() && in <= *prev(low.end())) {
                    low.insert(in);
                } else {
                    high.insert(in);
                }

                if ((int)low.size() < l_s_s) {
                    auto it = high.begin();
                    low.insert(*it);
                    high.erase(it);
                } else if ((int)low.size() > l_s_s) {
                    auto it = prev(low.end());
                    high.insert(*it);
                    low.erase(it);
                }

                hi = *prev(low.end());
                if (hi > ahana) {
                    ahana = hi;
                    datta = i - m + 2;  
                    ah_da = i + 1;
                }
            }
        };

        run(k);
       
        if (k % 2 == 1) {
            run(k + 1);
        }

        cout << ahana << " " << datta << " " << ah_da << "\n";
    }

    return 0;
}
