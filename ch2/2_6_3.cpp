// 素数判定
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool judge = (n != 1);
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            judge = false;
        }
    }
    if (judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}