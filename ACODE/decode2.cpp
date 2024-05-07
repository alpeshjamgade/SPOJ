#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            int n = (int)s.size();
            if (s[0] == '0') return 0;
            
            vector<int> dp(n, 0);
            dp[0] = (s[0]=='*'?9:1);

            for (int i = 1; i < n; i++) {
                int x = s[i]-'0';
                int y = (s[i-1]-'0')*10 + x;
                
               
                if (s[i] != '*' && x != 0) dp[i] += dp[i-1];

                if (y >= 10 && y <= 26) dp[i] += dp[i<2?0:i-2];
            }

            return dp[n-1];
        }
};
int main() {

    return 0;
}
