// 特殊な状態の列挙
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    do {
        for_each(a.begin(), a.end(), [](int x) {
            cout << x << " ";
        });
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));
}