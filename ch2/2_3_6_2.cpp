// 最長増加部分列問題 （セグメント木）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;

struct SegmentTree {
    int N;
    vector<int> dat;
    SegmentTree(int n) { init(n); }
    void init(int n) {
        N = 1;
        while (N < n) N *= 2;
        dat.assign(2 * N, 0);
    }
    void update(int a, int x) {
        a += N;
        dat[a] = x;
        while (a >>= 1) dat[a] = max(dat[2 * a], dat[2 * a + 1]);
    }
    int max_query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = N;
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return dat[k];
        int vl = max_query(a, b, 2 * k, l, (l + r) / 2);
        int vr = max_query(a, b, 2 * k + 1, (l + r) / 2, r);
        return max(vl, vr);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto a_c = a;
    sort(a_c.begin(), a_c.end());
    a_c.erase(unique(a_c.begin(), a_c.end()), a_c.end());
    for_each(a.begin(), a.end(), [&a_c](int &x) {
        x = lower_bound(a_c.begin(), a_c.end(), x) - a_c.begin();
    });
    SegmentTree seg(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int A = seg.max_query(0, a[i]);
        if (seg.max_query(a[i], a[i] + 1) < A + 1) {
            seg.update(a[i], A + 1);
            res = max(res, A + 1);
        }
    }
    cout << res << endl;
}