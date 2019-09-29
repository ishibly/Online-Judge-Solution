#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 5e4 + 5;
constexpr int LOGN = 18;

int parent[LOGN][N];
int level[N], dist[N];
vector< pair< int, int>> conn[N];

void dfs(int a, int lvl, int prt) {
    level[a] = lvl;
    for (const auto &p : conn[a]) {
        int b = p.first;
        if (prt == b) continue;
        parent[0][b] = a;
        dist[b] = dist[a] + p.second;
        dfs(b, lvl + 1, a);
    }
}

int LCA(int x, int y) {
    if (x == y) return x;
    if (level[x] < level[y]) swap(x, y);

    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[i][x] != -1 && level[parent[i][x]] >= level[y]) {
            x = parent[i][x];
        }
    }

    if (x == y) return x;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    return parent[0][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        conn[a].emplace_back(b, c);
        conn[b].emplace_back(a, c);
    }

    memset(parent, -1, sizeof parent);
    dfs(0, 0, -1);
    for (int log = 1; log < LOGN; log++) {
        for (int i = 0; i < n; i++) {
            if (parent[log - 1][i] != -1) {
                parent[log][i] = parent[log - 1][parent[log - 1][i]];
            }
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int a, b;
        cin >> a >> b;
        int c = LCA(a, b);
        cout << dist[a] - 2 * dist[c] + dist[b] << "\n";
    }
}
