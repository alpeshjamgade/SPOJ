#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct sgt {
    ll best, total, prefix, suffix;

};

void build(int node, int start, int end, vector<ll> &arr, vector<sgt> &tree) {
    if (start == end) {
    
        tree[node].best = arr[start];
        tree[node].total = arr[start];
        tree[node].prefix = arr[start];
        tree[node].suffix = arr[start];
 
        return;
    }

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    build(leftNode, start, mid, arr, tree);
    build(rightNode, mid+1, end, arr, tree);

    tree[node].total = tree[leftNode].total + tree[rightNode].total;
    tree[node].best = max(tree[leftNode].suffix + tree[rightNode].prefix, max(tree[leftNode].best, tree[rightNode].best));
    tree[node].prefix = max(tree[leftNode].prefix, tree[leftNode].total + tree[rightNode].prefix);
    tree[node].suffix = max(tree[rightNode].suffix, tree[rightNode].total + tree[leftNode].suffix);
    return;
}

sgt query(int x, int y, int node, int start, int end, vector<ll> &arr, vector<sgt> &tree) {
    
    sgt result;
    if (y < start || x > end) {
        result.total = result.best = result.prefix = result.suffix = INT_MIN;
        return result;
    }
    if (start >= x && end <= y) return tree[node];

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    sgt leftResult = query(x, y, leftNode, start, mid, arr, tree);
    sgt rightResult = query(x, y, rightNode, mid+1, end, arr, tree);

    result.total = leftResult.total + rightResult.total;
    result.best = max(leftResult.suffix + rightResult.prefix, max(leftResult.best, rightResult.best));
    result.prefix = max(leftResult.prefix, leftResult.total + rightResult.prefix);
    result.suffix = max(rightResult.suffix, rightResult.total + leftResult.suffix);

    return result;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n;
    vector<ll> arr(n);
    vector<sgt> tree(4*n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1, arr, tree);

    cin >> m;
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;

        sgt result = query(x, y, 1, 0, n-1, arr, tree);
        cout << result.best << '\n';
    }
    return 0;
}
