// Conscription (POJ No.3723)
#include <iostream>
#include <vector>
#include <algorithm>
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

struct Edge {
    int x, y, d;
};

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<Edge> edges(R);
    for (int i = 0; i < R; ++i) {
        cin >> edges[i].x >> edges[i].y >> edges[i].d;
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return a.d > b.d;
    });
    UnionFind uf(N + M);
    int res = 10000 * (N + M);
    for (auto [a, b, d]: edges) {
        if (uf.unite(a, b + N)) {
            res -= d;
        }
    }
    cout << res << endl;
}