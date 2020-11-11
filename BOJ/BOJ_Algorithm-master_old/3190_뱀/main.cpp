#include <iostream>
#include <queue>
using namespace std;
class _Node {
public:
    int x, y, dist, dir;
    _Node() {};
    _Node(int _x, int _y, int _dist, int _dir):
        x(_x), y(_y), dist(_dist), dir(_dir) {};
};

typedef _Node node;
int N, K, L;
// E : 0, W : 1, S : 2, N : 3
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[101][101], head[2];
char order[10001];
int change_dir(int dir, char C) {
    if (C == 'D') {
        switch (dir) {
            case 0:
                return 2;
            case 1:
                return 3;
            case 2:
                return 1;
            case 3:
                return 0;
        }
    }
    else if (C == 'L') {
        switch (dir) {
            case 0:
                return 3;
            case 1:
                return 2;
            case 2:
                return 0;
            case 3:
                return 1;
        }
    }
    return -1;
}

void sol() {
    int cur_time = 0, dir = 0;
    map[1][1] = 2;
    queue<pair<int, int> > snake;
    snake.push(make_pair(1, 1));
    head[0] = 1; head[1] = 1;
    // vector<pair<int, int> > head;
    while(true) {
        cur_time++;
        int nx = head[0] + dx[dir];
        int ny = head[1] + dy[dir];
        // cout << "nx ,ny " << nx << ", " << ny << endl;
        if (nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 2) break;
        // head.push_back(make_pair(nx, ny));
        head[0] = nx;
        head[1] = ny;

        // cout << "head " << head[0] << ", " << head[1] << endl;
        if (map[nx][ny] != 1) {
            pair<int, int> tail = snake.front();
            map[tail.first][tail.second] = 0;
            // cout << "tail : " << tail.first << ", " << tail.second << " pop "<<endl;
            snake.pop();
        }

        map[nx][ny] = 2;
        snake.push(make_pair(nx, ny));
        // cout << "snake push " << nx << ", " << ny << endl;


        // cout << "===================" <<  cur_time << "==============" << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if (order[cur_time]) {
            dir = change_dir(dir, order[cur_time]);
        }
    }
    cout << cur_time << "\n";
}

int main(int argc, char const *argv[]) {
	// freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        order[X] = C;
    }
    sol();
    return 0;
}
