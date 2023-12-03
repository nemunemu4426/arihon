// 最長増加部分列問題 （二分探索）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
}