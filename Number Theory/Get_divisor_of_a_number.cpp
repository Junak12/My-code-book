#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

vector<int> spf;

void sieve(int maxN) {
    spf.resize(maxN + 1);
    for (int i = 2; i <= maxN; i++) spf[i] = i;

    for (int i = 2; i * i <= maxN; i++) {
        if (spf[i] == i) {  // i is prime
            for (int j = i * i; j <= maxN; j += i) {
                if (spf[j] == j) spf[j] = i;  // Assign i as the smallest prime factor
            }
        }
    }
}

// Function to get prime factorization of n using SPF
map<int, int> getPrimeFactors(int n) {
    map<int, int> primeFactors;
    while (n != 1) {
        primeFactors[spf[n]]++;
        n /= spf[n];
    }
    return primeFactors;
}
vector<int> getDivisors(int n) {
    map<int, int> primeFactors = getPrimeFactors(n); 
    vector<int> divisors = {1}; 

    for (auto &factor : primeFactors) {
        int prime = factor.first, exp = factor.second;
        int size = divisors.size();
        for (int i = 0; i < size; i++) {
            int current = divisors[i];
            for (int j = 1; j <= exp; j++) {
                current *= prime;
                divisors.push_back(current);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    opt();
    int n = 100;  // Input number
    sieve(n);   
    vector<int> divisors = getDivisors(n);
    cout << "Divisors of " << n << " are: ";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
