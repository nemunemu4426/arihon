// 区間スケジューリング問題
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> itv(N);
    for (int i = 0; i < N; ++i) cin >> itv[i].second;
    for (int i = 0; i < N; ++i) cin >> itv[i].first;
    sort(itv.begin(), itv.end());
    int res = 0, pv = 0;
    for (int i = 0; i < N; ++i) {
        if (pv < itv[i].second) {
            ++res;
            pv = itv[i].first;
        }
    }
    cout << res << endl;
}