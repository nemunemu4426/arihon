// Expedition (POJ No.2431)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, L, P;
    cin >> N >> L >> P;
    vector<int> A(N + 1), B(N + 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    A[N] = L, B[N] = 0;
    N++;
    int res = 0, pv = 0;
    priority_queue<int> que;
    for (int i = 0; i < N; ++i) {
        int d = A[i] - pv;
        while (P - d < 0) {
            if (que.empty()) {
                cout << "-1" << endl;
                return 0;
            }
            P += que.top();
            que.pop();
            ++res;
        }
        P -= d;
        pv = A[i];
        que.push(B[i]);
    }
    cout << res << endl;
}