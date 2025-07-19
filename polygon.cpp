#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>a(n);
    int S = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        S += a[i];
    }


    vector<pair<int,int>> P;
   
    for(int i = 0; i <= n; i++){
        P.emplace_back(2*i, 0);
    }
   
    for(int i = n; i >= 1; i--){
        for(int y = 1; y <= a[i-1]; y++){
            P.emplace_back(2*i - 1, y);
        }
    }

  
    cout << P.size() << "\n";
    for(auto &pt: P){
        cout << pt.first << " " << pt.second << "\n";
    }
    return 0;
}
