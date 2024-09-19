#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

vector<int> spf;


// Function to preprocess smallest prime factors (SPF) up to 'maxN'
void sieve(int maxN) {
    spf.assign(maxN + 1, 0);
    for (int i = 2; i <= maxN; i++) {
        if (spf[i] == 0) {  // i is prime
            for (int j = i; j <= maxN; j += i) {
                if (spf[j] == 0) spf[j] = i;  // Assign i as the smallest prime factor for j
            }
        }
    }
}

// Function to generate prime factors using SPF
vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors;
    while (n != 1) {
        primeFactors.push_back(spf[n]);
        n /= spf[n];
    }
    return primeFactors;
}

int main() {
    opt();

    int n = 32;
    sieve(100);
    vector<int> primeFactors = getPrimeFactors(n);
    cout << "Prime factors of " << n << " are: ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
