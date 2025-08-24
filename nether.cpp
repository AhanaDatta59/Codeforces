#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> len(n+1);
        for (int i=1; i<=n; i++) {
            cout << "? " << i << " " << n;
            for (int j=1; j<=n; j++) {
                cout << " " << j;
            }
            cout << endl;
            cout.flush();
            cin >> len[i];
            if (len[i] == -1) {
                return 0;
            }
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return len[a] > len[b];
        });
        vector<int> path = {order[0]};
        for (int i=1; i<n; i++) {
            int u = order[i];
            cout << "? " << u << " " << path.size()+1;
            cout << " " << u;
            for (int node : path) {
                cout << " " << node;
            }
            cout << endl;
            cout.flush();
            int res;
            cin >> res;
            if (res == -1) {
                return 0;
            }
            if (res == path.size() + 1) {
                path.insert(path.begin(), u);
            }
        }
        cout << "! " << path.size();
        for (int node : path) {
            cout << " " << node;
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}