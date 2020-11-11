#include <iostream>
#include <queue>

using namespace std;
class Node {
public:
    int x, y, dist, broken;
    Node() {};
    Node(int _x, int _y, int _dist, int _broken):
        x(_x), y(_y), dist(_dist), broken(_broken) {};
};

int N, M;
char board[1001][1001];
int visit[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void bfs() {
    queue<Node> q;
    int escape = 0, ret = -1;
    q.push(Node(1, 1, 1, 0));
    visit[1][1][0] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.x == N && now.y == M) {
            escape = 1;
            ret = now.dist;
            break;
        }
        for (size_t i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

            if (board[nx][ny] == '0' && !visit[nx][ny][0] && now.broken == 0) {
                q.push(Node(nx, ny, now.dist + 1, 0));
                visit[nx][ny][0] = 1;
            }

            if (board[nx][ny] == '1' && !visit[nx][ny][1] && now.broken == 0) {
                q.push(Node(nx, ny, now.dist + 1, 1));
                visit[nx][ny][1] = 1;
            }

            if (board[nx][ny] == '0' && !visit[nx][ny][1] && now.broken == 1) {
                q.push(Node(nx, ny, now.dist + 1, 1));
                visit[nx][ny][1] = 1;
            }
        }
    }
    if (escape) {
        cout << ret << "\n";
    }
    else
        cout << "-1" << "\n";
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    bfs();
    return 0;
}
