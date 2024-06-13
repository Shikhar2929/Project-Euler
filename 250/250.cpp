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
const long long MOD = 1e16;
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

//Function that computes the number of elements whose sum is divisible by 250
long long compute(int index, int mod) {
    vector<long long> arr(mod, 0);
    arr[0] = 1;
    for (int i = 1; i <= index; i++) {
        int val = modExp(i, i, mod);
        vector<long long> temparr(mod, 0);
        for (int j = 0; j < mod; j++) {
            int newIndex = (val + j) % mod;
            temparr[newIndex] = (arr[j] + arr[newIndex]) % MOD;
        }
        for (int j = 0; j < mod; j++)
            arr[j] = temparr[j];
    }
    return arr[0] - 1;
}

int main() {
    cout << compute(250250, 250) << endl; 
}