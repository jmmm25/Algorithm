/*
 BFS로 풀었을 시 문제의 답은 제대로 나오나,
 시간 초과로 틀리게 됨.
 DP를 이용해서 풀어야함. --> 욕심쟁이 판다 문제처럼
 그러나 접근 방법이 다름. 고민좀 해봐야할 것
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class Info {
public:
    int x, y, dist, broken;
    Info(){};
    Info(int _x, int _y, int _dist, int _broken):
        x(_x), y(_y), dist(_dist), broken(_broken) {};
};

int N, M, hx, hy, ex, ey;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[1001][1001];
int isVisited[1001][1001][2];

int bfs() {
    queue<Info> q;
    q.push(Info(hx, hy, 0, 0));
    isVisited[hx][hy][0] = 1;
    Info m;
    while (!q.empty()) {
        m = q.front();
        q.pop();
        // cout << "pop (nx, ny, dist, broken) : " << m.x << "," << m.y << "," << m.dist << "," << m.broken << endl;
        if (m.x == ex && m.y == ey) {
            // cout << "result : " << m.dist << endl;
            return m.dist;
        }
        for (int i = 0; i < 4; i++) {
            int nx = m.x + dx[i];
            int ny = m.y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
            if (map[nx][ny] == 0 && isVisited[nx][ny][0] == 0 && m.broken == 0) {
                isVisited[nx][ny][0] = 1;
                // cout << "1. if push(nx, ny, dist, broken) : " << nx << "," << ny << "," << m.dist+1 << "," << m.broken << endl;
                q.push(Info(nx, ny, m.dist + 1, 0));
            }
            if (map[nx][ny] == 1 && isVisited[nx][ny][1] == 0 && m.broken == 0) {
                isVisited[nx][ny][1] = 1;
                // cout << "2. if push(nx, ny, dist, broken) : " << nx << "," << ny << "," << m.dist+1 << "," << "1" << endl;
                q.push(Info(nx, ny, m.dist + 1, 1));
            }
            if (map[nx][ny] == 0 && isVisited[nx][ny][1] == 0 && m.broken == 1) {
                // cout << "3. if push(nx, ny, dist, broken) : " << nx << "," << ny << "," << m.dist+1 << "," << "1" << endl;
                isVisited[nx][ny][1] = 1;
                q.push(Info(nx, ny, m.dist + 1, 1));
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> hx >> hy >> ex >> ey;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    int ret = -1;
    ret = bfs();
    cout << ret << "\n";
    return 0;
}
