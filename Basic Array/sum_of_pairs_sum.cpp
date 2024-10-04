#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int main() {
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        //equation is = 2 * n * a[i];
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
             sum += 2* n* a[i];
        }
        cout << sum << endl;
    }
}
