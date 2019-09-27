#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 1006;

vector< int> parent[N], child[N];
bitset< N> up, down;

void go_up(int a) {
    if (up[a]) return;
    up[a] = true;
    for (const int &b : parent[a]) {
        go_up(b);
    }
}

void go_down(int a) {
    if (down[a]) return;
    down[a] = true;
    for(const int &b : child[a]) {
        go_down(b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    string x, y;
    while (cin >> x) {
        if (x == "BLOOD") break;
        cin >> y;
        int a = stoi(x);
        int b = stoi(y);
        parent[a].push_back(b);
        child[b].push_back(a);
    }

    int v;
    while (cin >> v) {
        go_up(v);
        go_down(v);
    }

    bool f = false;
    for (int i = 1; i <= n; i ++) {
        if (up[i] or down[i]) continue;
        cout << i << ' ';
        f = true;
    }
    if (!f) cout << 0 << endl;
}
