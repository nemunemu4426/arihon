// 食物連鎖 (POJ No.1182)
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par;
    UnionFind(int n): par(n, -1) {}
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    UnionFind uf(3 * N);
    int res = 0;
    while (K--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x, --y;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            ++res;
            continue;
        }
        if (t == 1) {
            if (uf.same(x, y + N) || uf.same(x, y + 2 * N)) {
                ++res;
            } else {
                uf.unite(x, y);
                uf.unite(x + N, y + N);
                uf.unite(x + 2 * N, y + 2 * N);
            }
        } else {
            if (uf.same(x, y) || uf.same(x, y + 2 * N)) {
                ++res;
            } else {
                uf.unite(x, y + N);
                uf.unite(x + N, y + 2 * N);
                uf.unite(x + 2 * N, y);
            }
        }
    }
    cout << res << endl;
}