// Saruman's Army (POJ No.3069)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R, N;
    cin >> R >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    int res = 0, i = 0;
    while (i < N) {
        int s = x[i++];
        while (i < N && x[i] <= s + R) ++i;
        int p = x[--i];
        while (i < N && x[i] <= p + R) ++i;
        ++res;
    }
    cout << res << endl;
}