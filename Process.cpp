#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        string s;
        s.reserve(n);

        int l = 0, r = n - 1;
        int ahana = 0, datta = 0;
        int xxxx = 0;

        for (int step = 0; step < n; step++) {
            int candL = p[l];
            int candR = p[r];

            int incL = (ahana > 0 && candL > xxxx) ? ahana + 1 : 1;
            int decL = (datta > 0 && candL < xxxx) ? datta + 1 : 1;
            bool safeL = (incL < 5 && decL < 5);

            int incR = (ahana > 0 && candR > xxxx) ? ahana + 1 : 1;
            int decR = (datta > 0 && candR < xxxx) ? datta + 1 : 1;
            bool safeR = (incR < 5 && decR < 5);

            bool riskL = false, riskR = false;

            int nl = l + 1, nr = r;
            if (safeL && nl <= nr) {
                
                if (incL == 4 && p[nl] > candL && p[nr] > candL) {
                    riskL = true;
                }
             
                if (decL == 4 && p[nl] < candL && p[nr] < candL) {
                    riskL = true;
                }
            }

            nl = l; nr = r - 1;
            if (safeR && nl <= nr) {
                if (incR == 4 && p[nl] > candR && p[nr] > candR) {
                    riskR = true;
                }
                if (decR == 4 && p[nl] < candR && p[nr] < candR) {
                    riskR = true;
                }
            }

            char choice;
            if (!safeL && safeR) {
                choice = 'R';
            } else if (!safeR && safeL) {
                choice = 'L';
            } else if (safeL && safeR) {
                
                if (riskL != riskR) {
                    choice = riskL ? 'R' : 'L';
                } else {
                  
                    int maxL = max(incL, decL);
                    int maxR = max(incR, decR);
                    if (maxL < maxR) choice = 'L';
                    else if (maxR < maxL) choice = 'R';
                    else choice = 'L';
                }
            } else {
                choice = 'L';
            }

            if (choice == 'L') {
                xxxx = candL;
                ahana = incL;
                datta = decL;
                l++;
            } else {
                xxxx = candR;
                ahana = incR;
                datta = decR;
                r--;
            }
            s.push_back(choice);
        }

        cout << s << "\n";
    }

    return 0;
}
