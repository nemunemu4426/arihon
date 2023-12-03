// 01ナップサック問題その２
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    int W;
    cin >> W;
    int v_max = *max_element(v.begin(), v.end());
    vector<vector<int>> dp(n + 1, vector<int>(n * v_max + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n * v_max; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j - v[i] >= 0) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
        }
    }
    int res = 0;
    for (int j = 0; j <= n * v_max; ++j) if (dp[n][j] <= W) res = j;
    cout << res << endl;
}