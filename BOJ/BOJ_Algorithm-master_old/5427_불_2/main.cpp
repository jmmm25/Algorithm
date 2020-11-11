#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class Node{
public:
    int x, y, dist;
    Node() {};
    Node(int _x, int _y, int _dist):
        x(_x), y(_y), dist(_dist) {};
};

queue<Node> sq;
queue<Node> fq;
int w, h, ret;
char map[1001][1001];
int visit[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void bfs() {
    int escape = 0;
    Node now;
    while (!sq.empty()) {
        int sq_size = sq.size();
        for (int k = 0; k < sq_size; k++) {
            now = sq.front();
            sq.pop();
            if (map[now.x][now.y] == '*') {
                continue;
            }
            // cout << "pop : " << now.x << ", " << now.y << ", " << now.dist << endl;
            visit[now.x][now.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    escape = 1;
                    break;
                }
                if (map[nx][ny] == '.' && !visit[nx][ny]) {
                    // cout << "push : " << nx << ", " << ny << ", " << now.dist + 1 << endl;
                    // map[nx][ny] = '@';
                    sq.push(Node(nx, ny, now.dist + 1));
                }
            }
        }
        if (escape) {
            ret = now.dist + 1;
            break;
        }

        int fq_size = fq.size();
        while (fq_size--) {
            Node fnow = fq.front();
            fq.pop();
            // cout << "fire pop : " << fnow.x << ", " << fnow.y << ", " << fnow.dist << endl;
            for (int i = 0; i < 4; i++) {
                int nx = fnow.x + dx[i];
                int ny = fnow.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (map[nx][ny] == '.') {
                    map[nx][ny] = '*';
                    // cout << "fire push : " << nx << ", " << ny << ", " << "0" << endl;
                    fq.push(Node(nx, ny, 0));
                }
            }
        }
    }

    if (escape)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE" << "\n";
}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    // cout << "sq push : " << i << "," << j << endl;
                    sq.push(Node(i, j, 0));
                }
                if (map[i][j] == '*') {
                    // cout << "fq push : " << i << "," << j << endl;
                    fq.push(Node(i, j, 0));
                }
            }
        }
        ret = -1;
        bfs();

        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) {
                map[i][j] = '\0';
                visit[i][j] = 0;
            }
        }
        while (!sq.empty()) sq.pop();
        while (!fq.empty()) fq.pop();

    }
    return 0;
}
