#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

vector<ll> getDivisors(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());  
    return divisors;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}


ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    opt();
    int t;
    t = 1;

    while (t--) {
        ll x;
        cin >> x;
        vector<ll> div = getDivisors(x);
        
        ll val_1 = 1, val_2 = x;
        for (int i = 0; i < div.size(); i++) {
            ll a = div[i];
            ll b = x / a;
            if (lcm(a, b) == x && max(a, b) < max(val_1, val_2)) {
                val_1 = a;
                val_2 = b;
            }
        }
        cout << val_1 << " " << val_2 << endl;
    }
    return 0;
}
