// 線分上の格子点の個数
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    else return gcd(b, a % b);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (x1 == x2 && y1 == y2) cout << 0 << endl;
    else cout << gcd(abs(x1 - x2), abs(y1 - y2)) - 1 << endl;
}