#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main() {
    opt();
    int t;
    t = 1;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll xor_value = 0;
        for (int i = 0; i < n; ++i) {
            ll x = (i) * (n - i + 1);
            if (x % 2 != 0) {
                xor_value ^= a[i];
            }
        }
        cout << xor_value << endl;
    }
}
