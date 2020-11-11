//
//  main.cpp
//  2583_영역 구하기
//
//  Created by JEONGMIN on 2018. 1. 21..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[101][101];
bool isVisited[101][101];
int M, N, K;
int component;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y, int cnt) {
    isVisited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= M || ny >= N || map[nx][ny] || isVisited[nx][ny]) {
            continue;
        }
        
        cnt = dfs(nx, ny, cnt+1);
    }
    
    return cnt;
}


int main(int argc, const char * argv[]) {
    int x1, x2, y1, y2;
    int ret = 0;
    vector<int> v;
    cin >> M >> N >> K;
    for (int i=0; i<K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = y2-1; x>=y1; x--) {
            for (int y = x2-1; y>=x1; y--) {
                map[x][y] = 1;
            }
        }
    }
    
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
//            cout << map[i][j] << " ";
            if (!isVisited[i][j] && !map[i][j]) {
                ret = dfs(i, j, 1);
                component++;
                v.push_back(ret);
            }
        }
    }
    
    cout << component << "\n";
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        cout << v.at(i) << " ";
    }
    return 0;
}
