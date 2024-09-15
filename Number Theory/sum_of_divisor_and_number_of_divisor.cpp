#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1000000;

vector<int> spf(mx + 1);  // Smallest Prime Factor (SPF)

// Sieve to calculate smallest prime factor (SPF) for each number
void sieve_spf() {
    for (int i = 1; i <= mx; i++) spf[i] = i;
    for (int i = 2; i * i <= mx; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mx; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Function to get prime factorization of n using SPF
vector<pair<int, int>> get_prime_factors(int n) {
    vector<pair<int, int>> factors;  // (prime, exponent)
    while (n > 1) {
        int prime = spf[n];
        int count = 0;
        while (n % prime == 0) {
            n /= prime;
            count++;
        }
        factors.push_back({prime, count});
    }
    return factors;
}

// Function to compute Number of Divisors (NOD)
int number_of_divisors(int n) {
    vector<pair<int, int>> factors = get_prime_factors(n);
    int nod = 1;
    for (auto factor : factors) {
        nod *= (factor.second + 1);  // (exponent + 1)
    }
    return nod;
}

// Function to compute Sum of Divisors (SOD)
int sum_of_divisors(int n) {
    vector<pair<int, int>> factors = get_prime_factors(n);
    int sod = 1;
    for (auto factor : factors) {
        int p = factor.first;
        int e = factor.second;
        int term = (pow(p, e + 1) - 1) / (p - 1);  // Sum of geometric series
        sod *= term;
    }
    return sod;
}

int main() {
    opt();
    sieve_spf();

    int n = 36;  

    int nod = number_of_divisors(n);
    int sod = sum_of_divisors(n);

    cout << "Number of Divisors (NOD) of " << n << " = " << nod << endl;
    cout << "Sum of Divisors (SOD) of " << n << " = " << sod << endl;

    return 0;
}
