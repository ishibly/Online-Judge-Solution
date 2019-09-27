#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 3005;

int n, m;
const int d[] = { -1, 0, 1, 0};
bitset< N> in[N];
bitset< N> seen[N];
int mnx, mny, mxx, mxy;

void bfs(int a, int b) {
    queue< pair< int, int>> q;
    q.emplace(a, b);
    seen[a][b] = true;


    while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = a + d[i];
            int y = b + d[i ^ 1];
            if (x < 0 or y < 0 or x >= n or y >= m) continue;
            if (seen[x][y]) continue;
            if (in[x][y] == false) continue;
            q.emplace(x, y);
            seen[x][y] = true;
            mnx = min(x, mnx);
            mxx = max(x, mxx);
            mny = min(y, mny);
            mxy = max(y, mxy);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        seen[i].reset();
        in[i].reset();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            in[i][j] = x;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (in[i][j] == true && seen[i][j] == false) {
                mxx = mnx = i;
                mxy = mny = j;
                bfs(i, j);
                for (int x = mnx; x <= mxx; x++) {
                    for (int y = mny; y <= mxy; y++) {
                        if (in[x][y] == 0) return cout << "No\n", 0;
                    }
                }
            }
        }
    }
    cout << "Yes\n";
}
