// Layout (POJ No.3169)
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1 << 30;

int main() {
    int N, ML, MD;
    cin >> N >> ML >> MD;
    vector<vector<pair<int, int>>> G(N);
    // d[i] <= d[i + 1]
    for (int i = 0; i < N - 1; ++i) {
        G[i + 1].push_back({i, 0});
    }
    // d[Al] + DL >= d[BL]
    for (int i = 0; i < ML; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        G[a].push_back({b, w});
    }
    // d[AD] + DD <= d[BD]
    for (int i = 0; i < MD; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        G[b].push_back({a, -w});
    }
    bool exist_negative_cycle = false;
    vector<int> dist(N, INF);
    dist[0] = 0;
    for (int iter = 0; iter < N; ++iter) {
        bool update = false;
        for (int v = 0; v < N; ++v) {
            if (dist[v] == INF) continue;
            for (auto [nv, w]: G[v]) {
                if (dist[nv] > dist[v] + w) {
                    dist[nv] = dist[v] + w;
                    update = true;
                }
            }
        }
        if (!update) break;
        if (iter == N - 1 && update) exist_negative_cycle = true;
    }
    if (exist_negative_cycle) cout << "-2" << endl;
    else {
        if (dist[N - 1] < INF) cout << dist[N - 1] << endl;
        else cout << "-1" << endl;
    }
}