#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Pt {
    int id;
    ll x, y, u, v;
};

// ahana datta code 3

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Pt> pts(n);
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            pts[i] = {i+1, x, y, x + y, x - y};
        }
 
        vector<int> indexU(n), indexV(n);
        iota(indexU.begin(), indexU.end(), 0);
        iota(indexV.begin(), indexV.end(), 0);

        sort(indexU.begin(), indexU.end(),
             [&](int a, int b){
                 if (pts[a].u != pts[b].u)
                     return pts[a].u < pts[b].u;
                 return pts[a].v < pts[b].v;
             });

        sort(indexV.begin(), indexV.end(),
             [&](int a, int b){
                 if (pts[a].v != pts[b].v)
                     return pts[a].v < pts[b].v;
                 return pts[a].u < pts[b].u;
             });

        vector<pair<int,int>> mU, mV;
        mU.reserve(n/2);
        mV.reserve(n/2);

        ll sumU = 0, sumV = 0;
        for (int i = 0; i < n/2; i++) {
            int a = indexU[i], b = indexU[n-1-i];
            mU.emplace_back(pts[a].id, pts[b].id);
            sumU += llabs(pts[a].x - pts[b].x)
                  + llabs(pts[a].y - pts[b].y);

            a = indexV[i]; b = indexV[n-1-i];
            mV.emplace_back(pts[a].id, pts[b].id);
            sumV += llabs(pts[a].x - pts[b].x)
                  + llabs(pts[a].y - pts[b].y);
        }

        if (sumU >= sumV) {
            for (auto &p : mU)
                cout << p.first << " " << p.second << "\n";
        } else {
            for (auto &p : mV)
                cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}
