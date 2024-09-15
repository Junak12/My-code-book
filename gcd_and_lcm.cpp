#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 12, b = 20;
    cout << "LCM of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
