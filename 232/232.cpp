#include "bits/stdc++.h"
#define vt vector
#define as assign
#define rsz resize
#define ub upper_bound
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pil pair<int, ll>
using namespace std;

int main () {
    // https://projecteuler.net/problem=232
    const int MAX_SIZE = 100;
    vector<vector<double>> dp(vector<vector<double>>(MAX_SIZE + 1, vector<double>(MAX_SIZE + 1, 0.0)));
    for (int i = 0; i <= MAX_SIZE; i++) {
        dp[i][MAX_SIZE] = 1.0;
    }
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        for (int j = MAX_SIZE - 1; j >= 0; j--) {
            for (int k = 1; k <= 8; k++) {
                double divisor = (double) ((1 << (k + 1)) - (1 << k) + 1);
                if (divisor == 0.0) continue;
                double prod1 = (double) ((1 << k) - 1);
                double powK = 1 << (k - 1);
                double term1 = j + powK <= MAX_SIZE ? dp[i + 1][j + powK] : 1;
                double term2 = j + powK <= MAX_SIZE ? dp[i][j + powK] : 1;
                dp[i][j] = max(dp[i][j], (term1 + term2 + prod1 * dp[i + 1][j]) / divisor);
            }
        }
    }
    double ans = dp[0][0] * 0.5 + dp[1][0] * 0.5;
    cout << fixed << setprecision(8) << ans << endl;
}