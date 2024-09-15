#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1000000;

vector<int> spf(mx + 1);  
void sieve_spf() {
    for (int i = 2; i <= mx; i++) spf[i] = i;

    for (int i = 2; i * i <= mx; i++) {
        if (spf[i] == i) {  // i is prime
            for (int j = i * i; j <= mx; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
vector<int> get_prime_factors(int n) {
    vector<int> prime_factors;
    while (n != 1) {
        prime_factors.push_back(spf[n]);
        n /= spf[n];
    }
    return prime_factors;
}

int main() {
    opt();
    sieve_spf();
    int n = 200;
    vector<int> factors = get_prime_factors(n);

    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
