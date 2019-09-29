#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 5;
int g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    stack< pair< char, int> > stk;
    int ghost = 0, buster = 0;
    for (int i = 0; i < 2 * n; i++) {
        char c = s[i];
        if (islower(c)) {
            ++ghost;
            if (!stk.empty() && stk.top().first != c && tolower(stk.top().first) == c) {
                g[stk.top().second] = ghost;
                stk.pop();
            }
            else {
                stk.push({c, ghost});
            }
        } else {
            ++buster;
            if (!stk.empty() && stk.top().first != c && toupper(stk.top().first) == c) {
                g[buster] = stk.top().second;
                stk.pop();
            }
            else {
                stk.push({c, buster});
            }
        }
    }
    if (!stk.empty()) cout << "Impossible\n";
    else {
        for (int i = 1; i <= n; i++) cout << g[i] << ' ';
    }
}
