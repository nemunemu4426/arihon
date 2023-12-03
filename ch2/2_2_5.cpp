// Fence Repair (POJ No.3253)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    priority_queue<int, vector<int>, greater<int>> que(L.begin(), L.end());
    int res = 0;
    while (que.size() != 1) {
        int l1 = que.top(); que.pop();
        int l2 = que.top(); que.pop();
        res += l1 + l2;
        que.push(res);
    }
    cout << res << endl;
}