#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6;
map<ll, ll> dp;

ll solve(ll n) {
    // Do you remember why you used map instead of array?
    if(dp[n]) return dp[n];
    if (n <= 11) return dp[n]=n;
         
    dp[n] = max(n, solve(n/2)+solve(n/3)+solve(n/4));
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    while (cin >> n) {
        cout << solve(n) << '\n';
    }
    return 0;
}
