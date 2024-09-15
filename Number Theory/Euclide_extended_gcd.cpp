#include <iostream>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int mod_inverse(int a, int mod) {
    int x, y;
    int g = extended_gcd(a, mod, x, y);
    if (g != 1) return -1; // Inverse doesn't exist
    return (x % mod + mod) % mod;
}

int main() {
    int a = 3, mod = 11;
    int inverse = mod_inverse(a, mod);
    if (inverse == -1)
        cout << "Inverse doesn't exist" << endl;
    else
        cout << "Modular inverse of " << a << " mod " << mod << " is " << inverse << endl;
    return 0;
}
