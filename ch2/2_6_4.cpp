// 素数の個数
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    cout << accumulate(is_prime.begin(), is_prime.end(), 0) << endl;
}