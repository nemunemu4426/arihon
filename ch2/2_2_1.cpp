// 硬貨の問題
#include <iostream>
#include <vector>
using namespace std;
const int V[6] = { 1, 5, 10, 50, 100, 500 };

int main() {
    vector<int> C(6);
    for (int i = 0; i < 6; ++i) cin >> C[i];
    int A;
    cin >> A;
    int res = 0;
    for (int i = 5; i >= 0; --i) {
        int num = min(A / V[i], C[i]);
        A -= V[i] * num;
        res += num;
    }
    cout << res << endl;
}