// Roadblocks (POJ No.3255)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1 << 30;

int main() {
    int N, R;
    cin >> N >> R;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < R; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    vector<int> dist(N, INF);
    vector<int> dist2(N, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist2[v]) continue;
        for (auto [nv, w]: G[v]) {
            int d2 = d + w;
            if (dist[nv] > d2) {
                swap(dist[nv], d2);
                que.push({dist[nv], nv});
            }
            if (dist2[nv] > d2 && dist[nv] < d2) {
                dist[nv] = d2;
                que.push({dist2[nv], nv});
            }
        }
    }
    cout << dist2[N - 1] << endl;
}