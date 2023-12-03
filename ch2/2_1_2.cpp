// Lake Counting (POJ No.2386)
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
const int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> grid[i][j];
    }
    vector<vector<bool>> seen(N, vector<bool>(M, false));
    function<void(int, int)> dfs = [&](int x, int y) {
        seen[y][x] = true;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (grid[ny][nx] == '.') continue;
            if (seen[ny][nx]) continue;
            dfs(nx, ny);
        }
    };
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'W' && !seen[i][j]) {
                dfs(j, i);
                ++res;
            }
        }
    }
    cout << res << endl;
}