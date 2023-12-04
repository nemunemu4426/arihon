// Carmichael Numbers (Uva No.10006)
#include <iostream>
using namespace std;

int mod_pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    int n;
    cin >> n;
    if (is_prime(n)) cout << "No" << endl;
    else {
        bool judge = true;
        for (int i = 2; i < n; ++i) {
            if (mod_pow(i, n, n) != i) judge = false;
        }
        if (judge) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}