// 二部グラフ判定
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> color(n, 0);
    function<bool(int, int)> dfs = [&](int v, int c) -> bool {
        color[v] = c;
        for (auto nv: G[v]) {
            if (color[nv] != 0) {
                if (color[nv] == c) return false;
            } else {
                if (!dfs(nv, -c)) return false;
            }
        }
        return true;
    };
    for (int v = 0; v < n; ++v) {
        if (color[v] != 0) continue;
        if (!dfs(v, 1)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}