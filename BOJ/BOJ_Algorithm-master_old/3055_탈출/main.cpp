//
//  main.cpp
//  3055_탈출
//
//  Created by JEONGMIN on 2018. 3. 1..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[51][51];
bool isVisited[51][51];
queue<pair<int, int> > wq;
queue<pair<int, int> > sq;

int bfs() {
    int x, y, ret = 0;
    bool escape = false;
    // int tc = 3;
    // water
    while (!sq.empty()) {
    // while(tc--) {
        ret++;
        int wq_sz = wq.size();
        while (wq_sz--) {
            x = wq.front().first;
            y = wq.front().second;
            wq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
                if (map[nx][ny] == 'D' || map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
                // if (map[nx][ny] == '.' || map[nx][ny] == 'S') {
                wq.push(make_pair(nx, ny));
                map[nx][ny] = '*';
                // cout << "wq : " << nx << ", " << ny << endl;
                // }
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int sq_sz = sq.size();
        while (sq_sz--) {
            x = sq.front().first;
            y = sq.front().second;
            sq.pop();
            // cout << "sq : " << x << ", " << y << endl;
            if (map[x][y] == 'D') {
                escape = true;
                // cout << "escape : true" << endl;
                break;
            }
            isVisited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // cout << "next sq : " << nx << ", " << ny << endl;

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || isVisited[nx][ny]) continue;
                // if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                if (map[nx][ny] == '*' || map[nx][ny] == 'X') continue;
                // if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
                isVisited[nx][ny] = true;
                sq.push(make_pair(nx, ny));
                // cout << "push sq : " << nx << ", " << ny << endl;
                // }
            }
        }
        // cout << "ret : " << ret << endl;
        if (escape) {
            break;
        }
    }
    if (escape) {
        // cout << "result : " << ret - 1<< "\n";
        cout << ret-1 << "\n";
        return 0;
    }
    else {
        cout << "KAKTUS" << "\n";
        return 0;
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '*') {
                wq.push(make_pair(i, j));
            }
            else if (map[i][j] == 'S') {
                sq.push(make_pair(i, j));
            }
            else
                continue;
        }
    }
    bfs();

    return 0;
}
