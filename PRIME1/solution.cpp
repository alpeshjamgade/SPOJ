#include <bits/stdc++.h>

using namespace std;

bool isPrime(long x) {
    if (x == 1) return false;
    if (x == 2) return true;

    for (long i = 2; i*i <= x; i++) {
        if (x%i==0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    
    while (t--) {
        long m, n; cin >> m >> n;

        for (long i = m; i <= n; i++) {
            if (isPrime(i)) {
                cout << i << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
