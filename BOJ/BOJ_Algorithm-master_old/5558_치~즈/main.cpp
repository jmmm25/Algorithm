#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
class Node {
public:
    int x, y, dist, level;
    Node() {};
    Node(int _x, int _y, int _dist, int _level):
        x(_x), y(_y), dist(_dist), level(_level) {};
};
int N, M, K, sx, sy;
char board[1000][1000];
int visit[1000][1000][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char cheese[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
queue<Node> q;

int bfs(int idx) {
    int ret = 0, flag = 0;
    Node now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        // cout << "qpop() : " << now.x << ", " << now.y << ", " << now.dist << ", " << now.level << endl;
        if (board[now.x][now.y] == cheese[idx] ) {
            flag = 1;
            // cout << "idx : " << idx << " -- > " << now.dist << endl;
            ret += now.dist;
            while (!q.empty()) q.pop();
            q.push(Node(now.x, now.y, 0, idx + 1));
            sx = now.x;
            sy = now.y;
            return ret;
        }

        for (size_t i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || board[nx][ny] == 'X'
                    || visit[nx][ny][now.level]) continue;
            visit[nx][ny][now.level] = 1;
            q.push(Node(nx, ny, now.dist + 1, now.level));
            // cout << "qpush() : " << now.x << ", " << now.y << ", " << now.dist << ", " << now.level << endl;
        }
    }
    if (!flag) {
        q.push(Node(sx, sy, 0, idx + 1));
        ret += now.dist;
        return ret;
    }

    return 0;
    // cout << ret << "\n";
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                q.push(Node(i, j, 0, 1));
                // cout << "i, j   "  << i << ", " << j << endl;
            }
        }
    }
    int ret = 0;
    for (size_t i = 1; i <= K; i++) {
        // cout << i << " start " << endl;
        Node now = q.front();
        // cout << now.x << ", " << now.y << ", " << now.dist << ", " << now.level << endl;
        ret += bfs(i);
    }
    // cout << "result : " << ret << "\n";
    cout << ret << "\n";
    return 0;
}
