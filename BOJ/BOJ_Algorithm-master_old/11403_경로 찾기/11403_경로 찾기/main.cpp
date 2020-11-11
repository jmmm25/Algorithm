//
//  main.cpp
//  11403_경로 찾기
//
//  Created by JEONGMIN on 2018. 1. 22..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[101][101];
bool isVisited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int flag = 0;

void dfs(int ret_x, int ret_y, int start_vertex, int ret) {
    if (start_vertex == ret_y && ret != 0) {
//        cout << "y 와 ret_y가 같다 " << "ret : " << ret << endl;
        flag = 1;
        return;
    }
    for (int i=start_vertex; i<=start_vertex; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] && !isVisited[i][j] && !flag) {
                isVisited[i][j] = true;
//                cout << i << " , " << j << " 일 때 재귀 dfs go " << endl;
                dfs(ret_x, ret_y, j, 1);
            }
        }
    }
    return;
}


int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> N;
    int ret[101][101] = {0,};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
//            cout << i << " , " << j << ": dfs go " << endl;
            dfs(i, j, i, 0);
//            cout << "after dfs flag : " << flag << endl;
            ret[i][j] = flag;
            memset(isVisited, false, sizeof(isVisited));
            flag = 0;
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
