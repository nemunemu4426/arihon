// 双六
#include <iostream>
using namespace std;

int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = extgcd(a, b, x, y);
    if (g == 1) {
        if (x > 0) cout << x << " ";
        else cout << 0 << " ";
        if (y > 0) cout << y << " ";
        else cout << 0 << " ";
        if (x < 0) cout << -x << " ";
        else cout << 0 << " ";
        if (y < 0) cout << -y << endl;
        else cout << 0 << endl;
    }
    else cout << "-1" << endl;
}