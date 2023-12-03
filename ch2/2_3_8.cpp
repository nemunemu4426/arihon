// 重複組合せ
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int M;
    cin >> M;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j - 1 - a[i] >= 0) {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i ][j - 1 - a[i]] + M) % M;
            } else {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    cout << dp[n][m] << endl;
}