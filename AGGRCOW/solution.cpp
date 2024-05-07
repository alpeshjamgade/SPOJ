#include <bits/stdc++.h>

using namespace std;

bool isOK(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    
    while(tt--) {
        int n, c;
        cin >> n >> c;

        vector<int> stalls(n);
        for(int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        sort(stalls.begin(), stalls.end());

        int low = 1, high = stalls[n-1]-stalls[0];

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isOK(stalls, mid, c)) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
       
        cout << high << '\n';
    }

    return 0;
}
