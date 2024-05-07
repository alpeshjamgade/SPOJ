#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c; cin >> a >> b >> c;
    while(a!=0 && b!=0 && c!=0) {
        if (b-a == c-b) {
            cout << "AP " << c + b - a << '\n';
        } else {
            cout << "GP " << c * b/a << '\n';
        }
        cin >> a >> b >> c;
    }
    return 0;
}
