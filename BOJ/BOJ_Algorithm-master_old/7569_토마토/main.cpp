//
//  main.cpp
//  7569_토마토
//
//  Created by JEONGMIN on 2018. 2. 28..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#define MIN_INF         (-987654321)

using namespace std;

class Info {
public:
    int z, x, y, cnt;
    Info () {};
    Info (int _z, int _x, int _y, int _cnt):
        z(_z), x(_x), y(_y), cnt(_cnt) {};
};

queue<Info> q;
int M, N, H;
int map[101][101][101];
bool isVisited[101][101][101];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int bfs() {
    Info m;
    int z, x, y, cnt;

    while (!q.empty()) {
        m = q.front();
        z = m.z;    x = m.x;    y = m.y;    cnt = m.cnt;
        q.pop();
        // cout << "z, x, y : " << z << " " << x << " " << y << endl;
        isVisited[z][x][y] = true;

        for (size_t i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            // cout << "n:  " << nz << ", " << nx << ", " << ny << endl;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || nz < 0 || nz >= H) continue;
            if (isVisited[nz][nx][ny] || map[nz][nx][ny] == -1 || map[nz][nx][ny] == 1) continue;
            isVisited[nz][nx][ny] = true;
            q.push(Info(nz, nx, ny, cnt+1));
            map[nz][nx][ny] = 1;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[k][i][j];
            }
        }
    }

    int cnt = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[k][i][j] == 1 || map[k][i][j] == -1){
                    cnt++;
                }
            }
        }
    }

    if (cnt == M * N * H) {
        cout << 0 << "\n";
        return 0;
    }

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[k][i][j] == 1) {
                    // cout << k << ", " << i << ", " << j << endl;
                    q.push(Info(k, i, j, 0));
                }
            }
        }
    }

    int ret = MIN_INF;
    ret = bfs();
    // cout << ret << "\n";

    // for (int k = 0; k < H; k++) {
    //     for (int i = 0; i < N; i++) {
    //         for (int j = 0; j < M; j++) {
    //             cout << map[k][i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    if (ret > 0) {
        for (int k = 0; k < H; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if(map[k][i][j] == 0){
                        cout << "-1" << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
