#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>&arr, int start, int mid, int end) {

}

int mergeSort(int start, int end, vector<int> &arr) {
    if (start >= end) {
        return 0;
    }

    int mid = (start + end) >> 1;
    int count = 0; 
    count += mergeSort(start, mid, arr);
    count += mergeSort(mid+1, end, arr);
    count += merge(arr, start, mid, end);

    return count;
}

int countInversions(vector<int> &arr, int n) {
    return mergeSort(0, n-1, arr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << countInversions(arr, n) << '\n';
    }

    return 0;
}
