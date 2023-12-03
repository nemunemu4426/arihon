// 分割数
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m >> M;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j - i >= 0) {
                dp[i][j] = dp[i][j - i] + dp[i - 1][j];
                dp[i][j] %= M;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << endl;
}