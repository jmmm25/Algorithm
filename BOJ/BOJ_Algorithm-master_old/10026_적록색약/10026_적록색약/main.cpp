//
//  main.cpp
//  10026_적록색약
//
//  Created by JEONGMIN on 2018. 1. 21..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int N;
char map[101][101];
bool isVisited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void change_GtoR() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }
}

void dfs(int x, int y, char color) {
    isVisited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[nx][ny] || map[nx][ny] != color) {
            continue;
        }
        dfs(nx, ny, color);
    }
    
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int partial_color_ret = 0, normal_color_ret = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!isVisited[i][j]) {
                dfs(i,j, map[i][j]);
                normal_color_ret++;
            }
        }
    }
    memset(isVisited, false, sizeof(isVisited));
    change_GtoR();
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!isVisited[i][j]) {
                dfs(i,j, map[i][j]);
                partial_color_ret++;
            }
        }
    }
    cout << normal_color_ret << " " << partial_color_ret << "\n";
    return 0;
}
