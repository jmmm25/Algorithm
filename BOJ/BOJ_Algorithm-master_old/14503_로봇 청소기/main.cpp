#include <iostream>
#define CLEAN       2
using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[51][51], cnt_map[51][51], ret;


int change_dir(int dir) {
    switch (dir) {
        case 0 : return 3;
        case 1 : return 0;
        case 2 : return 1;
        case 3 : return 2;
    }
    return -1;
}

void sol(int x, int y, int d) {
    int nd = d;
    bool flag = false;

    while (true) {
        if (map[x][y] == 0) {
            map[x][y] = CLEAN;
            ret++;
        }

        for (size_t i = 0; i < 5; i++) {
            if (i == 4) {
                int dir = nd;
                for (size_t i = 0; i < 2; i++) {
                    nd = change_dir(nd);
                }
                int nx = x + dx[nd];
                int ny = y + dy[nd];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (map[nx][ny] != 1) {
                    x = nx;
                    y = ny;
                    nd = dir;
                }
                else
                    flag = true;
                break;

            }
            nd = change_dir(nd);
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (map[nx][ny] == 0) {
                x = nx;
                y = ny;
                break;
            }
        }
        if (flag) {
            break;
        }
    }


    // if (map[x][y] == 0 || !isCleaned[x][y]) {
    //     ret++;
    //     isCleaned[x][y] = true;
    // }
    //
    // for (size_t i = 0; i < 4; i++) {
    //
    // }
    //
    // int nd = change_dir(d);
    // int nx = x + dx[nd];
    // int ny = y + dy[nd];
    //
    // if (nx >= 0 && ny >= 0 && nx < N && ny < M && !isCleaned[nx][ny]) {
    //     dfs(nx, ny, nd);
    // }
    //
    // else if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] || isCleaned[nx][ny]) {
    //     cnt_map[x][y]++;
    //     dfs(x, y, change_dir(nd));
    //     if (cnt_map == 4) {
    //
    //     }
    // }

}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r" , stdin);
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    sol(r, c, d);

    // cout << "=====================" << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ret << "\n";


    return 0;
}
