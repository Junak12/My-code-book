#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int phi(int n) {
    int result = n;  
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {  // If i is a factor of n
            // Reduce n as long as i divides n
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

int main() {
    opt();
    int n = 32;
    cout << "Euler's Totient function φ(" << n << ") = " << phi(n) << endl;
    return 0;
}
