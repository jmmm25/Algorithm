//
//  main.cpp
//  2667_단지 번호 붙이기
//
//  Created by JEONGMIN on 2018. 1. 19..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, component;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[26][26];
bool isVisited[26][26];


int dfs(int x, int y, int cnt) {
    int nx=0, ny=0;
    isVisited[x][y] = true;
    for (int i=0; i<4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[nx][ny] || map[nx][ny] == '0') {
            continue;
        }
        
        cnt = dfs(nx, ny, cnt+1);
    }
    
    return cnt;
}


int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    vector<int> v;
    int ret = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == '1' && !isVisited[i][j]) {
//                cout << i << ", " << j << "dfs start " << endl;
                ret = dfs(i, j, 1);
                component++;
                v.push_back(ret);
            }
        }
    }
    cout << component << "\n";
    
    sort(v.begin(), v.end());
    
    for (int i=0; i<v.size(); i++) {
        cout << v.at(i) << "\n";
    }
    
    return 0;
}
