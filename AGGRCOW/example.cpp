#include<bits/stdc++.h>
using namespace std;

bool isOK(int d, vector<int> &stalls, int c) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i]-last >= d) {
            cntCows++;
            last = stalls[i];
        }

        if (cntCows == c) return true;
    }
    return false;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, c; cin >> n >> c;
        vector<int> stalls(n);

        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        sort(stalls.begin(), stalls.end());

        // apply binary search between min and max distance.
        int low = 1; // lowest possible distance;
        int high = stalls[n-1] - stalls[0];

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isOK(mid, stalls, c)) {
                low = mid + 1;
            } else high = mid - 1;
        }

        cout << high << '\n';
    }
}
