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
        sort(a.begin(), a.end());
        //equatiom = (a[j] -a[i]) * (2^j - i - 1)
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += ((a[j] - a[i]) * pow (2, j - i - 1));
            }
        }
        cout << ans << endl;
    }
}

