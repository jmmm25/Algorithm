//
//  main.cpp
//  2638
//
//  Created by JEONGMIN on 2017. 9. 29..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
int isVisited[101][101];
int n,m, stat;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 ,0};

void dfs(int r, int c) {
    isVisited[r][c] = 1;

    for (int i=0; i<4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) {   continue;   }
        if (map[nr][nc] == 0 && isVisited[nr][nc]) {
            continue;
        }
        // cout << nr << " " << nc << endl;
        if (map[nr][nc] == 1) {
            isVisited[nr][nc]++;
           // cout << "map" << nr << nc <<"visited" << isVisited[nr][nc] << endl;
            if (isVisited[nr][nc] >= 2) {
                map[nr][nc] = 0;
            }
            continue;
        }
       // cout << "dfs" << nr << " " << nc << endl;
        dfs(nr, nc);
    }


}


int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &stat);
            map[i][j] = stat;
        }
    }
    int cnt = 0;
    int ret = 0;
    while (true){
        memset(isVisited, 0, sizeof(isVisited));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (map[i][j] == 0) {
                    cnt++;
                }
            }
        }
        if (cnt == m*n) {
            break;
        }

        dfs(0,0);
       //  for (int i=0; i<n; i++) {
       //     for (int j=0; j<m; j++) {
       //         cout << map[i][j];
       //     }
       //     cout << endl;
       // }
       // cout << endl;
        cnt = 0;
        ret++;
    }

    cout << ret << "\n";
    return 0;
}
