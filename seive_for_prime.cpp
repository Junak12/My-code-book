#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    opt();
    int n = 60;
    vector<bool> primes = sieve(n);
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
