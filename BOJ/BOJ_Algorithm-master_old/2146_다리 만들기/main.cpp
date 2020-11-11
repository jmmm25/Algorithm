#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

class Info {
public:
    int x, y, cnt;
    Info() {};
    Info (int _x, int _y, int _cnt):
        x(_x), y(_y), cnt(_cnt) {};
};

int N, map[101][101];
bool isVisited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int stat) {
    // cout << stat << endl;
    queue<Info> q;
    Info m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == stat) {
                isVisited[i][j] = true;
                q.push(Info(i, j, 0));
            }
        }
    }

    while (!q.empty()) {
        m = q.front();
        int r, c, cnt;
        r = m.x;    c = m.y;    cnt = m.cnt;
        q.pop();
        // cout << "pop : x, y, cnt : " << r << ", " << c << ", " << cnt << endl;

        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (map[nx][ny] != stat && map[nx][ny] != 0) return cnt;
            if (isVisited[nx][ny] || map[nx][ny] != 0) continue;

            q.push(Info(nx, ny, cnt+1));
            // cout << "push : nx, ny, cnt : " << nx << ", " << ny << ", " << cnt+1 << endl;
            isVisited[nx][ny] = true;
        }
    }
}

void dfs_change(int x, int y, int stat) {
    isVisited[x][y] = true;
    map[x][y] = stat;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (map[nx][ny] == 0 || isVisited[nx][ny]) continue;
        map[nx][ny] = stat;
        dfs_change(nx, ny, stat);
    }
}
int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N;
    int stat = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isVisited[i][j] && map[i][j] != 0) {
                // cout << i << ", " << j << "stat " << stat << endl;
                dfs_change(i, j, stat);
                stat++;
            }
        }
    }
    memset(isVisited, false, sizeof(isVisited));

    int ret = 987654321;
    for (int i = 1; i < stat; i++) {
        ret = min(ret, bfs(i));
        memset(isVisited, false, sizeof(isVisited));
    }
    cout << ret << endl;

    return 0;
}
