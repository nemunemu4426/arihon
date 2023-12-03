// 01ナップサック問題
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
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j - w[i] >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][W] << endl;
}