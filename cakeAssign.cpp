#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        long long k;
        unsigned long long x;
        cin >> k >> x;

        unsigned long long S = 1ULL << (k + 1);   
        unsigned long long A = x, B = S - x;    

        vector<int> ahanadatta;  
        while (A != B) {
            if (A < B) {
               
                ahanadatta.push_back(1);
                B -= A;           
                A <<= 1;          
            } else {
              
                ahanadatta.push_back(2);
                A -= B;           
                B <<= 1;         
            }
        }

       
        cout << ahanadatta.size() << "\n";
        for (int i = (int)ahanadatta.size() - 1; i >= 0; --i) {
            cout << ahanadatta[i] << (i ? ' ' : '\n');
        }
        if (ahanadatta.empty()) cout << flush; 
    }
    return 0;
}
