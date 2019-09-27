#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 20;
bitset< N * 3> seen;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector< vector< int>> in(n, vector< int>(3, 0));

    map< string, int> mp;
    int k = 0;

    for (int i = 0; i < n; i ++) {
        string x, y, z;
        cin >> x >> y >> z;
        if (mp.find(x) == mp.end()) mp[x] = k ++;
        if (mp.find(y) == mp.end()) mp[y] = k ++;
        if (mp.find(z) == mp.end()) mp[z] = k ++;
        in[i] = {mp[x], mp[y], mp[z]};
    }

    int mx = 0;
    for (int i = 1; i < (1 << n); i++) {
        seen.reset();
        bool ok = true;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            if (seen[in[j][0]] or seen[in[j][1]] or seen[in[j][2]]) ok = false;
            seen[in[j][0]] = seen[in[j][1]] = seen[in[j][2]] = 1;
        }
        if (ok) {
            mx = max(mx, __builtin_popcount(i));
        }
    }
    cout << mx << endl;
}
