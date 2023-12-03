// 個数制限なしナップサック問題
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    int W;
    cin >> W;
    vector<int> dp(W + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = w[i]; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
}