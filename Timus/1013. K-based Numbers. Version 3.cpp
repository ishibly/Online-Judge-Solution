/// http://www.programmersought.com/article/6886674750/
#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 5;

LL n, k, mod;

LL multiply(LL a, LL b) {
    LL rv = 0;
    while (b) {
        if (b & 1) rv = (rv + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return rv;
}

void matMul(LL A[2][2], LL B[2][2]) {
    LL C[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += multiply(A[i][k], B[k][j]);
                C[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) A[i][j] = C[i][j];
}

void matPow(LL A[2][2], LL p) {
    LL result[2][2] = {1, 0, 0, 1};
    while (p > 0) {
        if (p & 1) matMul(result, A);
        matMul(A, A);
        p /= 2;
    }
    for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++) A[i][j] = result[i][j];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> mod;
    LL A[2][2] = {k - 1, k - 1, 1, 0};
    LL B[2] = {k - 1, 0};

    matPow(A, n - 1);

    LL result = (multiply(A[0][0], k - 1) + multiply(A[1][0], k - 1)) % mod;
    cout << result << "\n";
}
