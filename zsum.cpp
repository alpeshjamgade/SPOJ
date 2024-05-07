#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e8, mod = 1e9+7;

ll modexp(int base, int exponent, int mod) {
    base %= mod;

    ll res = 1;
    
    while (exponent > 0) {
        if (exponent & 1) {
            res = res * base % mod;

        }
        base = base * base % mod;
        exponent >>= 1;
    }

    return res;
}

int calc(int n, int k) {

    ll zn = 0, zn_1=0, zn_2=0, si = 0, pi = 0;
    for (int i = 1; i <= n; i++) {
        si = (si + modexp(n, k, mod)) % mod;
        pi = (pi + modexp(n, n, mod)) % mod;

        if (i == n-2) {
           zn_2 = (si + pi ) % mod;
        }
        
        if (i == n-1) {
            zn_1 = (si + pi) % mod;
        }
    }
    
    zn = (si + pi)%mod;
    return (zn + zn_1 - 2*zn_2) % mod;
}
int main() {
    int n, k; 
    
    cin >> n >> k; 
    while (n && k) {
        cout << calc(n, k);
        cin >> n >> k;

        cout << calc(n, k) << '\n';
    }
}
