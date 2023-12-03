// 部分和問題
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k;
    cin >> k;
    for (int bit = 0; bit < (1 << n); ++bit) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (bit >> j & 1) sum += a[j];
        }
        if (sum == k) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}