//
//  main.cpp
//  2468_안전 영역
//
//  Created by JEONGMIN on 2018. 1. 24..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#define MAX_HEIGHT      100
#define MIN_INF     (-987654)
using namespace std;

int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[101][101];
bool isVisited[101][101];

void dfs(int x, int y, int height) {
    isVisited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[nx][ny] || map[nx][ny] <= height) {
            continue;
        }
        
        dfs(nx, ny, height);
    }
    
    
    return;
}


int main(int argc, const char * argv[]) {
    cin >> N;
    int ret = MIN_INF;
    int current_ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int h=0; h<=MAX_HEIGHT; h++) {
        current_ret = 0;
        for (int x=0; x<N; x++) {
            for (int y=0; y<N; y++) {
//                cout << "height, x, y : " << h << ", " << x << ", " << y << endl;
                if (map[x][y] > h && !isVisited[x][y]) {
//                    cout << "dfs " << x << ", " << y << " go" << endl;
                    dfs(x, y, h);
                    current_ret++;
                }
            }
        }
        ret = max(ret, current_ret);
        memset(isVisited, false, sizeof(isVisited));
        if (current_ret == 0) {
            break;
        }
    }
    
    cout << ret << "\n";
    
    
    return 0;
}
