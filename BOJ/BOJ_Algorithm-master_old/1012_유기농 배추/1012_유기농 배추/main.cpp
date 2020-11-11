//
//  main.cpp
//  1012_유기농 배추
//
//  Created by JEONGMIN on 2018. 1. 16..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

bool map[51][51];
bool isVisited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int T, M, N, K, ret;

void dfs(int x, int y) {
    isVisited[x][y] = true;
    
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || !map[nx][ny] || isVisited[nx][ny]) continue;
        
//        cout << nx << ", " << ny << "일 때 dfs들어감 " << "\n";
        dfs(nx, ny);
        
    }

}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int tc=0; tc<T; tc++) {
        cin >> M >> N >> K;
        int u, v;
        
        for (int i=0; i<K; i++) {
            cin >> u >> v;
            map[v][u] = true;
        }
//        cout << "debug1" << "\n";
        for (int i=0; i<N; i++) {
            for (int j =0; j<M; j++) {
                if (map[i][j] && !isVisited[i][j]) {
//                    cout << i << ", " << j << "일 때 시작 " << "\n";
                    ret++;
                    dfs(i,j);
                }
            }
        }
        cout << ret << "\n";
        ret = 0;
        memset(isVisited, 0, sizeof(isVisited));
        memset(map, 0, sizeof(map));
        
//        for (int i=0; i<N; i++) {
//            for (int j=0; j<M; j++) {
//                cout << map[i][j] << " ";
//            }
//            cout << "\n";
//        }
        
    }
    
    return 0;
}
