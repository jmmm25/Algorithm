#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M, ret = -9876543;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};
int map[9][9], mat[9][9];
bool dfs_isVisited[9][9];
bool bfs_isVisited[9][9];
queue<pair<int, int> > q, copy_q;

void bfs() {
    while (!copy_q.empty()) {
        int x = copy_q.front().first;
        int y = copy_q.front().second;
        bfs_isVisited[x][y] = true;
        mat[x][y] = 2;
        copy_q.pop();
        // cout << "*pop : " << x << ", " << y << endl;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // cout << "nx , ny : " << nx << ", " << ny << endl;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || bfs_isVisited[nx][ny]) continue;
            if (mat[nx][ny] == 1 || mat[nx][ny] == 2) continue;

             copy_q.push(make_pair(nx, ny));
             // cout << "**push : " << nx << ", " << ny << endl;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // cout << map[i][j] << " ";
            if (mat[i][j] == 0) {
                cnt++;
            }
        }
        // cout << endl;
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "cnt : " << cnt << endl;
    if (ret < cnt) {
        // cout << "=======update======= " << ret << " -> " << cnt  << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ret = cnt;
    }

    // cout << "result : " << ret << endl;
}

void dfs(int x, int y, int d) {
    if (d == 3) {
        // cout << "d == 3" << endl;
        // cout << "make wall finish!!" << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        memcpy(mat, map, sizeof(map));
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        copy_q = q;
        // cout << "bfs go : " << endl;
        bfs();
        memset(bfs_isVisited, false, sizeof(bfs_isVisited));
        return;
    }

    for (int i = x; i < N; i++) {
        for (int j = y; j < M; j++) {
            if (map[i][j] == 0 && !dfs_isVisited[i][j]) {
                dfs_isVisited[i][j] = true;
                map[i][j] = 1;

                dfs(i, j+1, d+1);
                map[i][j] = 0;
                dfs_isVisited[i][j] = false;
            }
        }
        y = 0;
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                q.push(make_pair(i, j));
                // cout << "push!! 2  ::: " << i <<", " << j << endl;
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dfs(0, 0, 0);
    // memcpy(mat, map, sizeof(map));
    // bfs();
    cout << ret << endl;

    return 0;
}
