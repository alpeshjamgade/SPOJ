#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll calculateDecodings(string &s) {
    int n = (int)s.size(); 
    vector<ll> dp(n, 0);
    dp[0] = 1;
    
    if (s[0] == '0') return 0;

    for (int i = 1; i < n; i++) {
        int x = s[i] - '0';
        int y = (s[i-1] - '0')*10 + x;

        // is it possibel to form two digit number?
        if (y >= 10 && y <= 26) {
            dp[i] += dp[i<2?0:i-2];
        }
        
        // is it possible to from single digit number?
        if (x != 0) {
            dp[i] += dp[i-1];
        }
    }
    return dp[n-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        string s; cin >> s;
        if (s == "0") break;

        cout << calculateDecodings(s) << '\n';
    }
    return 0;
}
