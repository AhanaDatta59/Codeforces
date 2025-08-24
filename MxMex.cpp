#include <bits/stdc++.h>
using namespace std;
//ahana code 1
//ahana compute
int mex3(int x, int y, int z) {
    bool present[4] = {false, false, false, false};
    if (0 <= x && x < 4) present[x] = true;
    if (0 <= y && y < 4) present[y] = true;
    if (0 <= z && z < 4) present[z] = true;
    for (int i = 0; i < 4; i++) {
        if (!present[i]) return i;
    }
    return 4; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b = a; 

        bool datta = false;
        bool ahana = true;

        while (ahana && !datta) {
            ahana = false;
            for (int i = 0; i + 2 < n; i++) {
                int missmiss = 0;
                for (int j = i; j < i + 3; j++) {
                    if (b[j] == -1) missmiss++;
                }
               
                if (missmiss == 3) {
                    continue;
                }
               
                if (missmiss == 0) {
                    int x = b[i], y = b[i+1], z = b[i+2];
                    int mn = min(x, min(y, z));
                    int mx = max(x, max(y, z));
                    int m = mex3(x, y, z);
                    if (m != mx - mn) {
                        datta = true;
                        break;
                    }
                } else {
                    
                    int needVal = -1;
                    if (missmiss == 2) {
                        
                        for (int j = i; j < i + 3; j++) {
                            if (b[j] != -1) {
                                needVal = b[j];
                                break;
                            }
                        }
                        
                        if (needVal <= 0) {
                            datta = true;
                            break;
                        }
                    } else { 
                       
                        int p = -1, q = -1;
                     
                        if (b[i] != -1 && b[i+1] != -1) {
                            p = b[i];
                            q = b[i+1];
                        } else if (b[i] != -1 && b[i+2] != -1) {
                            p = b[i];
                            q = b[i+2];
                        } else {
                            p = b[i+1];
                            q = b[i+2];
                        }
                        if (p != q || p <= 0) {
                            datta = true;
                            break;
                        }
                        needVal = p;
                    }
                   
                    for (int j = i; j < i + 3; j++) {
                        if (b[j] == -1) {
                            b[j] = needVal;
                            ahana = true;
                        }
                    }
                }
            }
        }

        if (datta) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                b[i] = 1;
            }
        }

        bool ok = true;
        for (int i = 0; i + 2 < n; i++) {
            int x = b[i], y = b[i+1], z = b[i+2];
            int mn = min(x, min(y, z));
            int mx = max(x, max(y, z));
            int m = mex3(x, y, z);
            if (m != mx - mn) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}

//ahana code end 
