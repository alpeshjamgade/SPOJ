#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll merge(vector<int>&arr, vector<int> &tmp, int start, int mid, int end) {
    int i = start, j = mid+1, k = start;
    ll count = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
                count += (mid - i + 1);
            tmp[k++] = arr[j++];
        }
    }

    while (i <= mid) tmp[k++] = arr[i++];

    for (int i = start; i <= end; i++) arr[i] = tmp[i];

    return count;
}

ll mergeSort(int start, int end, vector<int> &arr, vector<int> &tmp) {
    if (start == end) {
        return 0;
    }

    int mid = (start + end) >> 1;
    ll count = 0;
    count += mergeSort(start, mid, arr, tmp);
    count += mergeSort(mid+1, end, arr, tmp);
    count += merge(arr, tmp, start, mid, end);

    return count;
}

ll countInversions(vector<int> &arr, vector<int> &tmp, int n) {
    return mergeSort(0, n-1, arr, tmp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n), tmp(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            tmp[i] = arr[i];
        }

        cout << countInversions(arr, tmp, n) << '\n';
    }

    return 0;
}
