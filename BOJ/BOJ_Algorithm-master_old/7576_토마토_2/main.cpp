#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Info {
public:
    int x, y, cnt;
    Info() {};
    Info(int _x, int _y, int _cnt):
        x(_x), y(_y), cnt(_cnt) {};
};

int N, M;
int map[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isVisited[1001][1001];
queue<Info> q;


int bfs() {
    int x, y, cnt, ret = -1;
    Info m;
    while (!q.empty()) {
        m = q.front();
        x = m.x;    y = m.y;    cnt = m.cnt;
        q.pop();
        for (size_t i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || isVisited[nx][ny] || map[nx][ny] == -1
                || map[nx][ny] == 1) {
                continue;
            }
            q.push(Info(nx, ny, cnt+1));
            isVisited[nx][ny] = true;
            map[nx][ny] = 1;
        }
        ret = max(ret, cnt);
    }

    return ret;
}

void set_init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push(Info(i, j, 0));
                isVisited[i][j] = true;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    set_init();
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 || map[i][j] == -1) {
                cnt++;
            }
        }
    }
    if (cnt == M * N) {
        cout << "0" << "\n";
        return 0;
    }
    int ret = -1;
    ret = bfs();
    if (ret > 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0) {
                    cout << "-1" << "\n";
                    return 0;
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}
