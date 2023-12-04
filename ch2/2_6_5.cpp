// 区間内の素数の個数
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    vector<bool> is_prime_small(sqrt(b), true);
    vector<bool> is_prime(b - a, true);
    for (int i = 2; (ll)i * i < b; ++i) {
        if (!is_prime_small[i]) continue;
        for (int j = 2 * i; (ll)j * j < b; j += i) {
            is_prime_small[j] = false;
        }
        for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
            is_prime[j - a] = false;
        }
    }
    cout << accumulate(is_prime.begin(), is_prime.end(), 0) << endl;
}