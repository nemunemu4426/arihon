// k-th shortest path
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1 << 30;

int main() {
    int N, R, K;
    cin >> N >> R >> K;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < R; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    vector<vector<int>> dist(K, vector<int>(N, INF));
    dist[0][0] = 0;
    priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[K - 1][v]) continue;
        for (auto [nv, w]: G[v]) {
            int nd = d + w;
            if (dist[0][nv] > nd) {
                swap(dist[0][nv], nd);
                que.push({dist[0][nv], nv});
            }
            for (int k = 1; k < K; ++k) {
                if (dist[k][nv] > nd && dist[k - 1][nv] < nd) {
                    swap(dist[k][nv], nd);
                    que.push({dist[k][nv], nv});
                }
            }
        }
    }
    cout << dist[K - 1][N - 1] << endl;
}