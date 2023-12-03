// Ants (POJ No.1852)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, n;
    cin >> L >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    int minT = 0, maxT = 0;
    for (int i = 0; i < n; ++i) {
        minT = max(minT, min(x[i], L - x[i]));
        maxT = max(maxT, max(x[i], L - x[i]));
    }
    cout << minT << " " << maxT << endl;
}