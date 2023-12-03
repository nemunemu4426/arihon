// 迷路の最短路
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int N, M;
    cin >> M >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    int sy, sx, gy, gx;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sy = i, sx = j;
            }
            if (grid[i][j] == 'G') {
                gy = i, gx = j;
            }
        }
    }
    vector<vector<int>> dist(N, vector<int>(M, -1));
    dist[sy][sx] = 0;
    queue<pair<int, int>> que;
    que.push({sx, sy});
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (grid[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push({nx, ny});
        }
    }
    cout << dist[gy][gx] << endl;
}