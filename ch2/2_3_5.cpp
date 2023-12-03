// 個数制限付き部分和問題
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), m(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> m[i];
    int K;
    cin >> K;
    vector<int> dp(K + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}