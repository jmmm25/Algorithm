//
//  main.cpp
//  1937
//
//  Created by JEONGMIN on 2017. 9. 24..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
/*
4
14 9 12 10
1 11 5 4
7 15 2 13
6 3 16 8
*/

#include <iostream>
#include <cstring>
using namespace std;
int n, num;
int cache[501][501];    // 대나무의 크기 1~500
int matrix[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int sol(int i, int j) {
    int &ret = cache[i][j];
    if (ret != -1) {
        return ret;
    }
    ret = 1;
    
    for (int q=0; q<4; q++) {
        int ni = i + dx[q];
        int nj = j + dy[q];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
            continue;
        }
        if (matrix[i][j] < matrix[ni][nj]) {

            ret = max(ret, sol(ni, nj) + 1);
        }
    }
    
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &num);
            matrix[i][j] = num;
        }
    }
    
    memset(cache, -1, sizeof(cache));
    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cache[i][j] = sol(i, j);
            ret = max(ret, cache[i][j]);
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}




/*
 BFS로 구현할 경우 출력은 일치하나, 메모리 문제로 답은 틀림.
 DP로 구현해야할 것.
 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int map[501][501];
int isVisited[501][501];
int dx[4] = {0, 0 , 1, -1};
int dy[4] = {1, -1 ,0 , 0};


struct matrix {
    int x;
    int y;
    int cnt;
};

int bfs(int x, int y) {
    int ret = 0;
    queue<matrix> q;
    memset(isVisited, -1, sizeof(isVisited));
    matrix m;    m.x = x; m.y = y;  m.cnt = 0;
    q.push(m);
    isVisited[m.x][m.y] = 1;
    //            cout << m.x <<" " << m.y << endl;
    
    while (!q.empty()) {
        m = q.front();
        int r = m.x;   int c = m.y; int cnt =m.cnt;
        q.pop();
        for (int i=0; i<4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                continue;
            }
            if (map[nr][nc] < map[r][c]) {
                continue;
            }
                        if (isVisited[nr][nc] == 1) {
                continue;
            }
            isVisited[nr][nc] = 1;
            m.x = nr;   m.y = nc;   ;m.cnt = cnt + 1;
//            cout << nr << " " << nc << endl;
            q.push(m);
        }
    }
    return m.cnt;
}

int main(int argc, const char * argv[]) {
    int ret = 0;
    cin >> n;
    
    memset(map, -1, sizeof(map));
    memset(isVisited, -1, sizeof(isVisited));
    
    for (int i=0; i < n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
            //            cout << map[i][j] << " ";
        }
        //        cout << endl;
    }
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            int result = bfs(x,y);
            if (ret < result) {
                ret = result;
            }
        }
    }
    cout << ret+1 << "\n";
    
    return 0;
    
}
 
*/
