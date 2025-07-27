#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MAXN = 500000 + 5;
int p[MAXN], ahana[MAXN], datta[MAXN], nxt[MAXN], smallsmall[MAXN], st[MAXN];

//ahana datta
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> p[i];

        for (int i = 1; i <= n; i++) 
            datta[i] = -1;

        int st_sz = 0;
        for (int i = 1; i <= n; i++) {
            while (st_sz > 0 && p[st[st_sz-1]] <= p[i]) 
                st_sz--;
            ahana[i] = (st_sz==0 ? 0 : st[st_sz-1]);
            st[st_sz++] = i;
            if (ahana[i] != 0) {
                nxt[i] = datta[ahana[i]];
                datta[ahana[i]] = i;
            }
        }

        ll ansans = 0;
        for (int i = n; i >= 1; i--) {
            int sz = 1;
            for (int c = datta[i]; c != -1; c = nxt[c])
                sz += smallsmall[c];
            smallsmall[i] = sz;
            ansans += ll(i) * sz;
        }

        cout << ansans << "\n";
    }
    return 0;
}
