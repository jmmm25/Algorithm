//
//  main.cpp
//  3085_사탕게임
//
//  Created by JEONGMIN on 2018. 1. 3..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define MIN_INF (-999999)
using namespace std;


// 우측, 위측
int dx[2] = {0, 1};
int dy[2] = {1, 0};
char map[51][51];
int N;
int ret = MIN_INF;

int bottomMove(int x, int y, int cnt) {
    int nx = 0, ny = 0;
    nx = x + dx[1];
    ny = y + dy[1];
    
    if (nx < 0 || ny >= N || map[nx][ny] != map[x][y])
        return cnt;
    
    if (map[nx][ny] == map[x][y]) {
        cnt = bottomMove(nx, ny, cnt+1);
    }
    
    return cnt;
}

int rightMove(int x, int y, int cnt) {
    int nx = 0, ny = 0;
    nx = x + dx[0];
    ny = y + dy[0];
        
    if (nx < 0 || ny >= N || map[nx][ny] != map[x][y])
        return cnt;
    
    if (map[nx][ny] == map[x][y]) {
        cnt = rightMove(nx, ny, cnt+1);
    }
    
    return cnt;
}


int sol(int x, int y) {
    int cnt = 0;
    int nx = 0, ny = 0;
    for (int i=0; i<2; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || ny >= N) continue;
        
        char temp = map[x][y];
        map[x][y] = map[nx][ny];
        map[nx][ny] = temp;
        
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                ret = max(ret, rightMove(j, k, 1));
                ret = max(ret, bottomMove(j, k, 1));
            }
        }
        
        temp = map[x][y];
        map[x][y] = map[nx][ny];
        map[nx][ny] = temp;
    }
    
    cnt = ret;
    return cnt;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> N;
    int result = MIN_INF;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int temp = sol(i,j);
            result = max(result, temp);
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
